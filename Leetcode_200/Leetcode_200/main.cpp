#include "iostream"
#include "stdio.h"
#include "cmath"
#include "string"
#include "string.h"
#include "array"
#include "set"
#include "map"
#include "vector"
#include "algorithm"
#include "stack"
#include "queue"
#include "unordered_set"
#include "unordered_map"
using namespace std;

class Solution {
public:
    void floodfill(vector<vector<char>>& grid, int row, int column) {
        if (column >= grid[0].size() - 1 || row >= grid.size() - 1 || row < 0 || column < 0) {
            return;
        }
        if (grid[row][column] == '0') {
            return;
        }
        grid[row][column] = '0';
        floodfill(grid, row, column + 1);
        floodfill(grid, row + 1, column);
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        int num = 0;
        for (int i = 0; i < row;  i++) {
            for (int j = 0; j < column; j++) {
                if (grid[i][j] == '1') {
                    num++;
                    floodfill(grid, i, j);
                }
            }
        }
        return num;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> grid = {{'1','0','0'},{'0','0','1'}};
    int num = sol.numIslands(grid);
    cout<<num<<endl;
    return 0;
}
