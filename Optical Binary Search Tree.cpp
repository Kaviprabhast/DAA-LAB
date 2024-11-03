#include <iostream>
#include <iomanip>
#include <climits>  

using namespace std;
double sum(double prob[], int i, int j) {
    double s = 0.0;
    for (int k = i; k <= j; k++) {
        s += prob[k];
    }
    return s;
}
void optimalBST(int keys[], double prob[], int n, double cost[][100], int root[][100]) {
    for (int i = 0; i < n; i++) {
        cost[i][i] = prob[i];  
        root[i][i] = i + 1; 
    }
    for (int length = 2; length <= n; length++) {  
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                double c = ((r > i) ? cost[i][r - 1] : 0) +  
                           ((r < j) ? cost[r + 1][j] : 0) + 
                           sum(prob, i, j);   
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i][j] = r + 1;  
                }
            }
        }
    }
}

void printMatrix(double matrix[][100], int n, const string& name) {
    cout << "\n" << name << " Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                cout << fixed << setprecision(2) << matrix[i][j] << "\t";
            } else {
                cout << "   \t";  
            }
        }
        cout << endl;
    }
}
void printMatrix(int matrix[][100], int n, const string& name) {
    cout << "\n" << name << " Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                cout << matrix[i][j] << "\t";
            } else {
                cout << "   \t";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;
    int keys[n];
    double prob[n];
    cout << "Enter the keys: ";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }
    cout << "Enter the probabilities of the keys (must sum to 1): ";
    for (int i = 0; i < n; i++) {
        cin >> prob[i];
    }
    double cost[100][100] = {0}; 
    int root[100][100] = {0};
    optimalBST(keys, prob, n, cost, root);
    printMatrix(cost, n, "Cost");
    printMatrix(root, n, "Root");

    return 0;
}
