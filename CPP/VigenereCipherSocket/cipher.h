#include<bits/stdc++.h>
using namespace std;

char decryptedText[100] = "";
char cipherText[100] = "";


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

char *encryption(string plainText, string key)
{
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
        cipherText[i] = char(element + 65);
    }
    return cipherText;
}

char *decryption(char *encryptedText, string key)
{
    string plainToKeyText = plainToKey(encryptedText, key);
    int matrix[26][26];

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            matrix[i][j] = (i + j) % 26;
        }
    }

    for (int i = 0; i < strlen(encryptedText); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (matrix[j][plainToKeyText[i] - 65] == encryptedText[i] - 65)
            {
                decryptedText[i] = char(j + 65);
            }
        }
    }
    return decryptedText;
}