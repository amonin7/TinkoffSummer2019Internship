#include <iostream>
#include <vector>

using namespace std;
struct Point {
    int x;
    int y;
};
int main() {
    int amPoints;
    cin >> amPoints;
    if (amPoints == 1) {
        struct Point p1 = {};
        cin >> p1.x >> p1.y;
        cout << "NO" << endl;
    } else if (amPoints == 2) {
        struct Point p1 = {};
        cin >> p1.x >> p1.y;
        struct Point p2 = {};
        cin >> p2.x >> p2.y;
        cout << "NO" << endl;
    } else {
        struct Point p1 = {}, p2 = {};
        cin >> p1.x >> p1.y;
        cin >> p2.x >> p2.y;

        if (p1.x != p2.x) {
            double angleCoef = ((double) (p2.y - p1.y)) / ((double) (p2.x - p1.x));
            double moveCoef = p2.y - angleCoef * p2.x;

            struct Point pCurrent = {};
            bool isFound = false;
            for (int i = 0; i < amPoints - 2; ++i) {
                cin >> pCurrent.x >> pCurrent.y;
                if (pCurrent.y != angleCoef * pCurrent.x + moveCoef)
                    isFound = true;
            }
            if (isFound)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else {
            struct Point pCurrent = {};
            bool isFound = false;
            for (int i = 0; i < amPoints - 2; ++i) {
                cin >> pCurrent.x >> pCurrent.y;
                if (pCurrent.x != p1.x)
                    isFound = true;
            }
            if (isFound)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}