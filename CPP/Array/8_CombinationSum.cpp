/*
https://leetcode.com/problems/combination-sum/
Leetcode : 39. Combination Sum - Medium
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times.
Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
Example 1: Input: candidates = [2,3,6,7], target = 7 Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2: Input: candidates = [2,3,5], target = 8 Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3: Input: candidates = [2], target = 1 Output: []
Example 4: Input: candidates = [1], target = 1 Output: [[1]]
Example 5: Input: candidates = [1], target = 2 Output: [[1,1]]

Constraints:
1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500
*/

#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    void combination(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>& v, int index, int sum) {
        if (sum == target) {
            res.push_back(v);
            return;
        }
        //Maintain index for unique combination
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] + sum <= target) {
                v.push_back(candidates[i]);
                combination(res, candidates, target, v, i, candidates[i] + sum);
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> v;
        combination(res, candidates, target, v, 0, 0);
        return res;
    }
};

void printVI(vector<int>& vi) {
    cout << "[";
    for (auto x : vi) {
        cout << x << ", ";
    }
    cout << "]" << endl;
}

void printVII(vector<vector<int>>& vii) {
    cout << "[";
    for (auto vi : vii) {
        cout << "[";
        for (auto x : vi) {
            cout << x << ", ";
        }
        cout << "] ";
    }
    cout << "]" << endl;
}

void testSolution(vector<int> A, int n) {
    cout << "Input: ";
    printVI(A);
    cout << "Target: "<<n<<endl;

    Solution s;
    vector<vector<int>> res = s.combinationSum(A, n);
    printVII(res);
    cout << "\n--------------------------------\n";
}

int main() {
    testSolution({ 4,5,6,7,1,2 }, 10);
    testSolution({ 4,5,6,7,1,2 }, 20);
    testSolution({ 3, 1 }, 9);
    testSolution({ 1, 2 }, 6);
    testSolution({}, 7);
    testSolution({ 1 }, 1);
    testSolution({ 1 }, 8);
    return 0;
}