#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in("input_for_struct_11.txt");
ofstream out("output.txt"); 

struct Stock 
{
	string form; 
	int price;
 	string sort; 
	int count; 

	void read(string s); 
	void print(); 
};

void Stock::read(string s)
{
	int start = 0;
	int finish = 0;

	finish = s.find("_");

	string s2 = s.substr(start, finish - start); 
	form = s2;

	start = finish + 1;
	finish = s.find("_", start);
	s2 = s.substr(start, finish - start);
	price = atoi(s2.c_str());

	start = finish + 1;
	finish = s.find("_", start);
	s2 = s.substr(start, finish - start);
	sort = s2;

	start = finish + 1;
	finish = s.length();
	s2 = s.substr(start, finish - start);
	count = atoi(s2.c_str() );
}

void Stock::print()
{
	out << form << "_" << price << "_" << sort << "_" << count << endl;
}

void readStocks(Stock* &mas, int &n) 
{
	n = 0; //счетчик элементов 
	while ( in.peek() != EOF )
	{
		string s;
		getline( in, s );
		mas[n].read(s);
		n++;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Stock *mas = new Stock[1000];

	int n;
	readStocks(mas, n);

	int value;
	cout << "¬ведите максимально возможное количество товаров: " ;
	cin >> value;

	for( int i = 0; i < n ; i++ ) 
	{
		if( value > mas[i].count )
			mas[i].print();
	}

	system("pause");
	return 0;
}