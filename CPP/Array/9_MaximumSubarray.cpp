/*
https://leetcode.com/problems/maximum-subarray/
Leetcode : 53. Maximum Subarray - Easy
Given an integer array nums, find the contiguous subarray 
(containing at least one number) which has the largest sum and return its sum.
Follow up: If you have figured out the O(n) solution, 
try coding another solution using the divide and conquer approach, which is more subtle.

Example 1: Input: nums = [-2,1,-3,4,-1,2,1,-5,4] Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2: Input: nums = [1] Output: 1
Example 3: Input: nums = [0] Output: 0
Example 4: Input: nums = [-1] Output: -1
Example 5: Input: nums = [-2147483647] Output: -2147483647

Constraints:
1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int cur_sum = 0;
        for (auto x : nums) {
            cur_sum += x;
            if (sum < cur_sum)
                sum = cur_sum;
            if (cur_sum < 0)
                cur_sum = 0;
        }
        return sum;
    }
};

void printVI(vector<int>& vi) {
    cout << "[";
    for (auto x : vi) {
        cout << x << ", ";
    }
    cout << "]" << endl;
}

void testSolution(vector<int> A) {
    cout << "Input: ";
    printVI(A);

    Solution s;
    cout<<"Result: "<<s.maxSubArray(A);
    cout << "\n--------------------------------\n";
}

int main() {
    testSolution({ -4,5,-6,7,1,-2, 9 });
    testSolution({ 4,-5,6,-7,1,2 });
    testSolution({ -3, 1 });
    testSolution({ -1, 2 });
    testSolution({-5});
    return 0;
}