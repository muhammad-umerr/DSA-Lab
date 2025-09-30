#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* deleteFront(Node* head) {
    if (!head) return NULL;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteLast(Node* head) {
    if (!head || !head->next) {
        delete head;
        return NULL;
    }
    Node* curr = head;
    while (curr->next->next) curr = curr->next;
    delete curr->next;
    curr->next = NULL;
    return head;
}

Node* deleteAt(Node* head, int pos) {
    if (pos == 0) return deleteFront(head);
    Node* curr = head;
    for (int i = 0; curr && i < pos - 1; i++) curr = curr->next;
    if (curr && curr->next) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
    return head;
}

void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

DNode* reverse(DNode* head) {
    if (!head) return NULL;
    DNode* temp = head->prev;
    head->prev = head->next;
    head->next = temp;
    if (!head->prev) return head;
    return reverse(head->prev);
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, NULL}}};
    head = deleteFront(head);
    display(head);
    head = deleteLast(head);
    display(head);
    head = deleteAt(head, 0);
    display(head);

    DNode* h = new DNode{1, NULL, NULL};
    h->next = new DNode{2, h, NULL};
    h->next->next = new DNode{3, h->next, NULL};
    h = reverse(h);
    while (h) {
        cout << h->data << " ";
        h = h->next;
    }
}
