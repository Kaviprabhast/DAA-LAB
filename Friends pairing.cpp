#include <iostream>
using namespace std;

int friendsPairing(int n) {
    if (n <= 2) {
        return n; 
    }

    int dp[n + 1];

    dp[1] = 1;  
    dp[2] = 2; 
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }

    return dp[n]; 
}

int main() {
    int n;
    cout << "Enter the number of friends: ";
    cin >> n;

    cout << "Number of ways to pair up friends: " << friendsPairing(n) << endl;

    return 0;
}