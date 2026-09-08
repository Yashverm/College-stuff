#include <iostream>
#include <string>
using namespace std;

// Function to find modular multiplicative inverse of a under modulo m
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // Inverse doesn't exist
}

// Function to encrypt using Affine Cipher: E(x) = (a*x + b) mod 26
string encrypt(string plaintext, int a, int b) {
    string ciphertext = "";

    for (int i = 0; i < plaintext.length(); i++) {
        char ch = plaintext[i];

        if (isupper(ch)) {
            // x = ch - 'A', then E(x) = (a*x + b) mod 26
            int x = ch - 'A';
            int encrypted = (a * x + b) % 26;
            ciphertext += char(encrypted + 'A');
        }
        else if (islower(ch)) {
            // x = ch - 'a', then E(x) = (a*x + b) mod 26
            int x = ch - 'a';
            int encrypted = (a * x + b) % 26;
            ciphertext += char(encrypted + 'a');
        }
        else {
            // Non-alphabetic characters remain unchanged
            ciphertext += ch;
        }
    }
    return ciphertext;
}

// Function to decrypt using Affine Cipher: D(y) = a^(-1) * (y - b) mod 26
string decrypt(string ciphertext, int a, int b) {
    string plaintext = "";

    // Find modular inverse of a
    int a_inv = modInverse(a, 26);

    if (a_inv == -1) {
        return "Error: Key 'a' has no modular inverse. Decryption not possible.";
    }

    for (int i = 0; i < ciphertext.length(); i++) {
        char ch = ciphertext[i];

        if (isupper(ch)) {
            // y = ch - 'A', then D(y) = a^(-1) * (y - b) mod 26
            int y = ch - 'A';
            int decrypted = (a_inv * (y - b + 26)) % 26;
            plaintext += char(decrypted + 'A');
        }
        else if (islower(ch)) {
            int y = ch - 'a';
            int decrypted = (a_inv * (y - b + 26)) % 26;
            plaintext += char(decrypted + 'a');
        }
        else {
            plaintext += ch;
        }
    }
    return plaintext;
}

int main() {
    string message;
    int a, b;

    cout << "===== Affine Cipher Program =====" << endl;
    cout << "\nEnter the plaintext message: ";
    getline(cin, message);

    cout << "Enter key 'a' (must be coprime with 26): ";
    cin >> a;

    cout << "Enter key 'b': ";
    cin >> b;

    // Validate that 'a' is coprime with 26
    if (modInverse(a, 26) == -1) {
        cout << "\nError: Key 'a' = " << a << " is not coprime with 26." << endl;
        cout << "Valid values for 'a' are: 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25" << endl;
        return 1;
    }

    string ciphertext = encrypt(message, a, b);
    cout << "\n--- Encryption Result ---" << endl;
    cout << "Plaintext:  " << message << endl;
    cout << "Ciphertext: " << ciphertext << endl;

    string decrypted = decrypt(ciphertext, a, b);
    cout << "\n--- Decryption Result ---" << endl;
    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Decrypted:  " << decrypted << endl;

    return 0;
}