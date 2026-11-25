#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
int main() {
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char captcha[7], input[100];
    srand(time(0));
    for(int i = 0; i < 6; i++) {
        int r = rand() % 62;
        captcha[i] = chars[r];
    }
    captcha[6] = '\0';
    cout << "CAPTCHA: " << captcha << endl;
    for(int i = 1; i <= 3; i++) {
        cout << "Enter CAPTCHA: ";
        cin.width(100);
        cin >> input;
        if(strcmp(captcha, input) == 0) {
            cout << "CAPTCHA Verified!" << endl;
            return 0;
        } else {
            cout << "Wrong CAPTCHA" << endl;
            cout << "Attempts left: " << 3 - i << endl;
        }
    }
    cout << "Verification failed. Access denied." << endl;
    return 0;
}
