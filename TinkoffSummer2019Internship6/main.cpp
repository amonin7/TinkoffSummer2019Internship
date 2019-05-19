#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char>> table(rows, vector<char>(cols));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> table[i][j];

    string path;
    for (int i = 0; i < rows - 1; ++i) path += "0";
    for (int i = 0; i < cols - 1; ++i) path += "1";

    vector<string> passwords;
    do {
        string currentPassword;
        for (int i = 0, j = 0; i + j < rows + cols - 1;) {
            currentPassword += table[i][j];
            char nowmove = path[i + j];
            if (nowmove == '0')
                ++i;
            else
                ++j;
        }
        passwords.push_back(currentPassword);
    } while ( next_permutation(path.begin(), path.end()) );
    sort(passwords.begin(), passwords.end());
    int wantedPassword;
    cin >> wantedPassword;
    cout << passwords[wantedPassword - 1];
    return 0;
}