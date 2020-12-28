/*
https://leetcode.com/problems/container-with-most-water/
Leetcode : 11. Container With Most Water - Medium
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
Find two lines, which, together with the x-axis forms a container, 
such that the container contains the most water.
Notice that you may not slant the container.

Example 1: Input: height = [1,8,6,2,5,4,8,3,7] Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.

Example 2: Input: height = [1,1] Output: 1

Example 3: Input: height = [4,3,2,1,4] Output: 16
Example 4: Input: height = [1,2,1] Output: 2

Constraints:
n = height.length
2 <= n <= 3 * 104
0 <= height[i] <= 3 * 104
*/


#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
        //Two pointer approach, 
        //Move the pointer(left or right) whose height is shorter.
        int n = height.size();
        if (n == 0 || n == 1) return 0;
        int left = 0, right = n - 1, maxArea = 0;
        while (left < right) {
            int curArea = min(height[left], height[right]) * (right - left);
            if (curArea > maxArea) maxArea = curArea;
            if (height[left] < height[right]) left++;
            else right--;
        }
        return maxArea;
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
    cout<<" Area: "<<s.maxArea(A);
    cout << "\n--------------------------------\n";
}

int main() {
    testSolution({1, 1}); //1
    testSolution({4, 3, 2, 1, 4}); //16
    testSolution({1, 8, 6, 2, 5, 4, 8, 3, 7}); //49
    testSolution({1, 2, 1}); //2
    testSolution({}); //0
    testSolution({1}); //0
    return 0;
}