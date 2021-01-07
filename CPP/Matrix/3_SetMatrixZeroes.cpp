/*
LeetCode: 73. Set Matrix Zeroes - Meduim
https://leetcode.com/problems/set-matrix-zeroes/
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.
Follow up:
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Example 1: Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
           Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2: Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
           Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = 0;
        if (m > 0) {
            n = matrix[0].size();
        }
        bool rowFlag = false, colFlag = false;
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0)
                rowFlag = true;
        }
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0)
                colFlag = true;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (rowFlag) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (colFlag) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

void printVII(vector<vector<int>>& vii) {
    cout << "[ ";
    for (auto vi : vii) {
        cout << " [ ";
        for (auto x : vi) {
            cout << x << " ";
        }
        cout << " ]";
    }
    cout <<" ]"<< endl;
}

void testSolution(vector<vector<int>> matrix) {
    cout << "Inout: ";
    printVII(matrix);
    Solution s;
    s.setZeroes(matrix);
    cout << "Output: ";
    printVII(matrix);
    cout << "-------------------------" << endl;
}

int main() {
    testSolution({ {1, 1, 1},{1, 0, 1},{1, 1, 1} });
    testSolution({ {0, 1, 2, 0},{3, 4, 5, 2},{1, 3, 1, 5} });
    return 0;
}