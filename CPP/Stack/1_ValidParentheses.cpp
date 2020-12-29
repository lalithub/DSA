/*
https://leetcode.com/problems/valid-parentheses/
LeetCode: 20. Valid Parentheses- Easy
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Example 1: Input: s = "()"     Output: true
Example 2: Input: s = "()[]{}" Output: true
Example 3: Input: s = "(]"     Output: false
Example 4: Input: s = "([)]"   Output: false
Example 5: Input: s = "{[]}"   Output: true

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isMatch(char left, char right) {
        if ((left == '(' && right == ')')
            || (left == '{' && right == '}')
            || (left == '[' && right == ']')) {
            return true;
        }
        return false;
    }

    bool isValid(string s) {
        stack<char> st;
        for (auto c: s) {
            if (st.empty()) {
                st.push(c);
            }
            else if (isMatch(st.top(), c)) {
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        return st.empty();
    }
};


int main() {
    Solution s;
    cout << "Input: () Res: " << s.isValid("()") << endl;
    cout << "Input: ()[]{} Res: " << s.isValid("()[]{}") << endl;
    cout << "Input: (] Res: " << s.isValid("(]") << endl;
    cout << "Input: ([)] Res: " << s.isValid("([)]") << endl;
    cout << "Input: {[]} Res: " << s.isValid("{[]}") << endl;

    return 0;
}