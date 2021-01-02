/*
Leetcode 49. Group Anagrams - Meduim
https://leetcode.com/problems/group-anagrams/
Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of 
a different word or phrase, typically using all the original letters exactly once.

Example 1: Input: strs = ["eat","tea","tan","ate","nat","bat"]
           Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2: Input: strs = [""]  Output: [[""]]
Example 3: Input: strs = ["a"] Output: [["a"]]
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(str);
        }
        vector<vector<string>> res;
        for (auto vs : m) {
            res.push_back(vs.second);
        }
        return res;
    }
};

void printVVS(vector<vector<string>>& vvs) {
    for (auto vs : vvs) {
        cout << "[ ";
        for (auto s : vs) {
            cout << s << ", ";
        }
        cout << " ]";
    }
    cout <<" ]"<< endl;
}

void testSolution(vector<string> strs) {
    Solution s;
    vector<vector<string>> res = s.groupAnagrams(strs);
    printVVS(res);
    cout << "--------------------------" << endl;
}

int main()
{    
    testSolution({ "eat","tea","tan","ate","nat","bat" });
    testSolution({ "a","b","c","d","e","eat", "ate" });
    testSolution({ "" });
    return 0;
}