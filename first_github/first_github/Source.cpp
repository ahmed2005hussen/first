#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string sentence, key;

int punction()
{
	for (int i = 0; i < key.size(); ++i) {


		if (ispunct(key[i])) {
			return 1;
		}

	}
	return 0;
}




int digit()
{
	for (int i = 0; i < key.size(); ++i) {


		if (isdigit(key[i])) {
			return 1;
		}

	}
	return 0;
}


int uniqe() {

	for (int i = 0; i < key.size(); ++i) {

		for (int k = i + 1; k < key.size(); ++k) {

			if (key[i] == key[k]) {
				return 1;
			}
		}
	}

	return 0;
}




int main()
{

	cout << "****************************************************" << endl;
	cout << "************ Simple Substitution Cipher ************" << endl;
	cout << "****************************************************" << endl;
	cout << endl;


	string str = "abcdefghijklmnopqrstuvwxyz";
	int process;
	cout << "Ahlan ya user ya habibi." << endl;
	cout << endl;

	cout << "What do you like to do today?" << endl;
	cout << endl;

	while (true)
	{
		cout << "1- Cipher a message" << endl;
		cout << "2- Decipher a message" << endl;
		cout << "3- End" << endl;
		cin >> process;
		cin.ignore();
		if (process == 1)
		{
			cout << "Enter the sentence which do you want cipher it ";
			getline(cin, sentence);

			for (char& c : sentence) {
				c = tolower(c);
			}
			cout << "Enter the key , key of 5 unique letters ";
			while (true) {
				cin >> key;

				for (char& c : key) {
					c = tolower(c);
				}

				if (key.size() == 5 && !uniqe() && !digit() && !punction())
				{

					for (int i = 0; i < 26; i++)
					{
						if (char(i + 'a') == key[0])
						{
							continue;
						}
						if (char(i + 'a') == key[1])
						{
							continue;
						}
						if (char(i + 'a') == key[2])
						{
							continue;
						}
						if (char(i + 'a') == key[3])
						{
							continue;
						}
						if (char(i + 'a') == key[4])
						{
							continue;
						}
						else
						{
							key += char(i + 'a');
						}



					}
					for (int i = 0; i < sentence.size(); i++)
					{
						for (int x = 0; x < 26; x++) {
							if (sentence[i] == str[x]) {
								sentence[i] = key[x];
								break;
							}
						}

					}
					cout << "The sentence is : " << sentence << endl;
					break;

				}
				else {
					cout << "Pls enter valid key : ";
					continue;
				}

			}
		}






		else if (process == 2)
		{

			cout << "Enter the sentence which do you want decipher it ";
			getline(cin, sentence);

			for (char& c : sentence) {
				c = tolower(c);
			}
			cout << "Enter the key , key of 5 unique letters ";
			while (true) {
				cin >> key;

				for (char& c : key) {
					c = tolower(c);
				}

				if (key.size() == 5 && !uniqe() && !digit() && !punction())
				{

					for (int i = 0; i < 26; i++)
					{
						if (char(i + 'a') == key[0])
						{
							continue;
						}
						if (char(i + 'a') == key[1])
						{
							continue;
						}
						if (char(i + 'a') == key[2])
						{
							continue;
						}
						if (char(i + 'a') == key[3])
						{
							continue;
						}
						if (char(i + 'a') == key[4])
						{
							continue;
						}
						else
						{
							key += char(i + 'a');
						}



					}
					for (int i = 0; i < sentence.size(); i++)
					{
						for (int x = 0; x < 26; x++) {
							if (sentence[i] == key[x]) {
								sentence[i] = str[x];
								break;
							}
						}

					}
					cout << "The sentence is : " << sentence << endl;
					break;

				}
				else {
					cout << "Pls enter valid key : ";
					continue;
				}






			}

		}
		else if (process == 3)
		{
			cout << " Good bye :)";
			break;
		}
		else
		{
			cout << "Please choice number from 1 To 3 " << endl;
			continue;
		}



	}

}