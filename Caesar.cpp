#include <iostream>
#include <string>

using namespace std;

string cypherCaesar(int count_chars, char *alphabet, string message, int k)
{
	k %= count_chars;

	for (int i = 0; i < message.size(); i++)
	{
		char symbol = message[i];
		for (int j = 0; j < count_chars; j++)
			if (alphabet[j] == symbol)
			{
				int t = j + k;
				if (t >= count_chars)
					t -= count_chars;
				symbol = alphabet[t];
				break;
			}
		message[i] = symbol;
	}

	return message;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int count_chars;
	cout << "������� ���������� ���� � ��������: ";
	cin >> count_chars;
	cin.get();
	if ( count_chars )
	{
		char *alphabet = new char[count_chars];

		cout << endl << "������� �������:" << endl;
		for (int i = 0; i < count_chars; i++)
			cin >> alphabet[i];

		cin.get();
		string message;
		cout << endl << "������� ���������:" << endl;
		getline(cin, message);

		int k;
		cout << endl << "������� �����: ";
		cin >> k;

		message = cypherCaesar(count_chars, alphabet, message, k);

		cout << endl << "������������� ���������:" << endl << message << endl;
	}
	else
	{
		cout << endl << "������ ���������..." << endl;
	}

	cout << endl;

	system("pause");
	return 0;
}