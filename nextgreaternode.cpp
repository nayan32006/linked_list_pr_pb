// ll problem
// ex ; [2, 7, 4, 3, 5]

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        
        // 1. Convert Linked List to Vector
        while (head) {
            res.push_back(head->val);
            head = head->next;
        }

        stack<int> s;
        
        for (int i = res.size() - 1; i >= 0; i--) {
            int currentVal = res[i];

            while (!s.empty() && s.top() <= currentVal) {
                s.pop();
            }

            if (s.empty()) {
                res[i] = 0;
            } else {
                res[i] = s.top();
            }

            s.push(currentVal);
        }
        return res;
    }
};

int main() {
    ListNode* head = new ListNode(2);
    head->next = new ListNode(7);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    vector<int> result = sol.nextLargerNodes(head);

    cout << "Input:  [2, 7, 4, 3, 5]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    return 0;
}