// ll proble swap node pair 
// ex ; [1,2,3,4]  o/p [2,1,4,3]

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* dummy = new ListNode(0); 
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr && curr->next) {
            
            prev->next = curr->next;         
            curr->next = prev->next->next;   
            prev->next->next = curr;         
            
            prev = curr;
            curr = curr->next;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(vector<int> arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution sol;
    
    ListNode* list = createList({1, 2, 3, 4});
    cout << "Original List: ";
    printList(list);

    ListNode* swapped = sol.swapPairs(list);
    cout << "Swapped List:  ";
    printList(swapped);

    return 0;
}