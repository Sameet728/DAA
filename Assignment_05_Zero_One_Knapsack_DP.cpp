#include <iostream>
#include <algorithm>
using namespace std;
int dp[101][1001];
int main() {
    int n, capacity;
    int weight[100], profit[100];
    cout << "Enter number of items: ";
    cin >> n;
    if(n < 1 || n > 100) { cout << "Invalid size"; return 0; }
    for(int i = 0; i < n; i++) {
        cout << "Enter weight and profit for item " << i + 1 << ": ";
        cin >> weight[i] >> profit[i];
        if(weight[i] < 0 || profit[i] < 0) {
            cout << "Invalid item"; return 0;
        }
    }
    cout << "Enter bag capacity: ";
    cin >> capacity;
    if(capacity < 0 || capacity > 1000) {
        cout << "Invalid capacity"; return 0;
    }
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= capacity; w++) {
            if(i == 0 || w == 0) dp[i][w] = 0;
            else if(weight[i-1] <= w)
                dp[i][w] = max(profit[i-1] + dp[i-1][w-weight[i-1]],
                               dp[i-1][w]);
            else dp[i][w] = dp[i-1][w];
        }
    }
    cout << "Maximum Profit = " << dp[n][capacity] << endl;
    return 0;
}
