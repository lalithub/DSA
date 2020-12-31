/*
https://leetcode.com/problems/search-in-rotated-sorted-array/
Leetcode : 33. Search in Rotated Sorted Array - Medium
You are given an integer array nums sorted in ascending order, and an integer target.
Suppose that nums is rotated at some pivot unknown to you beforehand 
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
If target is found in the array return its index, otherwise, return -1.

Example 1: Input: nums = [4,5,6,7,0,1,2], target = 0 Output: 4
Example 2: Input: nums = [4,5,6,7,0,1,2], target = 3 Output: -1
Example 3: Input: nums = [1], target = 0 Output: -1
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) { //should check == otherwise we miss one last element [4,5,6,7,0,1,2] 0
            int mid = l + (r - l) / 2;
            if (target == nums[mid])
                return mid;
            //Left side is sorted, should check = also otherwise miss the target  [3,1] 1
            if (nums[l] <= nums[mid]) {
                if (target >= nums[l] && target <= nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else { //Right side is sorted
                if (target >= nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};


void printVI(vector<int>& vi) {
    cout << "[";
    for (auto x : vi) {
        cout << x << ", ";
    }
    cout << "]" << endl;
}

void testSolution(vector<int> A, int n) {
    cout << "Input: ";
    printVI(A);
    cout << "Target: "<<n<<endl;

    Solution s;
    cout << "Found at: " << s.search(A, n);
    cout << "\n--------------------------------\n";
}

int main() {
    testSolution({ 4,5,6,7,0,1,2 }, 0);
    testSolution({ 4,5,6,7,0,1,2 }, 3);
    testSolution({ 3, 1 }, 1);
    testSolution({ 1, 2, 1 }, 1);
    testSolution({}, 7);
    testSolution({ 1 }, 1);
    testSolution({ 1 }, 8);
    return 0;
}