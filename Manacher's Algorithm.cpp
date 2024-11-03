#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "bacca";
    int n = a.length();
    int l = 2 * n + 1;
    char s[l + 1];
    int* lps = new int[l]();  
    for (int i = 0, j = 0; i < l; i++) {
        if (i % 2 == 0) {
            s[i] = '#';
        } else {
            s[i] = a[j++];
        }
    }
    s[l] = '\0'; 

    int center = 0, right = 0;
    for (int i = 0; i < l; i++) {
        int mirror = 2 * center - i;

        if (i < right) {
            lps[i] = min(right - i, lps[mirror]);
        }
        while (i + 1 + lps[i] < l && i - 1 - lps[i] >= 0 && s[i + 1 + lps[i]] == s[i - 1 - lps[i]]) {
            lps[i]++;
        }
        if (i + lps[i] > right) {
            center = i;
            right = i + lps[i];
        }
    }

    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 0; i < l; i++) {
        if (lps[i] > maxLen) {
            maxLen = lps[i];
            centerIndex = i;
        }
    }
    int start = (centerIndex - maxLen) / 2;
    cout << "Longest palindromic substring: " << a.substr(start, maxLen) << endl;

    delete[] lps;

    return 0;
}
