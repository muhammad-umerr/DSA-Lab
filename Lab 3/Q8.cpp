#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void concatenate(DoublyLinkedList& other) {
        if (!head) {
            head = other.head;
            tail = other.tail;
        } else if (other.head) {
            tail->next = other.head;
            other.head->prev = tail;
            tail = other.tail;
        }
        other.head = NULL;
        other.tail = NULL;
    }
};

int main() {
    DoublyLinkedList L, M;
    L.insertEnd(1);
    L.insertEnd(2);
    M.insertEnd(3);
    M.insertEnd(4);
    L.concatenate(M);
    L.printList();
    return 0;
}
