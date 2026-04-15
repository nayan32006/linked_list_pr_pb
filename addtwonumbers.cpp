#include <iostream>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        ListNode *dummyHead = new ListNode(0);
        ListNode *current = dummyHead;
        int carry = 0;

       
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            
            current->next = new ListNode(sum % 10);
            current = current->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummyHead->next;
    }
};

void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val;
        if (node->next) std::cout << " -> ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    std::cout << "Resulting List: ";
    printList(result);

    return 0;
}