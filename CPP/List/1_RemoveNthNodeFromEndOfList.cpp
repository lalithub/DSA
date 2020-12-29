/*
Leetcode 19. Remove Nth Node From End of List - Medium
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given the head of a linked list, remove the nth node from the end of the list and return its head.
Follow up: Could you do this in one pass?

Example 1: Input: head = [1,2,3,4,5], n = 2 Output: [1,2,3,5]
Example 2: Input: head = [1], n = 1 Output: []
Example 3: Input: head = [1,2], n = 1 Output: [1]

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/

#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Brute force 
        //1. Count the number of total elements in the list ex T then delete T - n element from start
        // above approach takes two loops
        //2. We can use stack for push the all the elements then pops the elements and count the n and delete node.
        
        //Slow and fast pointer approach
        // Fast pointer reach at n + 1 position then slow and fast both pointer walk at same speed.
        // when fast pointer reach at the end of the list then delete the slow pointer node.
        if (head == nullptr) return head;
        if (head->next == nullptr && n == 1)
            return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (n-- > 0) {
            if(fast)
                fast = fast->next;
        }
        if (fast == nullptr) return head->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
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

void testSolution(vector<int> v, int n) {
    ListNode* head = createList(v);
    cout << "n: "<<n<<" Input: ";
    printList(head);

    Solution s;
    head = s.removeNthFromEnd(head, n);
    cout << " Result: ";
    printList(head);
    cout << "\n--------------------------------\n";
}

int main() {
    testSolution({1, 2, 3, 4, 5, 6, 7}, 5);
    testSolution({ 1 }, 5);
    testSolution({ 1 }, 1);
    testSolution({ 1, 2, 3, 4, 5, 6, 7 }, 1);
    testSolution({ 1, 2, 3, 4, 5, 6, 7 }, 7);
    testSolution({ 1, 2, 3, 4, 5, 6, 7 }, 9);
    return 0;
}