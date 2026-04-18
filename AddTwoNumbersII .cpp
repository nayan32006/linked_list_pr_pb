// टेस्ट केस: 7243 (7 -> 2 -> 4 -> 3)

#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        while (l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* head = NULL;

        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            carry = sum / 10;
        
            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

int main() {
  
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    cout << "List 1: "; printList(l1);
    cout << "List 2: "; printList(l2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result Sum: ";
    printList(result);

    return 0;
}

// Complexity Type,     Complexity,            Explanation
// Time  Complexity,    O(N+M),            N और M दोनों लिस्ट्स की लंबाई है। हमें दोनों लिस्ट्स को पूरा पढ़कर स्टैक में डालना पड़ता है और फिर एक-एक करके निकालना पड़ता है।
// Space Complexity,    O(N+M),            हमने दो एक्स्ट्रा स्टैक (Stacks) इस्तेमाल किए हैं जिनमें दोनों लिस्ट्स के सारे एलिमेंट्स स्टोर होते हैं।  