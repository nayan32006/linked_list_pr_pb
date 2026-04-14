// linked list cycle

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  bool hasCycle(ListNode* head)
  {
    if(head == NULL){
        return false;
    }
    ListNode* slow=head;
    ListNode* fast=head->next;

    while(fast!= NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
        }
        if(slow == fast){
            return true;
        }
    }
    return false;
  }
};
int main() {
  
    ListNode* head = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    node4->next = node2;

    Solution sol;
    if (sol.hasCycle(head)) {
        cout << "Cycle detected in the linked list." << endl<<"true" <<endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}