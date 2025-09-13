#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string value) {
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

    void insertEnd(string value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void bubbleSort() {
        if (!head) return;
        bool swapped;
        do {
            swapped = false;
            Node* temp = head;
            while (temp->next) {
                if (temp->data > temp->next->data) {
                    swap(temp->data, temp->next->data);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
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
    string arr[5] = {"banana","apple","cherry","date","grape"};
    LinkedList list;
    for (int i = 0; i < 5; i++) list.insertEnd(arr[i]);
    list.bubbleSort();
    list.printList();
    return 0;
}
