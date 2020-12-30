/*
23. Merge k Sorted Lists - Hard
https://leetcode.com/problems/merge-k-sorted-lists/
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
Example 1: Input: lists = [[1,4,5],[1,3,4],[2,6]] Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2: Input: lists = [] Output: []
Example 3: Input: lists = [[]] Output: []

Constraints: 
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
*/

#include<iostream>
#include<vector>
#include<queue>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode tmp;
        ListNode* head = &tmp;
        if (lists.empty()) return nullptr;
        //if(lists[0] == nullptr) return nullptr; [[1,4,5],[1,3,4],[2,6]]
        auto cmp = [](ListNode* l, ListNode* r) {
            return l->val > r->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto x : lists) {
            if (x) {
                pq.push(x);
            }
        }
        while (!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();
            head->next = cur;
            head = head->next;
            if (cur->next) {
                pq.push(cur->next);
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

void testSolution(vector<int> v1, vector<int> v2, vector<int> v3) {
    vector<ListNode*> ll;
    ll.push_back(createList(v1));
    ll.push_back(createList(v2));
    ll.push_back(createList(v3));

    Solution s;
    ListNode* res = s.mergeKLists(ll);
    cout << " Result: ";
    printList(res);
    cout << "\n--------------------------------\n";
}

int main() {
    testSolution({ 1, 3, 5, 7 }, { 2, 4, 6, 8, 9, 10 }, {1, 5, 10, 15, 20});
    testSolution({ }, { }, { 1 });
    testSolution({ }, { }, { });
    return 0;
}