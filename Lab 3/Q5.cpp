#include <iostream>
#include <string>
#include <algorithm>
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

    bool isPalindrome() {
        string s = "";
        Node* temp = head;
        while (temp) {
            s += temp->data;
            temp = temp->next;
        }
        string r = s;
        reverse(r.begin(), r.end());
        
        return s == r;
    }
};

int main() {
    LinkedList list1;
    list1.insertEnd("1");
    list1.insertEnd("0");
    list1.insertEnd("2");
    list1.insertEnd("0");
    list1.insertEnd("1");
    cout << (list1.isPalindrome() ? "Linked List is a Palindrome" : "Not a Palindrome") << endl;

    LinkedList list2;
    string word = "BORROWORROB";
    for (char c : word) list2.insertEnd(string(1, c));
    cout << (list2.isPalindrome() ? "Linked List is a Palindrome" : "Not a Palindrome") << endl;

    return 0;
}
