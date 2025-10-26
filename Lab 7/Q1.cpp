#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int v) : data(v), next(NULL) {}
};

Node *createList(int arr[], int n)
{
    Node *head = new Node(arr[0]), *cur = head;
    for (int i = 1; i < n; i++)
        cur = cur->next = new Node(arr[i]);
    return head;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int getMax(Node *head)
{
    int mx = 0;
    while (head)
    {
        if (head->data > mx)
            mx = head->data;
        head = head->next;
    }
    return mx;
}

Node *radixSortLinkedList(Node *head)
{
    if (!head || !head->next)
        return head;
    int maxVal = getMax(head);
    int exp = 1;
    while (maxVal / exp > 0)
    {
        Node *buckets[10] = {0};
        Node *tails[10] = {0};
        Node *curr = head;
        while (curr)
        {
            int d = (curr->data / exp) % 10;
            Node *next = curr->next;
            curr->next = NULL;
            if (!buckets[d])
                buckets[d] = tails[d] = curr;
            else
            {
                tails[d]->next = curr;
                tails[d] = curr;
            }
            curr = next;
        }
        head = NULL;
        Node *tail = NULL;
        for (int i = 0; i < 10; i++)
            if (buckets[i])
            {
                if (!head)
                    head = buckets[i], tail = tails[i];
                else
                {
                    tail->next = buckets[i];
                    tail = tails[i];
                }
            }
        exp *= 10;
    }
    return head;
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = createList(arr, n);
    head = radixSortLinkedList(head);
    printList(head);
    return 0;
}
