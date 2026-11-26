#include <iostream>
#include <cstring>
using namespace std;

// Simplified Rabin-Karp using an additive rolling hash.
void rabinKarp(char text[], char pat[]) {
    int n = strlen(text), m = strlen(pat);
    int p = 0, t = 0, count = 0;

    for(int i = 0; i < m; i++) {
        p += pat[i];
        t += text[i];
    }

    for(int i = 0; i <= n - m; i++) {
        if(p == t) {
            int j;
            for(j = 0; j < m; j++) {
                if(text[i+j] != pat[j]) break;
            }
            if(j == m) {
                cout << "Pattern found at " << i << endl;
                count++;
            }
        }

        if(i < n - m)
            t = t - text[i] + text[i+m];
    }

    if(count == 0) cout << "Pattern not found" << endl;
    cout << "Total matches: " << count << endl;
}

// Simplified Boyer-Moore using the bad-character rule.
void boyerMoore(char text[], char pat[]) {
    int n = strlen(text), m = strlen(pat);
    int last[256], count = 0;

    for(int i = 0; i < 256; i++)
        last[i] = -1;

    for(int i = 0; i < m; i++)
        last[(unsigned char)pat[i]] = i;

    int s = 0;
    while(s <= n - m) {
        int j = m - 1;
        while(j >= 0 && pat[j] == text[s+j])
            j--;

        if(j < 0) {
            cout << "Pattern found at " << s << endl;
            count++;
            s++; // Simple safe shift after a full match.
        } else {
            int shift = j - last[(unsigned char)text[s+j]];
            if(shift < 1) shift = 1;
            s += shift;
        }
    }

    if(count == 0) cout << "Pattern not found" << endl;
    cout << "Total matches: " << count << endl;
}

int main() {
    char text[100], pat[100];

    cout << "Enter text: ";
    cin.getline(text, 100);
    cout << "Enter pattern: ";
    cin.getline(pat, 100);

    int n = strlen(text), m = strlen(pat);
    if(m == 0 || m > n) {
        cout << "Invalid Pattern" << endl;
        return 0;
    }

    cout << "\nRabin-Karp:\n";
    rabinKarp(text, pat);

    cout << "\nBoyer-Moore:\n";
    boyerMoore(text, pat);
    return 0;
}
