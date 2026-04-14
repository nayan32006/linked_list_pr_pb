#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
int main(){
    node* n;
    node* h;
    node* t;

    n = new node;
    n->data =1;
    n-> next = NULL;
    t = n;
    h = n ;

    n= new node;
    n->data =2;
    n-> next = NULL;
    t-> next = n;
    t=n;

    n= new node;
    n->data =3;
    n-> next = NULL;
    t-> next = n;
    t=n;

    n= new node;
    n->data =4;
    n-> next = NULL;
    t->next = n;
    t=n;

    node* curr=h;
    while(curr != NULL){
        cout<<curr->data <<" -> ";
        curr= curr->next;

    }
    cout<<" NULL :" <<endl;
    return 0;


}
