/*
Leetcode: https://leetcode.com/problems/minimum-absolute-difference/
1200. Minimum Absolute Difference - Easy
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr

Example 1:
Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.

Example 2:
Input: arr = [1,3,6,10,15]
Output: [[1,3]]

Example 3:
Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]

Constraints:
2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6
*/
#include<iostream>
#include<vector>
#include<climits> //INT_MAX
#include<algorithm> //sort
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int min = INT_MAX;
        for (int i = 1; i < arr.size(); i++) {
            if (min > abs(arr[i] - arr[i - 1]))
                min = abs(arr[i] - arr[i - 1]);
        }

        for (int i = 1; i < arr.size(); i++) {
            int diff = abs(arr[i] - arr[i - 1]);
            if (diff == min) {
                res.push_back({ arr[i - 1], arr[i] });
            }
        }
        return res;
    }
};

void printVII(vector<vector<int>>& vii) {
    cout << "[ ";
    for (auto vi : vii) {
        cout << "[";
        for (auto x : vi) {
            cout << x <<", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}

void testSolution(vector<int> arr) {
    Solution s;
    vector<vector<int>> res = s.minimumAbsDifference(arr);
    printVII(res);
}

int main() {
    testSolution({4, 3, 2, 1}); //Output: [[1,2],[2,3],[3,4]]
    testSolution({ 3, 8, -10, 23, 19, -4, -14, 27 }); //Output: [[-14, -10], [19, 23], [23, 27]]
    testSolution({ 1, 3, 6, 10, 15 }); //Output: [[1, 3]]
    return 0;
}