#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int lengthTailRec(Node* node, int count=0) {
    if (!node) return count;
    return lengthTailRec(node->next, count+1);
}

int main() {
    Node* head = new Node{10, NULL};
    head->next = new Node{20, NULL};
    head->next->next = new Node{30, NULL};
    cout << "Length: " << lengthTailRec(head) << endl;
    return 0;
}
