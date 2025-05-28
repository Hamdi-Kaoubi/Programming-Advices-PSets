#include <iostream>
#include "clsUtility.h"
//using namespace std;

int main()
{
    
    clsUtility::Srand();
    cout << clsUtility::RandomNumber(1, 10) << endl;
    cout << clsUtility::GetRandomCharacter(clsUtility::MixChars) << endl;
    cout << clsUtility::GenerateWord(clsUtility::MixChars, 8) << endl;
    cout << clsUtility::GenerateKey(clsUtility::MixChars) << endl;
    //clsUtility::GenerateKeys(10, clsUtility::MixChars);

    //Swap integer:
    int x = 10, y = 20;
    cout << "\nswap integers:\n";
    cout << x << " " << y << endl;
    clsUtility::Swap(x, y);
    cout << x << " " << y << endl;

    //Swap Double:
    double a = 10.2, b = 20.1;
    cout << "\nswap doubles:\n";
    cout << a << " " << b << endl;
    clsUtility::Swap(a, b);
    cout << a << " " << b << endl;

    //Swap string:
    string s1 = "Ali", s2 = "Mohammed";
    cout << "\nswap strings:\n";
    cout << s1 << " " << s2 << endl;
    clsUtility::Swap(s1, s2);
    cout << s1 << " " << s2 << endl;

    //Swap Dates:
    clsDate d1(1, 5, 2022), d2(1, 10, 2023);
    cout << "\nswap dates:\n";
    cout << d1.DateToString() << " " << d2.DateToString() << endl;
    clsUtility::Swap(d1, d2);
    cout << d1.DateToString() << " " << d2.DateToString() << endl;

    //Fill Array with Random Numbers:
    int Arr1[5];
    clsUtility::FillArrayWithRandomNumbers(Arr1, 5, 20, 50);
    cout << "\nArray after fill:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr1[i] << endl;
    }

    //Fill Array with Random words:
    string Arr2[5];
    clsUtility::FillArrayWithRandomWords(Arr2, 5, clsUtility::MixChars, 8);
    cout << "\nArray after fill with words:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr2[i] << endl;
    }

    //Fill Array with Random Keys:
    string Arr3[5];
    clsUtility::FillArrayWithRandomKeys(Arr3, 5, clsUtility::MixChars);
    cout << "\nArray after fill with keys:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << Arr3[i] << endl;
    }

    //Shuffle Array of Numbers:
    int Arr4[4] = { 1,5,20,3 };
    clsUtility::ShuffleArray(Arr4, 4);
    cout << "\nArray after shuffle:\n";
    for (int i = 0; i < 4; i++)
    {
        cout << Arr4[i] << endl;
    }

    //Shuffle Array of strings:
    string Arr5[4] = { "Ali", "Mohammed", "Jaber", "Hamdi" };
    clsUtility::ShuffleArray(Arr5, 4);
    cout << "\nArray after shuffle strings:\n";
    for (int i = 0; i < 4; i++)
    {
        cout << Arr5[i] << endl;
    }

    //Tabs:
    cout << "\ntext1 " << clsUtility::Tabs(5) << "text2\n";

    //Encrypted text:
    const short EncryptionKey = 2;
    string TextAfterEncryption, TextAfterDecryption, Text = "Mohammed Abu-Hadhoud";

    TextAfterEncryption = clsUtility::EncryptText(Text, EncryptionKey);
    cout << "\nText after encryption:\n";
    cout << TextAfterEncryption << endl;

    //Decrypted text:
    TextAfterDecryption = clsUtility::DecryptText(TextAfterEncryption, EncryptionKey);
    cout << "\nText after decryption:\n";
    cout << TextAfterDecryption << endl;

    system("pause>0");
}
