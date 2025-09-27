#include <iostream>
using namespace std;

#define N 4

int board[N][N];
int maxFlags = 0;

bool isSafe(int row, int col) {
    for (int i=0; i<col; i++) if (board[row][i]) return false;
    for (int i=row, j=col; i>=0 && j>=0; i--, j--) if (board[i][j]) return false;
    for (int i=row, j=col; i<N && j>=0; i++, j--) if (board[i][j]) return false;
    return true;
}

bool solveFlags(int col) {
    if (col >= N) return true;
    for (int i=0; i<N; i++) {
        if (isSafe(i,col)) {
            board[i][col] = 1;
            if (solveFlags(col+1)) return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    for (int i=0;i<N;i++) for(int j=0;j<N;j++) board[i][j]=0;
    solveFlags(0);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout<<board[i][j]<<" ";
            if(board[i][j]==1) maxFlags++;
        }
        cout<<endl;
    }
    cout<<"Max Flags: "<<maxFlags<<endl;
    return 0;
}
