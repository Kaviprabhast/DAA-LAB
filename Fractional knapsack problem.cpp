#include <iostream>
using namespace std;
int knapsack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;  
            else if (weights[i - 1] <= w) 
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            else
                dp[i][w] = dp[i - 1][w]; 
        }
    }

    return dp[n][W];
}

int main() {
    int W = 50;
    int weights[] = {10, 20, 30}; 
    int values[] = {60, 100, 120};
    int n = sizeof(weights) / sizeof(weights[0]);

    int maxValue = knapsack(W, weights, values, n);

    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}