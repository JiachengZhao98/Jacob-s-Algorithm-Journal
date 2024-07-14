#include <iostream>
#include "vector"
#include "unordered_map"
#include "map"
#include "string"
#include "algorithm"
#include "set"
#include "unordered_set"

using namespace std;

vector<int> socialMedia(vector<vector<int>>& friends) {
    unordered_map<int, set<int>> ppl;
    for (auto f : friends) {
        ppl[f[0]].insert(f[1]);
        ppl[f[1]].insert(f[0]);
    }
    vector<int> res;

}

/*
def friend_recommendations(n, friendships):
    from collections import defaultdict

    # Create a graph from the friendships
    graph = defaultdict(set)
    for u, v in friendships:
        graph[u].add(v)
        graph[v].add(u)

    # Function to find recommendations for a given user
    def get_recommendation(user):
        non_friends = set(range(n)) - graph[user]
        max_common = -1
        recommendation = -1

        for non_friend in non_friends:
            # Calculate common friends with the user
            common_friends = len(graph[user].intersection(graph[non_friend]))

            # Update the recommendation based on the number of common friends
            if common_friends > max_common:
                max_common = common_friends
                recommendation = non_friend
            elif common_friends == max_common:
                if non_friend < recommendation:
                    recommendation = non_friend

        return recommendation

    # Collect recommendations for all users
    results = []
    for user in range(n):
        results.append(get_recommendation(user))

    return results
*/

int userBehavior(int n, vector<int>& user) {
    unordered_map<int, int> user_freq, sub;
    for (auto a : user) {
        user_freq[a]++;
    }
    int minf = INT_MAX;
    for (auto a : user_freq) {
        minf = min(minf, a.second);
    }
    int i = 0, j = 0, res = 0;
    while (j < n) {
        sub[user[j]]++;
        if (sub[user[j]] > minf) {
            while (sub[user[j]] > minf && i < n) {
                sub[user[i]]--;
                i++;
            }
        }
        res = max(res, j - i + 1);
        j++;
    }
    return res;
}

int operations(vector<int>& time, int x, int y) {
    sort(time.begin(), time.end());
    int count = 0;
    for (int i = time.size() - 1; i >= 0; i--) {
        if (i == time.size() - 1) {
            count += time[i] / x + 1;
        }
        else {
            time[i] -= count * y;
            if (time[i] <= 0) break;
            count += time[i] / x + 1;
        }
    }
    return count;
}

int servers(int n, vector<int>& cap) {
    unordered_map<int, vector<int>> rec;
    vector<int> prefix_sum(n, 0);

    // Compute the prefix sum and record indices of each capacity
    for (int i = 0; i < n; i++) {
        rec[cap[i]].push_back(i);
        if (i == 0) {
            prefix_sum[i] = cap[i];
        } else {
            prefix_sum[i] = cap[i] + prefix_sum[i - 1];
        }
    }

    int res = 0;
    // Check pairs of indices in the same capacity group
    for (auto& pair : rec) {
        vector<int>& indices = pair.second;
        for (int i = 0; i < indices.size(); i++) {
            for (int j = i + 1; j < indices.size(); j++) {
                // Ensure there's enough space for at least one server between indices
                if (indices[j] - indices[i] >= 2) {
                    // Calculate sum between indices[i]+1 and indices[j]-1
                    int subarray_sum = prefix_sum[indices[j] - 1] - prefix_sum[indices[i]];
                    if (cap[indices[i]] == subarray_sum) {
                        res++;
                    }
                }
            }
        }
    }

    return res;
}

int servers2(int n, vector<int>& cap) {
    if (n < 3) return 0;  // Need at least three elements to form a valid subarray

    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + cap[i];
    }

    int result = 0;
    unordered_map<int, unordered_map<int, int>> sum_count;  // Maps capacity to a map of (cumulative sum, count)

    // Iterate over the capacities
    for (int i = 0; i < n; ++i) {
        int c = cap[i];

        // If there's a previous sum that, when added to 2*c, equals the current prefix sum, we have a valid subarray
        for (const auto& p : sum_count[c]) {
            int needed_sum = prefix_sum[i + 1] - 2 * c;  // This is the sum we need from the start to just before the next 'i'
            if (needed_sum == p.first && i - (p.second - 1) > 1) {
                result += p.second;
            }
        }

        // Update the map for the current index
        sum_count[c][prefix_sum[i + 1]]++;
    }

    return result;
}

/*
def getDistinctGoodnessValues(arr):
    from itertools import combinations

    def bitwise_or(subsequence):
        result = 0
        for num in subsequence:
            result |= num
        return result

    goodness_values = set()
    goodness_values.add(0)


    # Generate all possible strictly increasing subsequences
    for length in range(1, len(arr) + 1):
        for subseq in combinations(arr, length):
            if all(subseq[i] < subseq[i+1] for i in range(len(subseq) - 1)):  # Ensure it's strictly increasing
                goodness_values.add(bitwise_or(subseq))

    # Convert set to a sorted list
    return sorted(goodness_values)
*/


int main() {
    vector<int> time = {9,3,3,3,9};
    int res = servers2(5, time);
    cout<<res<<endl;
    return 0;
}
