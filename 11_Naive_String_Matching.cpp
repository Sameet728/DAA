#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char text[100], pat[100];
    cout << "Enter the text: ";
    cin.getline(text, 100);
    cout << "Enter pattern: ";
    cin.getline(pat, 100);
    int n = strlen(text);
    int m = strlen(pat);
    if (m == 0 || m > n) {
        cout << "Invalid pattern";
        return 0;
    }

    int count = 0;
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i+j] != pat[j]) {
                break;
            }
        }

        if (j == m) {
            cout << "Pattern found at index " << i << endl;
            count++;
        }
    }

    if (count == 0) {
        cout << "No pattern found" << endl;
    }
    else {
        cout << "Total patterns found = " << count << endl;
    }

    return 0;
}
