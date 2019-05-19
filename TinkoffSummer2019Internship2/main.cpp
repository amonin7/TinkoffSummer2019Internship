#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int findMaxDegree(int basis, int maxNumber) {
    int firstBasis = basis;
    if (basis > maxNumber)
        return 0;
    else
        for (int i = 2; i < 9; ++i) {
            basis *= firstBasis;
            if (basis > maxNumber)
                return basis / firstBasis;
        }
}

bool isRightNumber(long long number, vector<int>& remains, vector<int>& primes) {
    for (int i = 0; i < primes.size(); ++i)
        if (number % primes[i] != remains[primes[i]])
            return false;
    return true;
}

bool isResult(long long number, vector<int>& remains) {
    for (int i = 2; i < remains.size(); ++i)
        if (number % i != remains[i])
            return false;
    return true;
}

int main() {
    int m;
    cin >> m;
    vector<int> remains(m + 1, 0);
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    vector<int> primeDegrees(primes.size());

    int maxPrimeNumber;
    for (int i = 0; i < primes.size(); ++i) {
        if (primes[i] > m) {
            maxPrimeNumber = i - 1;
            break;
        }
    }
    primes.resize(maxPrimeNumber + 1);
    primeDegrees.resize(maxPrimeNumber + 1);

    for (int i = 2; i <= m; ++i)
        cin >> remains[i];

    long long overallMultiplication = 1;
    for (int i = 0; i < primes.size(); ++i) {
        primeDegrees[i] = findMaxDegree(primes[i], m);
        overallMultiplication *= (long long) primeDegrees[i];
    }

    long long mainRemain = 0;
    for (long long i = 0; i < overallMultiplication; ++i)
        if (isRightNumber(i, remains, primeDegrees))
            mainRemain = i;

    for (long long i = 0; i < 1000 * overallMultiplication; i += overallMultiplication)
        if (isResult(i + mainRemain, remains)) {
            cout << i + mainRemain << endl;
            break;
        }

    return 0;
}