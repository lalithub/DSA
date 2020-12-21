/*
https://leetcode.com/problems/two-sum/
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		int n = nums.size();
		unordered_map<int, int> m;
		for (int i = 0; i < n; i++) {
			int key = target - nums[i];
			if (m.find(key) != m.end()) {
				if (m[key] != i) {
					res.push_back(m[key]);
					res.push_back(i);
					return res;
				}
			}
			m[nums[i]] = i;
		}
		return res;
	}

	// Brute force solution: Two loop n*n
	vector<int> twoSum_1(vector<int>& nums, int target) {
		vector<int> res;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (nums[i] + nums[j] == target) {
					res.push_back(i);
					res.push_back(j);
					return res;
				}
			}
		}
		return res;
	}
};

void printMe(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;

}

void solutionTest(vector<int> v, int t) {
	cout << "Array: ";
	printMe(v);
	cout << "Target: " << t << endl;
	cout << "Result: ";
	Solution s;
	//	vector<int> r = s.twoSum_1(v, t );
	vector<int> r = s.twoSum(v, t);
	printMe(r);
	cout << "\n--------------------------------\n";
}

int main()
{
	solutionTest({ 2, 7, 11, 15 }, 9);
	solutionTest({ 2, 7, 11, 15 }, 8);
	solutionTest({ 3, 2, 4 }, 6);
	solutionTest({ -1, -2, 0, 4, 6, 7, 3, 3 }, 6);
	solutionTest({ -1, -2, 0, 4, 3, 7, 9, 3 }, 6);

	return 0;
}
