#include <bits/stdc++.h>
using namespace std;

struct node {
        int data;
        node *prev;
        node *next;
};

void addElementAtLast(node *&root, int data) {
        if ( root == NULL ) {
                root = new node();
                root->data = data;
                root->prev = root->next = root;
                return;
        }
        node *temp = new node(); // Creating new node
        temp->data = data;

        node *p = root;
        node *q = NULL;
        do {
                q = p;
                p = p->next;
        } while ( p != root );

        q->next = p->prev = temp;
        temp->next = p;
        temp->prev = q;
}

void display(node *root) {
        if ( root == NULL ) {
                cout << "Element does not exist in circular linked list" << endl;
                return;
        }
        node *p = root;
        do {
                cout << p->data << " ";
                p = p->next;
        } while ( p != root );
        cout << endl;
}

int main()
{
        node *root = NULL;
        addElementAtLast(root, 10);
        addElementAtLast(root, 20);
        addElementAtLast(root, 30);
        addElementAtLast(root, 40);
        addElementAtLast(root, 50);

        cout << "Circular doubly linked list : ";
        display(root);

        return 0;
}
