#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;



class clsUtility
{
public:

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		return rand() % (To - From + 1) + From;
	}

    enum _letters { small = 1, capital = 2, digit = 3, special = 4, MixChars = 5 };

    static _letters RandSmallCapDig()
    {
        return _letters(RandomNumber(1, 3));
    }

    static char GetRandomCharacter(_letters charType)
    {
        switch (charType)
        {
        case _letters::small:
            return char(RandomNumber(97, 122));
            break;
        case _letters::capital:
            return char(RandomNumber(65, 90));
            break;
        case _letters::digit:
            return char(RandomNumber(48, 57));
            break;
        case _letters::special:
            return char(RandomNumber(33, 47));
            break;
        case _letters::MixChars:
            switch (RandSmallCapDig())
            {
            case _letters::small:
                return char(RandomNumber(97, 122));
                break;
            case _letters::capital:
                return char(RandomNumber(65, 90));
                break;
            case _letters::digit:
                return char(RandomNumber(48, 57));
                break;
            }
            break;
        }
    }

    static string GenerateWord(_letters charType, short length)
    {
        string characters = "";
        for (int i = 1; i <= length; i++)
        {
            characters += GetRandomCharacter(charType);
        }
        return characters;
    }

    static string GenerateKey(_letters charType)
    {
        string Key = "";
        Key = Key + GenerateWord(charType, 4) + "-";
        Key = Key + GenerateWord(charType, 4) + "-";
        Key = Key + GenerateWord(charType, 4) + "-";
        Key = Key + GenerateWord(charType, 4);
        return Key;
    }

    static void GenerateKeys(int key, _letters charType)
    {
        for (int i = 1; i <= key; i++)
        {
            cout << "Key[" << i << "] : ";
            cout << GenerateKey(charType) << endl;
        }
    }

    static void Swap(int& N1, int& N2)
    {
        int Temp;
        Temp = N1;
        N1 = N2;
        N2 = Temp;
    }
    static void Swap(double& N1, double& N2)
    {
        double Temp;
        Temp = N1;
        N1 = N2;
        N2 = Temp;
    }
    static void Swap(char& C1, char& C2)
    {
        char Temp;
        Temp = C1;
        C1 = C2;
        C2 = Temp;
    }
    static void Swap(string& S1, string& S2)
    {
        string Temp;
        Temp = S1;
        S1 = S2;
        S2 = Temp;
    }
    static void Swap(clsDate& D1, clsDate& D2)
    {
        string s1 = clsDate::DateToString(D1), s2 = clsDate::DateToString(D2);
        Swap(s1, s2);
    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, _letters chartype, int stringLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateWord(chartype, stringLength);
        }
    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, _letters chartype)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateKey(chartype);
        }
    }

    static void ShuffleArray(int arr[100], int size)
    {
        for (int i = 0; i < size; i++)
        {
            Swap(arr[RandomNumber(1, size) - 1], arr[RandomNumber(1, size) - 1]);
        }
    }
    static void ShuffleArray(string arr[100], int size)
    {
        for (int i = 0; i < size; i++)
        {
            Swap(arr[RandomNumber(1, size) - 1], arr[RandomNumber(1, size) - 1]);
        }
    }

    static string Tabs(short num)
    {
        string Tab = "";
        for (short i = 1; i <= num; i++)
        {
            Tab += "\t";
        }
        return Tab;
    }

    static string EncryptText(string text, short EncryptKey)
    {
        string encryptedText = "";
        for (int i = 0; i < text.length(); i++)
        {
            encryptedText += char(int(text[i]) + EncryptKey);
        }
        return encryptedText;
    }

    static string DecryptText(string text, short EncryptKey)
    {
        string decryptedText = "";
        for (int i = 0; i < text.length(); i++)
        {
            decryptedText += char(int(text[i]) - EncryptKey);
        }
        return decryptedText;
    }

};

