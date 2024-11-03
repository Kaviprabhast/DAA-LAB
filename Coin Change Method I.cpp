#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter no. of elements (coins):" << endl;
    cin >> n;
    int c[] = {1, 2, 5};
    int cost = 15;
    int dp[n+1][cost+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= cost; j++) {
            if (j == 0) {
                dp[i][j] = 1; 
            } else if (i == 0) {
                dp[i][j] = 0; 
            } else if (j < c[i-1]) {
                dp[i][j] = dp[i-1][j];  
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j - c[i-1]];
            }
        }
    }

    cout << "Number of ways to make change for cost " << cost << " is: " << dp[n][cost] << endl;

    return 0;
}
