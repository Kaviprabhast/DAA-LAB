#include <iostream>
using namespace std;
void golomb(int G[], int n) {
    G[1] = 1; 
    for (int i = 2; i <= n; ++i) {
        G[i] = 1 + G[i - G[G[i - 1]]]; 
    }
}

int main() {
    int n;
    cout << "Enter the number of terms in the Golomb sequence: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of terms should be greater than 0." << endl;
        return 1;
    }

    int G[n + 1]; 
    golomb(G, n); 

    cout << "Golomb sequence up to " << n << " terms:\n";
    for (int i = 1; i <= n; ++i) {
        cout << G[i] << " ";
    }
    cout << endl;

    return 0;
}