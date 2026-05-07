#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Linked List के नोड की परिभाषा
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vals;
        
        // 1. सभी लिस्ट से वैल्यूज़ निकालें
        for (ListNode* list : lists) {
            while (list != nullptr) {
                vals.push_back(list->val);
                list = list->next;
            }
        }

        // 2. वैल्यूज़ को सॉर्ट करें
        sort(vals.begin(), vals.end());

        // 3. सॉर्ट की हुई वैल्यूज़ से नई लिस्ट बनाएं
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        for (int x : vals) {
            curr->next = new ListNode(x);
            curr = curr->next;
        }

        return dummy->next;
    }
};

// हेल्पर फंक्शन: एरे से लिस्ट बनाने के लिए
ListNode* createList(vector<int> arr) {
    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;
    for (int x : arr) {
        curr->next = new ListNode(x);
        curr = curr->next;
    }
    return dummy->next;
}

// हेल्पर फंक्शन: लिस्ट प्रिंट करने के लिए
void printList(ListNode* node) {
    while (node) {
        cout << node->val << (node->next ? " -> " : "");
        node = node->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Example Input: [[1,4,5], [1,3,4], [2,6]]
    vector<ListNode*> lists;
    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));

    ListNode* result = sol.mergeKLists(lists);

    cout << "Merged Sorted List: ";
    printList(result);

    return 0;
}