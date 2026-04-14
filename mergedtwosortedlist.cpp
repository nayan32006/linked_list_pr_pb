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


// YHIS THE LEET CODE SOLUTION MAIN POINT 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (head1 == NULL || head2 == NULL) {
            return head1 == NULL ? head2 : head1;
        }
        if (head1->val <= head2->val) {
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};


void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    
    ListNode* l1 = new ListNode(1, new ListNode(3, new ListNode(5)));

    
    ListNode* l2 = new ListNode(2, new ListNode(4, new ListNode(6)));

    
    Solution sol;
    
    ListNode* mergedHead = sol.mergeTwoLists(l1, l2);

    cout << "Merged List: " << endl;
    printList(mergedHead);

    return 0;
}

// FeatureAnalysis 
// ReadabilityExtremely high. The code clearly expresses the mathematical definition of merging.
// Time Complexity$O(n + m)$, where $n$ and $m$ are the lengths of the two lists. You visit every node once.
// Space Complexity$O(n + m)$ due to the recursion stack. Each comparison adds a new frame to the stack.