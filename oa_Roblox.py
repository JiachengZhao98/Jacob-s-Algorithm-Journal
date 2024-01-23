def solution(matrix, words):
    ROWS, COLS = len(matrix), len(matrix[0])

    # Directions for initially moving left to right or top to bottom
    initial_directions = [(0, 1), (1, 0)]
    # All possible directions
    all_directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

    def dfs(x, y, word, index, used_change, direction):
        if index == len(word):
            return True
        if not (0 <= x < ROWS and 0 <= y < COLS) or matrix[x][y] != word[index]:
            return False

        # Mark the current path
        temp, matrix[x][y] = matrix[x][y], "#"

        # Try to continue in the same direction
        nx, ny = x + direction[0], y + direction[1]
        if dfs(nx, ny, word, index + 1, used_change, direction):
            matrix[x][y] = temp
            return True

        # If a direction change hasn't been used, try all other directions
        if not used_change:
            for dx, dy in all_directions:
                if (dx, dy) != direction:  # avoid using the same direction
                    if dfs(x + dx, y + dy, word, index + 1, True, (dx, dy)):
                        matrix[x][y] = temp
                        return True

        # If not found, backtrack and unmark the path
        matrix[x][y] = temp
        return False

    def find_word(word):
        found_count = 0
        for i in range(ROWS):
            for j in range(COLS):
                for direction in initial_directions:
                    if dfs(i, j, word, 0, False, direction):
                        found_count += 1
                        break  # Break to avoid counting the same word more than once
        return found_count

    # Count how many times the words are found
    count = sum(find_word(word) for word in words)
    return count

# Test the function with the updated constraints
updated_matrix = [
    ["a", "b", "a", "c"],
    ["x", "a", "c", "d"],
    ["y", "r", "d", "s"]
]

updated_words = ["ac", "cat", "car", "bar", "acdc", "abacaba"]

# Test the function with the updated matrix and words
print(solution(updated_matrix, updated_words))
