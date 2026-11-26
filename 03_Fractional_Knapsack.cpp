#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    double weight, profit, ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n;
    Item a[100];
    double capacity, totalProfit = 0;
    cout << "Enter number of items: ";
    cin >> n;
    if (n < 1 || n > 100) {
        cout << "Invalid size";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter weight and profit of item " << i + 1 << ": ";
        cin >> a[i].weight >> a[i].profit;
        if (a[i].weight <= 0 || a[i].profit < 0) {
            cout << "Invalid item";
            return 0;
        }

        a[i].ratio = a[i].profit / a[i].weight;
    }

    cout << "Enter bag capacity: ";
    cin >> capacity;
    if (capacity < 0) {
        return 0;
    }

    sort(a, a + n, compare);
    for (int i = 0; i < n && capacity > 0; i++) {
        if (a[i].weight <= capacity) {
            totalProfit += a[i].profit;
            capacity -= a[i].weight;
        }
        else {
            totalProfit += a[i].ratio * capacity;
            capacity = 0;
        }
    }

    cout << "Maximum Profit = " << totalProfit << endl;
    return 0;
}
