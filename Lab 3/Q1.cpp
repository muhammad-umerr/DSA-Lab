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

    void insertFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtPos(int pos, int value) {
        if (pos == 1) {
            insertFront(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
        if (!temp) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteValue(int value) {
        if (!head) return;
        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value) temp = temp->next;
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    int arr[5] = {3, 1, 2, 5, 8};
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;

    LinkedList list;
    for (int i = 0; i < 5; i++) list.insertEnd(arr[i]);
    list.insertEnd(9);
    list.insertAtPos(3, 11);
    list.insertFront(4);
    list.insertFront(1);
    list.deleteValue(1);
    list.deleteValue(2);
    list.deleteValue(5);
    list.printList();
    return 0;
}
