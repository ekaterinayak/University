#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

ifstream in("input_for_struct_17-18.txt");
ofstream out("output.txt");

struct Point
{
	double x;
	double y;

	void read(string s);
	void print();
};

void Point::read(string s)
{
	int start = 0;
	int finish = s.find(" ");
	
	string s2 = s.substr(start, finish - start);
	x = atoi(s2.c_str() );

	start = finish + 1;
	finish = s.length();
	s2 = s.substr(start, finish - start);
	y = atoi(s2.c_str() );
}

void Point::print()
{
	out << x << " " << y << endl;	
}

void readPoints(Point* &mas, int &n)
{
	n = 0; 
	while ( in.peek() != EOF )
	{
		string s;
		getline( in, s );
		mas[n].read(s);
		n++;
	}
}

struct Triangle
{
	//Point *points = new Point[3];
	
	double LengthSide( Point a, Point b ); 
	double P( Point a, Point b, Point c );
};

double Triangle::LengthSide(Point a, Point b)
{
	double ax = a.x;
	double ay = a.y;
	double bx = b.x;
	double by = b.y;

	Point c;
	c.x = ax;
	c.y = by;

	double length_ac = fabs( ay - c.y );
	double length_bc = fabs( bx - c.x );
	
	return sqrt( length_ac * length_ac + length_bc * length_bc );
}

double Triangle::P(Point a, Point b, Point c)
{
	return LengthSide( a, b ) + LengthSide( b, c ) + LengthSide( c, a );
}

int main()
{
	//setlocale(LC_ALL, "Russian");

	Point *mas = new Point[1000];

	int n;
	readPoints(mas, n);

	double max = -1;
	Point *masik = new Point[3]; //array (new points for save)

	for( int i = 0; i < n ; i++ ) 
	{
		for( int j = 0; j < n; j++ )
		{
			for( int k = 0; k < n; k++ )
			{
				if (i != j && i != k && j != k)
				{
					Triangle abc;

					double Pabc = abc.P( mas[i], mas[j], mas[k] );
					
					if( Pabc > max ) 
					{
						max = Pabc;
						masik[0] = mas[i];
						masik[1] = mas[j];
						masik[2] = mas[k];
					}
				}
			}
		}
	}

	for( int i = 0; i < 3; i++ ) 
	{
		masik[i].print();
	}

	system("pause");
	return 0;
}