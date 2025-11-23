#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    string value;
    Node* next;

    Node(string k, string v) {
        key = k;
        value = v;
        next = NULL;
    }
};

class HashTable {
private:
    static const int SIZE = 10; // small size to show collisions
    Node* table[SIZE];

    int hashFunction(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
            sum += s[i];
        return sum % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = NULL;
    }

    void insert(string key, string value) {
        int index = hashFunction(key);

        Node* newNode = new Node(key, value);

        // Insert at head (separate chaining)
        newNode->next = table[index];
        table[index] = newNode;

        cout << "Inserted (" << key << ", " << value << ") at index " << index << endl;
    }

    void printTable() {
        cout << "\n--- Hash Table ---\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << "(" << temp->key << "," << temp->value << ") -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable myhash;

    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");

    myhash.printTable();

    return 0;
}