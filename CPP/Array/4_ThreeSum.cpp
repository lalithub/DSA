/*
Leetcode: https://leetcode.com/problems/3sum/
15. 3Sum - Medium
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
Input: nums = []
Output: []

Example 3:
Input: nums = [0]
Output: []

AlgoExpert three number sum
*/

#include<iostream>
#include<vector>
#include<algorithm> //sort

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int target = 0;
        int n = nums.size();
        if (n < 3) return res;

        sort(nums.begin(), nums.end());

        int cur = 0;
        while (cur < n - 2) {
            int l = cur + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[cur] + nums[l] + nums[r];
                if (sum == target) {
                    res.push_back({ nums[cur], nums[l], nums[r] });
                    //do not include duplicate
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (r > l && nums[r] == nums[r - 1]) r--;
                    if (l == r) break;
                    l++;
                    r--;
                }
                else if (sum < target) l++;
                else r--;
            }
            while (cur < n - 3 && nums[cur] == nums[cur + 1]) cur++;
            cur++;
        }
        return res;
    }
};

void printVI(vector<int>& vi) {
    cout << "[";
    for (auto x : vi) {
        cout << x << ", ";
    }
    cout << "], ";
}

void printVII(vector<vector<int>>& vii) {
    cout << "[ ";
    for (auto vi : vii) {
        printVI(vi);
    }
    cout << "]" << endl;
}

void testSolution(vector<int> arr) {
    cout << "Input: ";
    printVI(arr);
    Solution s;
    vector<vector<int>> res = s.threeSum(arr);
    cout << "\nResult: ";
    printVII(res);
    cout << "\n--------------------------------\n";
}

int main() {
    testSolution({ -1, 0, 1, 2, -1, -4 }); //Output: [[-1, -1, 2], [-1, 0, 1]]
    testSolution({ 0 }); //Output: []
    testSolution({ 1, 2, 3 }); //Output: []
    return 0;
}
