#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guessGame(int target, int player, int totalPlayers) {
    int guess;
    cout << "Player " << player << " enter guess: ";
    cin >> guess;
    if (guess == target) {
        cout << "Player " << player << " wins!" << endl;
        return;
    }
    if (guess < target) cout << "Too low" << endl;
    else cout << "Too high" << endl;
    guessGame(target, (player % totalPlayers) + 1, totalPlayers);
}

int main() {
    srand(time(0));
    int target = rand() % 100 + 1;
    int players = 2;
    guessGame(target, 1, players);
    return 0;
}
