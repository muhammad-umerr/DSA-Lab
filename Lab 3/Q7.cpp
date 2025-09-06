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

class CircularLinkedList {
public:
    Node* head;
    CircularLinkedList() {
        head = NULL;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAtPos(int pos, int value) {
        if (pos == 1) {
            insertFront(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; temp->next != head && i < pos - 1; i++) temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteValue(int value) {
        if (!head) return;
        if (head->data == value && head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* curr = head;
        Node* prev = NULL;
        do {
            if (curr->data == value) {
                if (curr == head) {
                    Node* temp = head;
                    while (temp->next != head) temp = temp->next;
                    temp->next = head->next;
                    head = head->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    }

    void printList() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};

int main() {
    CircularLinkedList list;
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertFront(0);
    list.insertAtPos(3, 5);
    list.printList();
    list.deleteValue(2);
    list.printList();
    return 0;
}
