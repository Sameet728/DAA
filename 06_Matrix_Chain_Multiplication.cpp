#include <iostream>
#include <climits>

using namespace std;

int m[51][51], s[51][51];

void printOrder(int i, int j) {
    if (i == j) {
        cout << "A" << i;
        return;
    }

    cout << "(";
    printOrder(i, s[i][j]);
    printOrder(s[i][j] + 1, j);
    cout << ")";
}

int main() {
    int n, p[51];
    cout << "Enter number of matrices: ";
    cin >> n;
    if (n < 1 || n > 50) {
        return 0;
    }

    cout << "Enter dimensions (" << n+1 << " numbers): ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k+1][j]
                         + p[i-1] * p[k] * p[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum multiplications = " << m[1][n] << endl;
    cout << "Optimal order: ";
    printOrder(1, n);
    cout << endl;
    return 0;
}
