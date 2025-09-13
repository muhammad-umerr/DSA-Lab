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

    void sortYears() {
        LinkedList y2022, y2023, y2024;
        Node* temp = head;
        while (temp) {
            if (temp->data == 2022) y2022.insertEnd(temp->data);
            else if (temp->data == 2023) y2023.insertEnd(temp->data);
            else if (temp->data == 2024) y2024.insertEnd(temp->data);
            temp = temp->next;
        }
        head = y2022.head;
        temp = head;
        if (temp) while (temp->next) temp = temp->next;
        if (temp) temp->next = y2023.head;
        else head = y2023.head;
        if (!head) head = y2024.head;
        else {
            temp = head;
            while (temp->next) temp = temp->next;
            temp->next = y2024.head;
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
    int arr[6] = {2022, 2023, 2024, 2022, 2023, 2024};
    LinkedList list;
    for (int i = 0; i < 6; i++) list.insertEnd(arr[i]);
    list.sortYears();
    list.printList();
    return 0;
}
