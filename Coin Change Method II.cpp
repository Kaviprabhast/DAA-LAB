#include<iostream>
#include<algorithm> 
using namespace std;

int main() {
    int n;
    cout << "Enter number of coins:" << endl;
    cin >> n;
    int c[] = {1, 2, 5};
    int cost = 15;
    int dp[cost + 1];
    fill(dp, dp + cost + 1, INT_MAX);

    dp[0] = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = c[i]; j <= cost; j++) {
            if (dp[j - c[i]] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - c[i]] + 1);
            }
        }
    }

    if (dp[cost] != INT_MAX) {
        cout << "Minimum number of coins to make change for cost " << cost << " is: " << dp[cost] << endl;
    } else {
        cout << "It's not possible to make change for cost " << cost << " with the given coins." << endl;
    }

    return 0;
}
