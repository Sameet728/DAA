#include <iostream>
using namespace std;
int temp[100];
void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    while(i <= mid && j <= high) {
        if(a[i] <= a[j]) { temp[k] = a[i]; i++; }
        else { temp[k] = a[j]; j++; }
        k++;
    }
    while(i <= mid) { temp[k] = a[i]; i++; k++; }
    while(j <= high) { temp[k] = a[j]; j++; k++; }
    for(int x = low; x <= high; x++) a[x] = temp[x];
}
void mergeSort(int a[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
int main() {
    int n, a[100];
    cout << "Enter number of elements: ";
    cin >> n;
    if(n < 1 || n > 100) { cout << "Invalid size"; return 0; }
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> a[i];
    mergeSort(a, 0, n - 1);
    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
