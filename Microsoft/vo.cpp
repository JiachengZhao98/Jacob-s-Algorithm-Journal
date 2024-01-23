#include "vector"

using namespace std;

int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> zero, stone;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == 0) {
                    zero.push_back({i, j});
                }
                else if (grid[i][j] > 1) {
                    int count = grid[i][j];
                    while (count > 1) {
                        stone.push_back({i, j});
                        count--;
                    }
                }
            }
        }
        int count = INT_MAX;
        do {
            int temp = 0;
            for (int i = 0; i < zero.size(); i++) {
                temp += abs(zero[i].first - stone[i].first) + abs(zero[i].second - stone[i].second);
            }
            count = min(count, temp);
        } while (next_permutation(zero.begin(), zero.end()));
        return count;
    }
