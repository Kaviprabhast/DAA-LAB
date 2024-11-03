#include <iostream>
using namespace std;
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;  
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int n;
    int W; 
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    int val[n], wt[n]; 
    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> val[i] >> wt[i];
    }

    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;

    return 0;
}