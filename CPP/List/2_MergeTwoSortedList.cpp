/*
Leetcode 21. Merge Two Sorted Lists - Easy
https://leetcode.com/problems/merge-two-sorted-lists/
Merge two sorted linked lists and return it as a new sorted list. 
The new list should be made by splicing together the nodes of the first two lists.

Example 1:
Input: l1 = [1,2,4], l2 = [1,3,4]  Output: [1,1,2,3,4,4]
Example 2: Input: l1 = [], l2 = [] Output: []
Example 3: Input: l1 = [], l2 = [0] Output: [0]

Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.
*/

#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode  tmp;
        ListNode* head = &tmp;
        while (l1 || l2) {
            if (l1 && l2) {
                if (l1->val < l2->val) {
                    head->next = l1;
                    l1 = l1->next;
                    head = head->next;
                }
                else {
                    head->next = l2;
                    l2 = l2->next;
                    head = head->next;
                }
            }
            else {
                if (l1) {
                    head->next = l1;
                    l1 = l1->next;
                    head = head->next;
                }
                if (l2) {
                    head->next = l2;
                    l2 = l2->next;
                    head = head->next;
                }
            }
        }
        return tmp.next;
    }
};

ListNode* createList(vector<int>& v) {
    ListNode* head = nullptr;
    ListNode* cur = nullptr;
    for (auto x : v) {
        ListNode* node = new ListNode(x);
        if (head == nullptr) head = node;
        else cur->next = node;
        cur = node;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}

void testSolution(vector<int> v1, vector<int> v2) {
    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);

    cout << "l1: ";
    printList(l1);
    cout << "l2: ";
    printList(l2);

    Solution s;
    ListNode* res = s.mergeTwoLists(l1, l2);
    cout << " Result: ";
    printList(res);
    cout << "\n--------------------------------\n";
}

int main() {
    testSolution({ 1, 3, 5, 7 }, {2, 4, 6, 8, 9, 10});
    testSolution({ 1, 2, 3, 7, 8, 9, 10 }, { 3, 4, 5, 6, 7, 8, 11 });
    testSolution({ }, { });
    testSolution({ 1, 2, 3, 4, 5, 6, 7 }, {});
    testSolution({ 5 }, { 1 });
    testSolution({ 1, 2, 3, 4, 5, 6, 7 }, { 9 });
    return 0;
}