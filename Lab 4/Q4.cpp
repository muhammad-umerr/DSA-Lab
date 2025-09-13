#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    bool hasDuplicates() {
        for (Node* i = head; i; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                if (i->data == j->data) return true;
            }
        }
        return false;
    }
};

int main() {
    LinkedList list;
    int arr[7] = {1,2,3,4,5,2,6};
    for (int i = 0; i < 7; i++) list.insertEnd(arr[i]);
    cout << (list.hasDuplicates() ? "true" : "false") << endl;
    return 0;
}
