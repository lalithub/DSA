/*
Leetcode: 70. Climbing Stairs - Easy
https://leetcode.com/problems/climbing-stairs/

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Example 1: Input: n = 2 Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2: Input: n = 3 Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:
1 <= n <= 45
*/

#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        //n included, we should reach nth stairs
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};


void testSolution(int n, int ways)
{
    Solution s;
    int res = s.climbStairs(n);
    cout << "n: " << n << " result: " << res << ((ways == res) ? " - PASS" : " - FAIL") << endl;
    cout << "----------------------------" << endl;
}

int main() {
    testSolution(7, 21);
    testSolution(2, 2);
    testSolution(3, 3);
    testSolution(20, 10946);
    return 0;
}