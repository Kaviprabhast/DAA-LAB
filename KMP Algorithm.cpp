#include<iostream>
#include<string>
using namespace std;

void computeLPSArray(string pat, int m, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMP_Search(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();
    
    int lps[m];
    computeLPSArray(str2, m, lps);

    int i = 0;
    int j = 0; 
    while (i < n) {
        if (str2[j] == str1[i]) {
            i++;
            j++;
        }

        if (j == m) {
            return (i - j); 
            j = lps[j - 1];
        }
        else if (i < n && str2[j] != str1[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return -1;
}

int main() {
    string str1 = "Hello";
    string str2 = "o";
    int result = KMP_Search(str1, str2);

    if (result != -1)
        cout << "Found at index " << result << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
