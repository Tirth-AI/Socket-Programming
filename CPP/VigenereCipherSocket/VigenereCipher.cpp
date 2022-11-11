#include <bits/stdc++.h>
#include "cipher.h"
using namespace std;

int main()
{
    string key = "", plainText = "";
    cout << "Enter the key:";
    cin >> key;
    cout << "Enter the plain text: ";
    cin >> plainText;

    string encryptedText = encryption(plainText, key);
    decryption(encryptedText, key);
    cout << "\n\n\n\n\n\n";
    return 0;   
}