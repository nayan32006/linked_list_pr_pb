  // एक छोटा सा टेस्ट केस बनाते हैं:
    // 1 <-> 2 <-> 3
    //       | (child)
    //       4
    

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;

        Node* curr = head;
        while (curr != NULL) {
            if (curr->child != NULL) {
                Node* nextNode = curr->next;

                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                Node* temp = curr->next;
                while (temp->next != NULL) {
                    temp = temp->next;
                }

                if (nextNode != NULL) {
                    temp->next = nextNode;
                    nextNode->prev = temp;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->val << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
  
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->next->child = new Node(4);

    cout << "Original List (with child at 2)..." << endl;
    
    Solution sol;
    head = sol.flatten(head);

    cout << "Flattened List: " << endl;
    printList(head);

    return 0;
}

// time cmplexiyty= O(N) 
//जहाँ N कुल नोड्स की संख्या है। हम हर नोड को कम से कम एक बार और अधिकतम दो बार (एक बार आगे बढ़ते हुए और एक बार टेल ढूँढते हुए) विज़िट करते हैं।
// & space =O(H)
// O(H)यहाँ H लिस्ट की गहराई (Levels) है। रिकर्शन की वजह से सिस्टम स्टैक मेमोरी का उपयोग होता है। अगर कोई चाइल्ड नहीं है, तो यह O(1) होगा