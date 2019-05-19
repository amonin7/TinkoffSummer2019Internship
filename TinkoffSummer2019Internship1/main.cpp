#include <iostream>
using namespace std;
int main() {
    double firstDay, minLength;
    cin >> firstDay >> minLength;
    int cntDays = 1;
    double currentSum = firstDay;
    while (currentSum <= minLength) {
        ++cntDays;
        firstDay *= 1.7;
        currentSum += firstDay;
    }
    cout << cntDays << endl;
    return 0;
}