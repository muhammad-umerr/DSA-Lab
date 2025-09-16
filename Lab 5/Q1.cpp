#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }
    void insertEnd(int val) {
        Node* n = new Node{val, NULL};
        if (!head) { head = n; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }
    void displayReverse(Node* node) {
        if (!node) return;
        displayReverse(node->next);
        cout << node->data << " ";
    }
    void showReverse() { displayReverse(head); }
};

int maze[4][4] = {
    {1, 1, 1, 1},
    {0, 0, 0, 1},
    {1, 1, 0, 1},
    {1, 1, 1, 1}
};
int sol[4][4];

bool isSafe(int x, int y) {
    return (x >= 0 && y >= 0 && x < 4 && y < 4 && maze[x][y] == 1);
}

bool solveMazeUtil(int x, int y) {
    if (x == 2 && y == 0)
    { 
        sol[x][y] = 1; 
        return true; 
    }

    if (isSafe(x, y)) 
    {
        sol[x][y] = 1;
        if (solveMazeUtil(x+1,y)) return true;
        if (solveMazeUtil(x,y+1)) return true;
        if (solveMazeUtil(x-1,y)) return true;
        if (solveMazeUtil(x,y-1)) return true;
        sol[x][y] = 0;
        
        return false;
    }

    return false;
}

void printSolution() 
{
    for (int i=0;i<4;i++) 
    {
        for (int j=0;j<4;j++) 
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    LinkedList list;
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    cout << "Reverse Linked List: ";
    list.showReverse();
    cout << endl;

    
    for (int i=0;i<4;i++) for (int j=0;j<4;j++) sol[i][j]=0;
    cout << "Maze Solution:" << endl;
    if (solveMazeUtil(0,0)) printSolution();
    else cout << "No Path Found";
    return 0;
}
