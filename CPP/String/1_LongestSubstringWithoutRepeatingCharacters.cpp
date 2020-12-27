/*
Leet code: Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/
3. Longest Substring Without Repeating Characters - Medium
Given a string s, find the length of the longest substring without repeating characters.
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:
Input: s = ""
Output: 0

Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		if (n == 0 || n == 1) return n;

		unordered_set<char> hash;
		int maxSoFar = -1;
		int i = 0, j = 0;
		while (i < n && j < n) {
			if (hash.find(s[j]) == hash.end()) {
				hash.insert(s[j]);
				j++;
				if (maxSoFar < j - i)
					maxSoFar = j - i;
			}
			else {
				hash.erase(s[i]);
				i++;
			}
		}
		return maxSoFar;
	}
};

int main() {
	Solution s;
	cout << s.lengthOfLongestSubstring("abcabcd") << endl;
	cout << s.lengthOfLongestSubstring("bbbb") << endl;
	cout << s.lengthOfLongestSubstring("pwwkew") << endl;
	cout << s.lengthOfLongestSubstring("") << endl;

	return 0;
}