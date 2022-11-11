#include<bits/stdc++.h>
using namespace std;

string plainToKey(string plainText, string key)
{
    int rem, quo;
    string plainToKeyText = "";
    quo = plainText.length() / key.length();
    rem = plainText.length() % key.length();

    for (int i = 0; i < quo; i++)
    {
        plainToKeyText += key;
    }

    for (int i = 0; i < rem; i++)
    {
        plainToKeyText += key[i];
    }
    return plainToKeyText;
}

string encryption(string plainText, string key)
{
    cout<<"\n\n************Inside encryption************\n"<<endl;
    string cipherText ="";
    string plainToKeyText = plainToKey(plainText, key);
    int matrix[26][26];

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            matrix[i][j] = (i + j) % 26;
        }
    }

    for (int i = 0; i < plainText.length(); i++)
    {
        int element = matrix[plainText[i] - 65][plainToKeyText[i] - 65];
        cipherText += char(element + 65);
    }
    cout << "Ciphertext : " << cipherText << endl;
    return cipherText;
}

void decryption(string encryptedText, string key)
{
    cout<<"\n\n************Inside decryption***********\n"<<endl;
    string decryptedText = "";
    string plainToKeyText = plainToKey(encryptedText, key);
    int matrix[26][26];

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            matrix[i][j] = (i + j) % 26;
        }
    }

    for (int i = 0; i < encryptedText.length(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (matrix[j][plainToKeyText[i] - 65] == encryptedText[i] - 65)
            {
                decryptedText += char(j + 65);
            }
        }
    }
    cout << "Decrypted Text : " << decryptedText << endl;
}