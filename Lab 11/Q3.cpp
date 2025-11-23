#include <iostream>
#include <list>
using namespace std;

class Hash {
private:
    static const int size = 10;
    list<int> table[size];

    int hashFunction(int key) {
        return key % size;
    }

public:
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
        cout << "Inserted: " << key << " at index " << index << endl;
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        list<int>::iterator it;

        for (it = table[index].begin(); it != table[index].end(); it++) {
            if (*it == key) {
                table[index].erase(it);
                cout << "Deleted key: " << key << endl;
                return;
            }
        }
        cout << "Key not found!" << endl;
    }

    void search(int key) {
        int index = hashFunction(key);
        for (int x : table[index]) {
            if (x == key) {
                cout << "Key " << key << " found at index " << index << endl;
                return;
            }
        }
        cout << "Key not found!" << endl;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            for (int x : table[i]) cout << x << " -> ";
            cout << "NULL\n";
        }
    }
};

int main() {
    Hash h;

    h.insert(12);
    h.insert(22);
    h.insert(32);

    h.search(22);
    h.deleteKey(12);

    h.display();
}
