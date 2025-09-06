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

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void rotateList(int k) {
        if (!head || k == 0) return;
        Node* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }
        temp->next = head;
        k = k % length;
        for (int i = 0; i < length - k; i++) temp = temp->next;
        head = temp->next;
        temp->next = NULL;
    }
};

int main() {
    LinkedList list;
    int arr[6] = {5, 3, 1, 8, 6, 4};
    for (int i = 0; i < 6; i++) list.insertEnd(arr[i]);
    list.printList();

    int k = 2;
    cout << "After rotation: ";
    list.rotateList(k);
    list.printList();
    return 0;
}
