#include <iostream>
#include <string>
using namespace std;

struct DictNode {
    string key;
    string value;
    DictNode* next;

    DictNode(string k, string v) {
        key = k;
        value = v;
        next = NULL;
    }
};

class Dictionary {
private:
    static const int SIZE = 100;
    DictNode* table[SIZE];

    int hashFunction(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
            sum += s[i];
        return sum % SIZE;
    }

public:
    Dictionary() {
        for (int i = 0; i < SIZE; i++)
            table[i] = NULL;
    }

    void Add_Record(string key, string value) {
        int index = hashFunction(key);

        DictNode* newNode = new DictNode(key, value);
        newNode->next = table[index];
        table[index] = newNode;

        cout << "Record (" << key << ", " << value << ") added at index " << index << endl;
    }

    void Word_Search(string key) {
        int index = hashFunction(key);
        DictNode* temp = table[index];

        while (temp != NULL) {
            if (temp->key == key) {
                cout << "search key " << key << ": " << temp->value << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Error! Key not found: " << key << endl;
    }

    void Delete_Record(string key) {
        int index = hashFunction(key);
        DictNode* temp = table[index];
        DictNode* prev = NULL;

        while (temp != NULL) {
            if (temp->key == key) {
                if (prev == NULL) table[index] = temp->next;
                else prev->next = temp->next;

                delete temp;
                cout << "key " << key << " deleted successfully !" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Error! Key not found for deletion: " << key << endl;
    }

    void Print_Dictionary() {
        cout << "\n--- Dictionary ---\n";
        for (int i = 0; i < SIZE; i++) {
            if (table[i] != NULL) {
                cout << "index " << i << ": ";
                DictNode* temp = table[i];

                while (temp != NULL) {
                    cout << "(" << temp->key << ", " << temp->value << ") ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }
};

int main() {
    Dictionary dict;

    dict.Add_Record("AB", "FASTNU");
    dict.Add_Record("CD", "CS");
    dict.Add_Record("EF", "ENG");

    dict.Word_Search("AB");

    dict.Delete_Record("EF");

    dict.Print_Dictionary();

    return 0;
}
