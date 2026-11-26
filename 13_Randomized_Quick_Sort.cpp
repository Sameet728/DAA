#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(int a[], int low, int high) {
    int pivot = a[low], i = low;
    for (int j = low + 1; j <= high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[low], a[i]);
    return i;
}

int randomPartition(int a[], int low, int high) {
    int r = low + rand() % (high - low + 1);
    swap(a[r], a[low]);
    return partition(a, low, high);
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
    srand(time(0));
    int n, a[100];
    cout << "Enter number of elements: ";
    cin >> n;
    if (n < 1 || n > 100) {
        cout << "Invalid size";
        return 0;
    }

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}
