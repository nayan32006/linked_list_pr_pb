#include <iostream>
#include <stack>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> stack;
        
        while (cur != nullptr) {
           
            while (!stack.empty() && stack.top()->val < cur->val) {
                stack.pop();
            }
            stack.push(cur);
            cur = cur->next;
        }
        
        ListNode* nxt = nullptr;
        while (!stack.empty()) {
            cur = stack.top();
            stack.pop();
            cur->next = nxt;
            nxt = cur;
        }
        
        return cur;
    }
};


void printList(ListNode* head) {
    if (!head) {
        cout << "Empty List" << endl;
        return;
    }
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(5, new ListNode(2, new ListNode(13, new ListNode(3, new ListNode(8)))));

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* result = sol.removeNodes(head);

    cout << "Modified List: ";
    printList(result);

    return 0;
}

// Efficiency Comparison ; 

// Feature          |    Reverse Approach        |    Stack Approac 
// Time Complexity  |  $O(N)$ (Three passes)    |   $O(N)$ (Two passes)
// Space Complexity |  $O(1)$ (In-place)        |    $O(N)$ (To store the stack)