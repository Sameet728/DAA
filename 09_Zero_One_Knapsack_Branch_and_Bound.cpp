#include <iostream>

using namespace std;

struct Item {
    int weight, profit;
};
Item items[100];
int n, capacity;
long long bestProfit = 0;
int taken[100] = {
    0
}

, bestTaken[100] = {
    0
};
// Upper bound using Fractional Knapsack after ratio sorting.

double upperBound(int i, int weight, long long profit) {
    int remaining = capacity - weight;
    double bound = profit;
    while (i < n && items[i].weight <= remaining) {
        remaining -= items[i].weight;
        bound += items[i].profit;
        i++;
    }

    if (i < n) {
        bound += (double)remaining * items[i].profit / items[i].weight;
    }

    return bound;
}

void knapsack(int i, int weight, long long profit) {
    if (profit > bestProfit) {
        bestProfit = profit;
        for (int j = 0; j < n; j++) {
            bestTaken[j] = taken[j];
        }
    }

    if (i == n || weight == capacity) {
        return;
    }

    if (upperBound(i, weight, profit) <= bestProfit) {
        return;
    }

    // Include item i.
    if (items[i].weight <= capacity - weight) {
        taken[i] = 1;
        knapsack(i + 1, weight + items[i].weight,
                 profit + items[i].profit);
        taken[i] = 0;
    }

    // Exclude item i.
    knapsack(i + 1, weight, profit);
}

int main() {
    cout << "Enter number of items and capacity: ";
    cin >> n >> capacity;
    if (n < 0 || n > 100 || capacity < 0) {
        return 0;
    }

    cout << "Enter weight and profit of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].profit;
        if (items[i].weight <= 0 || items[i].profit < 0) {
            return 0;
        }
    }

    // Sort by profit/weight ratio (highest first).
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (1LL * items[j].profit * items[i].weight >
               1LL * items[i].profit * items[j].weight) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    knapsack(0, 0, 0);
    cout << "Maximum profit = " << bestProfit << endl;
    cout << "Selected items (weight, profit): ";
    int totalWeight = 0;
    for (int i = 0; i < n; i++) {
        if (bestTaken[i]) {
            cout << "(" << items[i].weight << ", " << items[i].profit << ") ";
            totalWeight += items[i].weight;
        }
    }

    cout << "\nTotal weight = " << totalWeight << endl;
    return 0;
}
