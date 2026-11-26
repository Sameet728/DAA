#include <iostream>
using namespace std;

struct Node {
    char ch;
    int freq, left, right;
    bool used;
};

Node a[100];

int findMin(int count) {
    int pos = -1;
    for(int i = 0; i < count; i++) {
        if(!a[i].used && (pos == -1 || a[i].freq < a[pos].freq))
            pos = i;
    }
    return pos;
}

void printCode(int root, char code[], int len) {
    if(a[root].left == -1) {
        if(len == 0) code[len++] = '0';
        code[len] = '\0';
        cout << a[root].ch << " : " << code << endl;
        return;
    }

    code[len] = '0';
    printCode(a[root].left, code, len + 1);
    code[len] = '1';
    printCode(a[root].right, code, len + 1);
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    if(n < 1 || n > 50) return 0;

    cout << "Enter character and frequency:\n";
    for(int i = 0; i < n; i++) {
        cin >> a[i].ch >> a[i].freq;
        if(a[i].freq <= 0) return 0;
        a[i].left = a[i].right = -1;
        a[i].used = false;
    }

    int count = n;
    while(count < 2*n - 1) {
        int x = findMin(count);
        a[x].used = true;
        int y = findMin(count);
        a[y].used = true;

        a[count].ch = '$';
        a[count].freq = a[x].freq + a[y].freq;
        a[count].left = x;
        a[count].right = y;
        a[count].used = false;
        count++;
    }

    char code[100];
    cout << "\nHuffman Codes:\n";
    printCode(count - 1, code, 0);
    return 0;
}
