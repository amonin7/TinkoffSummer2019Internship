#include <iostream>
#include <string.h>
using namespace std;
int main() {
    string password;
    cin >> password;
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;

    for (int i = 0; i < password.size(); ++i) {
        if (isupper(password[i])) hasUpper = true;
        if (islower(password[i])) hasLower = true;
        if (isdigit(password[i])) hasDigit = true;
    }
    if (hasDigit && hasLower && hasUpper && password.size() >= 8)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}