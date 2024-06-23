from collections import defaultdict

def process_queries(queries_list):
    user_files = defaultdict(set)
    file_sizes = {}
    file_owners = {}
    user_limits = {}
    user_used_space = {}
    backup_data = {}
    results = []

    user_limits["admin"] = float("inf")
    user_used_space["admin"] = 0

    for query in queries_list:
        action = query[0]

        if action == "ADD_USER":
            user = query[1]
            limit = query[2]
            if user in user_limits:
                results.append("false")
            else:
                results.append("true")
                user_limits[user] = int(limit)
                user_used_space[user] = 0

        elif action == "ADD_FILE":
            user = "admin"
            file = query[1]
            size = int(query[2])
            if file in file_sizes:
                results.append("false")
            else:
                results.append("true")
                user_used_space[user] += size
                file_owners[file] = user
                file_sizes[file] = size
                user_files[user].add(file)

        elif action == "GET_FILE_SIZE":
            file = query[1]
            results.append(str(file_sizes.get(file, "")))

        elif action == "DELETE_FILE":
            file = query[1]
            if file in file_sizes:
                user = file_owners[file]
                size = file_sizes[file]
                user_used_space[user] -= size
                user_files[user].remove(file)
                del file_owners[file]
                del file_sizes[file]
                results.append(str(size))
            else:
                results.append("")

        elif action == "GET_N_LARGEST":
            prefix = query[1]
            n = int(query[2])
            files_sorted_by_size = sorted([(-size, f) for f, size in file_sizes.items() if f.startswith(prefix)])
            top_n_files = files_sorted_by_size[:n]
            formatted_files = [f"{f[1]}({-f[0]})" for f in top_n_files]
            results.append(", ".join(formatted_files) if formatted_files else "")

        elif action == "ADD_FILE_BY":
            user = query[1]
            file = query[2]
            size = int(query[3])
            if user not in user_limits or file in file_sizes:
                results.append("")
                continue
            if user_used_space[user] + size > user_limits[user]:
                results.append("")
                continue
            user_used_space[user] += size
            remaining_space = user_limits[user] - user_used_space[user]
            results.append(str(remaining_space))
            file_owners[file] = user
            user_files[user].add(file)
            file_sizes[file] = size

        elif action == "MERGE_USER":
            user1, user2 = query[1], query[2]
            if user1 not in user_limits or user2 not in user_limits or user1 == user2:
                results.append("")
                continue
            combined_usage = user_used_space[user1] + user_used_space[user2]
            combined_limit = user_limits[user1] + user_limits[user2]
            user_used_space[user1] = combined_usage
            user_limits[user1] = combined_limit
            for f in user_files[user2]:
                file_owners[f] = user1
                user_files[user1].add(f)
            del user_limits[user2], user_files[user2], user_used_space[user2]
            results.append(str(combined_limit - combined_usage))

        elif action == "BACKUP_USER":
            user = query[1]
            if user not in user_limits:
                results.append("")
                continue
            backup_data[user] = ({f: file_sizes[f] for f in user_files[user]}, set(user_files[user]))
            results.append(str(len(user_files[user])))

        elif action == "RESTORE_USER":
            user = query[1]
            if user not in user_limits:
                results.append("")
                continue
            if user not in backup_data:
                for f in user_files[user]:
                    del file_sizes[f], file_owners[f]
                results.append("0")
                continue
            backup_files, backup_user_files = backup_data[user]
            total_size = 0
            restored_files = 0
            for f in user_files[user]:
                del file_owners[f], file_sizes[f]
            for f in backup_files:
                if f not in file_owners or file_owners[f] == user:
                    restored_files += 1
                    total_size += backup_files[f]
                    file_sizes[f] = backup_files[f]
                    file_owners[f] = user
            user_files[user] = backup_user_files
            user_used_space[user] = total_size
            results.append(str(restored_files))

    return results
