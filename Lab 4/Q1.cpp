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

    void selectionSort() {
        for (Node* i = head; i && i->next; i = i->next) {
            Node* minNode = i;
            for (Node* j = i->next; j; j = j->next) {
                if (j->data < minNode->data) minNode = j;
            }
            if (minNode != i) swap(minNode->data, i->data);
        }
    }

    void printFirstN(int n) {
        Node* temp = head;
        for (int i = 0; i < n && temp; i++) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        list.insertEnd(x);
    }
    list.selectionSort();
    list.printFirstN(4);
    return 0;
}
