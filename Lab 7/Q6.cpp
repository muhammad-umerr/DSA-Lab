#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[50], R[50];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr1[10] = {5, 9, 1, 7, 3, 8, 2, 10, 6, 4};
    int arr2[10] = {20, 18, 15, 11, 12, 19, 17, 14, 16, 13};
    int arr[20];
    for (int i = 0; i < 10; i++) arr[i] = arr1[i];
    for (int i = 0; i < 10; i++) arr[i + 10] = arr2[i];
    mergeSort(arr, 0, 19);
    for (int i = 0; i < 20; i++) cout << arr[i] << " ";
}
