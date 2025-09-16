#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool searchNonTailRec(Node* node, int key) {
    if (!node) return false;
    if (node->data == key) return true;
    return searchNonTailRec(node->next, key);
}

int main() {
    Node* head = new Node{10, NULL};
    head->next = new Node{20, NULL};
    head->next->next = new Node{30, NULL};
    cout << "Search 20: " << (searchNonTailRec(head,20) ? "Found" : "Not Found") << endl;
    cout << "Search 40: " << (searchNonTailRec(head,40) ? "Found" : "Not Found") << endl;
    return 0;
}
