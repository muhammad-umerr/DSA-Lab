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

    int linearSearch(string target, int& steps) {
        Node* temp = head;
        int index = 0;
        steps = 0;
        while (temp) {
            steps++;
            if (temp->data == target) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    int binarySearch(string target, int& steps) {
        int len = 0;
        Node* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        int low = 0, high = len - 1;
        steps = 0;
        while (low <= high) {
            steps++;
            int mid = (low + high) / 2;
            Node* midNode = head;
            for (int i = 0; i < mid; i++) midNode = midNode->next;
            if (midNode->data == target) return mid;
            else if (midNode->data < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};

int main() {
    string arr[10] = {"Ahmed","Ali","Basit","Karim","Rizwan","Sarwar","Tariq","Taufiq","Yasin","Zulfiqar"};
    LinkedList list;
    for (int i = 0; i < 10; i++) list.insertEnd(arr[i]);

    string names[3] = {"Aftab","Rizwan","Tariq"};
    for (int i = 0; i < 3; i++) {
        int stepsLin, stepsBin;
        int idxLin = list.linearSearch(names[i], stepsLin);
        int idxBin = list.binarySearch(names[i], stepsBin);
        cout << names[i] << " -> Linear: " << idxLin << " steps=" << stepsLin
             << " | Binary: " << idxBin << " steps=" << stepsBin << endl;
    }
    return 0;
}
