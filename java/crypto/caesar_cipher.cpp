#include <iostream>
#include <string>
using namespace std;

string encrypt(string plaintext, int shift) {
    string ciphertext = "";

    for (int i = 0; i < plaintext.length(); i++) {
        char ch = plaintext[i];

        if (isupper(ch)) {
            ciphertext += char((int(ch - 65 + shift) % 26 + 26) % 26 + 65);
        }
        else if (islower(ch)) {
            ciphertext += char((int(ch - 97 + shift) % 26 + 26) % 26 + 97);
        }
        else {
            ciphertext += ch;
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, int shift) {
    string plaintext = "";

    for (int i = 0; i < ciphertext.length(); i++) {
        char ch = ciphertext[i];

        if (isupper(ch)) {
            plaintext += char(int(ch - shift - 65 + 26) % 26 + 65);
        }
        else if (islower(ch)) {
            plaintext += char(int(ch - shift - 97 + 26) % 26 + 97);
        }
        else {
            plaintext += ch;
        }
    }
    return plaintext;
}

int main() {
    string message;
    int shift;

    cout << "===== Caesar Cipher Program =====" << endl;
    cout << "\nEnter the plaintext message: ";
    getline(cin, message);

    cout << "Enter the shift value (key): ";
    cin >> shift;

    shift = shift % 26;

    string ciphertext = encrypt(message, shift);
    cout << "\n--- Encryption Result ---" << endl;
    cout << "Plaintext:  " << message << endl;
    cout << "Ciphertext: " << ciphertext << endl;

    string decrypted = decrypt(ciphertext, shift);
    cout << "\n--- Decryption Result ---" << endl;
    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Decrypted:  " << decrypted << endl;

    return 0;
}