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

    void insertionSort() {
        Node* sorted = NULL;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            if (!sorted || sorted->data >= curr->data) {
                curr->next = sorted;
                sorted = curr;
            } else {
                Node* temp = sorted;
                while (temp->next && temp->next->data < curr->data) temp = temp->next;
                curr->next = temp->next;
                temp->next = curr;
            }
            curr = next;
        }
        head = sorted;
    }

    void moveMaxToMiddle() {
        if (!head) return;
        Node* temp = head;
        Node* maxNode = head;
        while (temp) {
            if (temp->data > maxNode->data) maxNode = temp;
            temp = temp->next;
        }
        if (maxNode == head) {
            head = head->next;
        } else {
            Node* prev = head;
            while (prev->next != maxNode) prev = prev->next;
            prev->next = maxNode->next;
        }
        int len = 0;
        temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        int mid = len / 2;
        temp = head;
        for (int i = 0; i < mid - 1 && temp; i++) temp = temp->next;
        if (!temp) {
            maxNode->next = head;
            head = maxNode;
        } else {
            maxNode->next = temp->next;
            temp->next = maxNode;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int arr[9] = {20, 12, 15, 2, 10, 1, 13, 9, 5};
    LinkedList list;
    for (int i = 0; i < 9; i++) list.insertEnd(arr[i]);
    list.insertionSort();
    list.moveMaxToMiddle();
    list.printList();
    return 0;
}
