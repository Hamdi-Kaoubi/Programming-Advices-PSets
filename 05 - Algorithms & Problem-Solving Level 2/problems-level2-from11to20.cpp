#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


//Problem 11:
/*int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}*/
/*int ReverseNumber(int num)
{
	int remainder;
	int result=0;
	while (num > 0)
	{
		remainder = num % 10;
		num /= 10;
		result = result * 10 + remainder;
	}
	return result;
}*/
/*void CheckAndPrintPalindrome(int num)
{
	if (ReverseNumber(num) == num)
		cout << "Yes, it is Palindrome number.\n";
	else
		cout << "No, it is not Palindrome number.\n";
}*/

//Problem 12:
/*int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}*/
/*void PrintInvertedPatern(int num)
{
	for (int i = num; i >=1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}
		cout << endl;
	}
}*/

//Problem 13: same as problem 12 just instead of i-- we change it to i++

//Problem 14:
/*int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}*/
/*void PrintInvertedPaternLetters(int num)
{
	for (int i = num; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << char(i+64);
		}
		cout << endl;
	}
}*/

//Problem 15:
/*int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}*/
/*void PrintPaternLetters(int num)
{
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << char(i + 64);
		}
		cout << endl;
	}
}*/

//Problem 16:
/*void printAllLetters()
{
	cout << "\n";
	string word = "";
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				word = word + char(i);
				word = word + char(j);
				word = word + char(k);
				cout << word << endl;
				word = "";
			}
		}
		cout << "\n_________________________________________\n";
	}
}*/

//Problem 17:
/*string ReadCapitalPassword(string message)
{
	string pass;
	do
	{
		cout << message;
		cin >> pass;
	} while (pass.length() != 3 or (char(pass[0]) < 65 or char(pass[0]) > 90) or (char(pass[1]) < 65 or char(pass[1]) > 90) or (char(pass[2]) < 65 or char(pass[2]) > 90));
	return pass;
}*/
/*bool GetAndPrintNumberOfTrials(string pass)
{
	int counter = 0;
	string word = "";
	cout << "\n";
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				counter++;
				word = word + char(i);
				word = word + char(j);
				word = word + char(k);
				cout << "Trial[" << counter << "]: " << word << endl;
				if (word == pass)
				{
					cout << "\nPassword is " << word << endl;
					cout << "Found after " << counter << " Trial(s)." << endl;
					return true;
				}
				word = "";
			}
		}
	}
	return false;
}*/

//Problem 18:
/*string ReadYourName()
{
	string name;
	cout << "enter your name: ";
	cin >> name;
	return name;
}*/
/*string EncryptName(string name)
{
	string encryptedName = "";
	for (int i = 0; i < name.length(); i++)
	{
		encryptedName += char(int(name[i]) + 2);
	}
	return encryptedName;
}*/
/*string DecryptName(string name)
{
	string decryptedName = "";
	for (int i = 0; i < name.length(); i++)
	{
		decryptedName += char(int(name[i]) - 2);
	}
	return decryptedName;
}*/
/*void PrintEncryptedAndDecrypted(string name)
{
	cout << "Text Before Encryption: " << name << endl;
	cout << "Text After Encryption: " << EncryptName(name) << endl;
	cout << "Text After Decryption: " << DecryptName(EncryptName(name)) << endl;
}*/

//Problem 18: abu-hadhoud solution:
/*string ReadText()
{
	string text;
	cout << "enter your text: ";
	cin >> text;
	return text;
}*/
/*string Encrypttext(string text, short encryptionKey)
{
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = char((int)text[i] + encryptionKey);
	}
	return text;
}*/
/*string Decrypttext(string text, short encryptionKey)
{
	for (int i = 0; i < text.length(); i++)
	{
		text[i] = char((int)text[i] - encryptionKey);
	}
	return text;
}*/

//Problem 19:
/*int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}*/

//Problem 20:
enum letters { small=1,capital=2, special=3, digit=4};
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
char getCharNumber(letters charNum)
{
	switch (charNum)
	{
	case letters::small:
		return char(RandomNumber(97, 122));
		break;
	case letters::capital:
		return char(RandomNumber(65, 90));
		break;
	case letters::special:
		return char(RandomNumber(33, 47));
		break;
	case letters::digit:
		return char(RandomNumber(48, 57));
		break;
	default:
		break;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	//Problem 11:
	/*CheckAndPrintPalindrome(ReadPositiveNumber("Enter a positive number: "));*/

	//Problem 12:
	/*PrintInvertedPatern(ReadPositiveNumber("Enter a positive number: "));*/

	//Problem 13: same as problem 12 just instead of i-- we change it to i++

	//Problem 14:
	/*PrintInvertedPaternLetters(ReadPositiveNumber("Enter a positive number: "));*/

	//Problem 15:
	/*PrintPaternLetters(ReadPositiveNumber("Enter a positive number: "));*/

	//Problem 16:
	/*printAllLetters();*/

	//Problem 17:
	/*GetAndPrintNumberOfTrials(ReadCapitalPassword("Enter a three capital characters password: "));*/
	
	//Problem 18:
	/*PrintEncryptedAndDecrypted(ReadYourName());*/

	//Problem 18: abu-hadhoud solution:
	/*const short encryptionKey = 2; //this is the key
	string text = ReadText();
	string textAfterEncryption = Encrypttext(text, encryptionKey);
	string textAfterDecryption = Decrypttext(textAfterEncryption, encryptionKey);
	cout << "\nText Before Encryption: " << text << endl;
	cout << "Text After Encryption: " << textAfterEncryption << endl;
	cout << "Text After Decryption: " << textAfterDecryption << endl;*/

	//Problem 19:
	/*srand((unsigned)time(NULL));
	cout << RandomNumber(1, 10) << endl;
	cout << RandomNumber(1, 10) << endl;
	cout << RandomNumber(1, 10) << endl;*/

	//Problem 20:
	cout << getCharNumber(letters::small) << endl;
	cout << getCharNumber(letters::capital) << endl;
	cout << getCharNumber(letters::special) << endl;
	cout << getCharNumber(letters::digit) << endl;
}

