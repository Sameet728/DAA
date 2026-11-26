#include <iostream>
#include <climits>

using namespace std;

int n, a[15][15], mn[15];
int visited[15], path[15], bestPath[15];
int best = INT_MAX;

void tsp(int level, int last, int cost) {
    if (level == n) {
        int total = cost + a[last][0];
        if (total < best) {
            best = total;
            for (int i = 0; i < n; i++) {
                bestPath[i] = path[i];
            }
        }

        return;
    }

    for (int j = 1; j < n; j++) {
        if (!visited[j]) {
            int newCost = cost + a[last][j];
            visited[j] = 1;
            int bound = newCost + mn[j];
            for (int k = 0; k < n; k++) {
                if (!visited[k]) {
                    bound += mn[k];
                }
            }

            if (bound < best) {
                path[level] = j;
                tsp(level + 1, j, newCost);
            }

            visited[j] = 0;
        }
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;
    if (n < 2 || n > 15) {
        return 0;
    }

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        mn[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i != j && a[i][j] < mn[i]) {
                mn[i] = a[i][j];
            }
        }
    }

    visited[0] = 1;
    path[0] = 0;
    tsp(1, 0, 0);
    cout << "Minimum cost = " << best << endl;
    cout << "Path: ";
    for (int i = 0; i < n; i++) {
        cout << bestPath[i] + 1 << " -> ";
    }

    cout << 1 << endl;
    return 0;
}
