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

    int binarySearch(int target) {
        int len = 0;
        Node* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        int low = 0, high = len - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            Node* midNode = head;
            for (int i = 0; i < mid; i++) midNode = midNode->next;
            if (midNode->data == target) return mid;
            else if (midNode->data < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
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
    int arr[10] = {12, 45, 23, 67, 34, 89, 56, 90, 11, 78};
    LinkedList list;
    for (int i = 0; i < 10; i++) list.insertEnd(arr[i]);
    list.insertionSort();
    list.printList();
    int roll = 45; 
    int pos = list.binarySearch(roll);
    if (pos != -1) cout << "Found at index " << pos << endl;
    else cout << "Not found" << endl;
    return 0;
}
