#include <iostream>
using namespace std;
int findMaxDivisor(int number) {
    for (int i = 2; i * i < number; ++i)
        if (number % i == 0)
            return i;
    return number;
}
int main() {
    int n;
    cin >> n;
    cout << findMaxDivisor(n) << endl;
    return 0;
}