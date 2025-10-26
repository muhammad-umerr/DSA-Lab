#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void swap(Node* a, Node* b) {
    int t = a->data;
    a->data = b->data;
    b->data = t;
}

Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low;
    Node* j = low;
    while (j != high) {
        if (j->data < pivot) {
            swap(i, j);
            i = i->next;
        }
        j = j->next;
    }
    swap(i, high);
    return i;
}

void quickSort(Node* low, Node* high) {
    if (low != high && low && high) {
        Node* p = partition(low, high);
        if (p && low != p) {
            Node* temp = low;
            while (temp->next != p) temp = temp->next;
            quickSort(low, temp);
        }
        if (p && p->next) quickSort(p->next, high);
    }
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    Node* head = new Node{arr[0], nullptr}, *curr = head;
    for (int i = 1; i < 7; i++) curr = curr->next = new Node{arr[i], nullptr};
    Node* tail = head; while (tail->next) tail = tail->next;
    quickSort(head, tail);
    print(head);
}
