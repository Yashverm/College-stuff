#include <iostream>
#include <string>
using namespace std;

char grid[5][5];

void createGrid(string key) {
    string alpha = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // J omitted
    string used = "";
    int r = 0, c = 0;

    for (char k : key) {
        k = toupper(k == 'J' ? 'I' : k);
        if (used.find(k) == string::npos) {
            grid[r][c] = k;
            used += k;
            c++; if (c == 5) { c = 0; r++; }
        }
    }
    for (char a : alpha) {
        if (used.find(a) == string::npos) {
            grid[r][c] = a;
            c++; if (c == 5) { c = 0; r++; }
        }
    }
}

void findPos(char ch, int &row, int &col) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (grid[i][j] == ch) { row = i; col = j; return; }
}

string decrypt(string cipher) {
    string plain = "";
    for (int i = 0; i < cipher.length(); i += 2) {
        int r1, c1, r2, c2;
        findPos(cipher[i], r1, c1);
        findPos(cipher[i+1], r2, c2);

        if (r1 == r2) { // Same row: move left
            plain += grid[r1][(c1 + 4) % 5];
            plain += grid[r2][(c2 + 4) % 5];
        }
        else if (c1 == c2) { // Same column: move up
            plain += grid[(r1 + 4) % 5][c1];
            plain += grid[(r2 + 4) % 5][c2];
        }
        else { // Rectangle: swap columns
            plain += grid[r1][c2];
            plain += grid[r2][c1];
        }
    }
    return plain;
}

int main() {
    string cipher, key;
    cout << "Enter ciphertext: "; cin >> cipher;
    cout << "Enter key: "; cin >> key;

    createGrid(key);
    cout << "Plaintext: " << decrypt(cipher) << endl;
    return 0;
}