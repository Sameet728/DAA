#include <iostream>
using namespace std;
int a[100], x[100];
int n, target, total = 0;
void subset(int i, int sum, int remaining) {
    if(sum == target) {
        total++;
        cout << "Subset: ";
        for(int j = 0; j < i; j++)
            if(x[j] == 1) cout << a[j] << " ";
        cout << endl;
        return;
    }
    if(i == n || sum > target || sum + remaining < target) return;
    x[i] = 1;
    subset(i + 1, sum + a[i], remaining - a[i]);
    x[i] = 0;
    subset(i + 1, sum, remaining - a[i]);
}
int main() {
    int remaining = 0;
    cout << "Enter number of elements: ";
    cin >> n;
    if(n < 1 || n > 100) { cout << "Invalid size"; return 0; }
    cout << "Enter positive elements: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] <= 0) {
            cout << "Only positive elements supported"; return 0;
        }
        remaining += a[i];
    }
    cout << "Enter target sum: ";
    cin >> target;
    if(target < 0) return 0;
    subset(0, 0, remaining);
    if(total == 0) cout << "No subset found" << endl;
    else cout << "Total subsets = " << total << endl;
    return 0;
}
