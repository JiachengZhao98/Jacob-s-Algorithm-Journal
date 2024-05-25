#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

// Function to check if s1 is a suffix of s2 or vice versa
bool isSuffix(const string& s1, const string& s2) {
    if (s1.length() > s2.length()) {
        return s1.compare(s1.length() - s2.length(), s2.length(), s2) == 0;
    } else {
        return s2.compare(s2.length() - s1.length(), s1.length(), s1) == 0;
    }
}

// Function to count pairs where one string is a suffix of the other
int countSuffixPairs(const vector<string>& words) {
    int count = 0;
    for (size_t i = 0; i < words.size(); ++i) {
        for (size_t j = i + 1; j < words.size(); ++j) {
            if (isSuffix(words[i], words[j])) {
                ++count;
            }
        }
    }
    return count;
}

// dfs traverse the matrix
void dfs_up(int numRow, int numCol, int curRow, int curCol, unordered_set<int>& laser_row,
    unordered_set<int>& laser_col, vector<vector<int>>& visited, int& count) {
        if (curRow >= numRow || curCol >= numCol || curRow < 0 || curCol < 0 || visited[curRow][curCol]) return;
        if (laser_row.find(curRow) != laser_row.end() || laser_col.find(curCol) != laser_col.end()) return;
        count++;
        visited[curRow][curCol] = 1;
        dfs_up(numRow, numCol, curRow - 1, curCol, laser_row, laser_col, visited, count);
}

void dfs_down(int numRow, int numCol, int curRow, int curCol, unordered_set<int>& laser_row,
    unordered_set<int>& laser_col, vector<vector<int>>& visited, int& count) {
        if (curRow >= numRow || curCol >= numCol || curRow < 0 || curCol < 0 || visited[curRow][curCol]) return;
        if (laser_row.find(curRow) != laser_row.end() || laser_col.find(curCol) != laser_col.end()) return;
        count++;
        visited[curRow][curCol] = 1;
        dfs_down(numRow, numCol, curRow + 1, curCol, laser_row, laser_col, visited, count);
}
void dfs_left(int numRow, int numCol, int curRow, int curCol, unordered_set<int>& laser_row,
    unordered_set<int>& laser_col, vector<vector<int>>& visited, int& count) {
        if (curRow >= numRow || curCol >= numCol || curRow < 0 || curCol < 0 || visited[curRow][curCol]) return;
        if (laser_row.find(curRow) != laser_row.end() || laser_col.find(curCol) != laser_col.end()) return;
        count++;
        visited[curRow][curCol] = 1;
        dfs_left(numRow, numCol, curRow, curCol - 1, laser_row, laser_col, visited, count);
    }

void dfs_right(int numRow, int numCol, int curRow, int curCol, unordered_set<int>& laser_row,
    unordered_set<int>& laser_col, vector<vector<int>>& visited, int& count) {
        if (curRow >= numRow || curCol >= numCol || curRow < 0 || curCol < 0 || visited[curRow][curCol]) return;
        if (laser_row.find(curRow) != laser_row.end() || laser_col.find(curCol) != laser_col.end()) return;
        count++;
        visited[curRow][curCol] = 1;
        dfs_right(numRow, numCol, curRow, curCol + 1, laser_row, laser_col, visited, count);
}

int solution(int numRow, int numCol, int curRow, int curCol, vector<vector<int>>& laserCoordinates) {
    vector<vector<int>> visited(numRow, vector<int>(numCol, 0));
    vector<int> count(4, 0);
    unordered_set<int> laser_row;
    unordered_set<int> laser_col;
    int res = 0;
    for (auto a : laserCoordinates) {
        laser_row.insert(a[0] - 1);
        laser_col.insert(a[1] - 1);
    }
    dfs_down(numRow, numCol, curRow, curCol, laser_row, laser_col, visited, count[0]);
    dfs_up(numRow, numCol, curRow, curCol, laser_row, laser_col, visited, count[1]);
    dfs_left(numRow, numCol, curRow, curCol, laser_row, laser_col, visited, count[2]);
    dfs_right(numRow, numCol, curRow, curCol, laser_row, laser_col, visited, count[3]);

    for (auto a : count) {
        res = max(a, res);
    }

    return res - 1;
}

int main() {
    // vector<string> words1 = {"back", "backdoor", "gammon", "backgammon", "comeback", "come", "door"};
    // vector<string> words2 = {"cba", "a", "a", "b", "ba", "ca"};

    // cout << "Count for first set: " << countSuffixPairs(words1) << endl;  // Expected output: 3
    // cout << "Count for second set: " << countSuffixPairs(words2) << endl; // Expected output: 8

    vector<vector<int>> laser = {{1, 6}, {2, 8}};
    int res = solution(8, 8, 4, 2, laser);
    cout<<res<<endl;
    return 0;
}
