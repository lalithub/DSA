/*
Leetcode 5. Longest Palindromic Substring - Meduim
https://leetcode.com/problems/longest-palindromic-substring/
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Example 3:
Input: s = "a"
Output: "a"

Example 4:
Input: s = "ac"
Output: "a"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    //Expand Around Center
    string longestPalindrome(string s) {
        if (s.size() < 1) return "";
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > (end - start + 1)) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
                //cout<<"len:"<<len<<" s: "<<start<<" e:"<<end<<endl;
            }
        }
        return s.substr(start, (end - start + 1));
    }

    int expandAroundCenter(string s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }
};

int main()
{
    Solution s;
    cout << "Input : babad -> output: " << s.longestPalindrome("babad")<<endl; //
    cout << "Input : cbbd -> output: " << s.longestPalindrome("cbbd") << endl;
    cout << "Input : a -> output: " << s.longestPalindrome("a") << endl;
    cout << "Input : ac -> output: " << s.longestPalindrome("ac") << endl;
    cout << "Input : abacdgfdcaba -> output: " << s.longestPalindrome("abacdgfdcaba") << endl;
    cout << "Input : caba -> output: " << s.longestPalindrome("caba") << endl;
    
	return 0;
}