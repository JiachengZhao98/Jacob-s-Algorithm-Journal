#include "vector"
using namespace std;

class Solution {
public:
    int searchRow(vector<vector<int>>& matrix, int target, int mid, int matrixSize) {
        if (target > matrix[mid][matrix[0].size() - 1] && target < matrix[mid + 1][0]) return -1;
        if (target >= matrix[mid][0]) {
            if (target > matrix[mid][matrix[0].size() - 1]) {
                return searchRow(matrix, target, (mid + 1 + matrixSize) / 2, matrixSize);
            }
            else return mid;
        }
        else {
            matrixSize = mid - 1;
            return searchRow(matrix, target, (mid - 1) / 2, matrixSize);
        }
    }
    int searchColumn(vector<vector<int>>& matrix, int target, int row, int columnSize, int mid) {
        if (mid == columnSize && matrix[row][mid] != target) return -1;
        if (target > matrix[row][mid]) {
            return searchColumn(matrix, target, row, columnSize, (mid + 1 + columnSize) / 2);
        }
        else if (target == matrix[row][mid]) return mid;
        else {
            columnSize = mid - 1;
            return searchColumn(matrix, target, row, columnSize, columnSize / 2);
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target > matrix[matrix.size() - 1][matrix[0].size() - 1] || target < matrix[0][0]) {
            return false; 
        }
        int row = searchRow(matrix, target, (matrix.size() - 1) / 2, matrix.size() - 1);
        if (row == -1) return false;
        int col = searchColumn(matrix, target, row, matrix[0].size() - 1, (matrix[0].size() - 1) / 2);
        return col != -1;
    }
};