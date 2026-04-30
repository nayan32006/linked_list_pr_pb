#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        // We start from the node after the initial 0
        head = head->next;
        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr) {
            if (curr->val != 0) {
                // Accumulate the sum into the 'prev' node
                prev->val += curr->val;
                curr = curr->next;
            } else {
                // We hit a 0. Link prev to the node after this 0.
                prev->next = curr->next;
                prev = prev->next;
                
                if (curr->next) {
                    curr = curr->next->next;
                } else {
                    curr = nullptr;
                }
            }
        }
        return head;
    }
};

// --- Helper Functions for VS Code Testing ---

// Creates a linked list from a vector
ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

// Prints the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Example 1: [0, 3, 1, 0, 4, 5, 2, 0]
    // Expected Output: [4, 11]
    vector<int> input1 = {0, 3, 1, 0, 4, 5, 2, 0};
    ListNode* list1 = createList(input1);

    cout << "Input:  0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0" << endl;
    ListNode* result1 = sol.mergeNodes(list1);
    cout << "Output: ";
    printList(result1);

    return 0;
}