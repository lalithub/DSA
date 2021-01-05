/*
LeetCode: 54. Spiral Matrix - Medium
https://leetcode.com/problems/spiral-matrix/
 Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1: Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
           Output: [1,2,3,6,9,8,7,4,5]
Example 2: Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
            Output: [1,2,3,4,8,12,11,10,9,5,6,7]
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> A;
        int rowStart = 0, rowEnd = 0, colStart = 0, colEnd = 0;
        int n = matrix.size();
        if (n > 0) {
            rowEnd = n - 1;
            colEnd = matrix[0].size() - 1;
        }
        else {
            return A;
        }

        while (rowStart <= rowEnd && colStart <= colEnd) {
            for (int i = colStart; i <= colEnd; i++) A.push_back(matrix[rowStart][i]);
            rowStart++;
            for (int i = rowStart; i <= rowEnd; i++) A.push_back(matrix[i][colEnd]);
            colEnd--;
            if (rowStart <= rowEnd) //if there col is exist
                for (int i = colEnd; i >= colStart; i--) A.push_back(matrix[rowEnd][i]);
            rowEnd--;
            if (colStart <= colEnd) //if there row is exist
                for (int i = rowEnd; i >= rowStart; i--) A.push_back(matrix[i][colStart]);
            colStart++;
        }

        return A;
    }
};

void printVII(vector<vector<int>>& vii) {
    cout << "[ ";
    for (auto vi : vii) {
        cout <<"[ ";

        for (auto x : vi) {
            cout << x << ", ";
        }
        cout << " ], ";
    }
    cout << " ]" << endl;
}

void printVI(vector<int>& vi) {
    cout << "[ ";
    for (auto x : vi) {
        cout << x << ", ";
    }
    cout << " ]" << endl;
}

void testSolution(vector<vector<int>> matrix) {
    cout << "Input: ";
    printVII(matrix);
    Solution s;
    vector<int> res = s.spiralOrder(matrix);
    cout << "Output: ";
    printVI(res);
    cout << "--------------------------" << endl;
}

int main() {
    testSolution({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
    testSolution({ {1, 2, 3, 4}, {10, 11, 12, 5}, {9, 8, 7, 6} });
    return 0;
}