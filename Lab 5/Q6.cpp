#include <iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim, int index=0) {
    if (index == sizes[dim]) return 0;
    if (dim == 0) return arr[0][index] + recursiveArraySum(arr, sizes, dim, index+1);
    return recursiveArraySum((int**)arr[index], sizes, dim-1) + recursiveArraySum(arr, sizes, dim, index+1);
}

int main() {
    int row1[] = {1,2};
    int row2[] = {3,4,5};
    int* arr[] = {row1, row2};
    int sizes[] = {2,2};
    cout << recursiveArraySum(arr, sizes, 1) << endl;
    return 0;
}