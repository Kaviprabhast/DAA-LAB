#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the position of the number: ";
    cin >> n;
    
    int a[n]; 
    a[0] = 1;  
    int i2 = 0, i3 = 0, i5 = 0; 

    int x = 2;
    int y = 3;
    int z = 5;
    int a1 = 1;

    for (int i = 1; i < n; i++) {
        a1 = min(x, min(y, z));
        a[i] = a1;
        if (a1 == x) {
            i2++;
            x = a[i2] * 2;
        }
        if (a1 == y) {
            i3++;
            y = a[i3] * 3;
        }
        if (a1 == z) {
            i5++;
            z = a[i5] * 5;
        }
    }
    cout << "The " << "Ugly number in "<<n<<"th  position:" << a[n-1] << endl;

    return 0;
}
