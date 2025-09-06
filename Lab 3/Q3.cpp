#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node(string value) {
        name = value;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void insertSorted(string value) {
        Node* newNode = new Node(value);
        if (!head || head->name > value) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->name < value) temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteValue(string value) {
        if (!head) return;
        if (head->name == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->name != value) temp = temp->next;
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    bool search(string value) {
        Node* temp = head;
        while (temp) {
            if (temp->name == value) return true;
            temp = temp->next;
        }
        return false;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    int choice;
    string name;
    while (true) {
        cout << "\n1. Reserve Ticket\n2. Cancel Reservation\n3. Check Reservation\n4. Display Passengers\n5. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter name: ";
            cin >> name;
            list.insertSorted(name);
        } else if (choice == 2) {
            cout << "Enter name: ";
            cin >> name;
            list.deleteValue(name);
        } else if (choice == 3) {
            cout << "Enter name: ";
            cin >> name;
            cout << (list.search(name) ? "Reserved\n" : "Not Reserved\n");
        } else if (choice == 4) {
            list.printList();
        } else break;
    }
    return 0;
}
