#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  
using namespace std;

int main() {
    int mat[3][3] = {
        {9, 2, 7},
        {6, 4, 3},
        {5, 8, 1}
    };

    vector <int> job = {0, 1, 2};
    int  minCost = INT_MAX;
    do {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += mat[i][job[i]]; 
        }
        if (sum < minCost) {
            minCost = sum; 
        }
    } while (next_permutation(job.begin(), job.end()));
    cout << "The minimum cost of assignment is: " << minCost << endl;

    return 0;
}
