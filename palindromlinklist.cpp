// ll problem 
// ex : [1, 2, 2, 1]
//  [1,2,3,4]

#include <iostream>
#include <stack>
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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* p = head;

        
        while (p != NULL) {
            s.push(p->val);
            p = p->next;
        }

        while (head != NULL) {
            if (s.top() != head->val) {
                return false;
            }
            s.pop();
            head = head->next;
        }
        return true;
    }
};

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

    ListNode* list1 = createList({1, 2, 2, 1});
    cout << "Test 1 [1,2,2,1]: " << (sol.isPalindrome(list1) ? "True" : "False") << endl;

    
    ListNode* list2 = createList({1, 2, 3, 4});
    cout << "Test 2 [1,2,3,4]: " << (sol.isPalindrome(list2) ? "True" : "False") << endl;

    return 0;
}