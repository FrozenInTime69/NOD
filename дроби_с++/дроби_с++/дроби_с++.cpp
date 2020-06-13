// дроби_с++.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h> 
using namespace std;
class drob
{
private: 
	int chisl;
	int znam;
public:
	int nod(int n,int m)
	{
		if ((n <= 0) || (m <= 0))
		{
			cout << "Invalid input" << endl;
		}
		if (n<m)
		{
			int k = m;
			m = n;
			n = k;
		}

		while (n != m)
		{
			n -= m;
			if (n<m)
			{
				int k = m;
				m = n;
				n = k;
			}
		}
		return n;
	}
	void socr()
	{
		int k = nod(chisl, znam);
		chisl /= k;
		znam /= k;
	}
	drob(int ch=0,int zn=1)
	{
		if ( zn != 0)//ch != 0 &&
		{
			chisl = ch;
			znam = zn;
			socr();
		}
		else cout << "Invalid input" << endl;
	}
	void show()
	{
		cout << chisl << "/" << znam << endl;
	}
	const drob operator*(const drob& d2)
	{
		drob tmp(chisl, znam);
		tmp.znam *= d2.znam;
		tmp.chisl *= d2.chisl;
		tmp.socr();
		return tmp;
	}
	 const drob operator*(int a)
	{
		drob tmp(chisl, znam);
		tmp.znam *= a;
		tmp.socr();
		return tmp;
	}
	const drob operator/(const drob& d2)
	{
		drob tmp(chisl, znam);
		tmp.znam *= d2.chisl;
		tmp.chisl *= d2.znam;
		tmp.socr();
		return tmp;
	}
	const drob operator+(const drob& d2)
	{
		drob tmp(chisl, znam);
		tmp.chisl = chisl*d2.znam + d2.chisl*znam;
		tmp.znam *= d2.znam;
		socr();
		return tmp;
	}
	const drob operator-(const drob& d2)
	{
		drob tmp(chisl, znam);
		tmp.chisl = chisl*d2.znam -d2.chisl*znam;
		tmp.znam *= d2.znam;
		socr();
		return tmp;
	}
	const drob operator=(const drob&d2)
	{
		drob tmp(d2.chisl, d2.znam);
		return tmp;
	}
	const int get_chisl()
	{
		return chisl;
	}
	const int get_znam()
	{
		return znam;
	}
};
ostream &operator <<(ostream &out, drob db)
{
	return out<<db.get_chisl()<<"/"<<db.get_znam()<<endl;
}

// Алгоритм Евклида GCD — greatest common divisor
int gcd(int a, int b) {
	int iter = 0;
	while (b) {
		iter++;
		cout << "STEP ";
		cout << iter;
		cout << "\n";
		if (iter != 1)
		{
			cout << "Counting NOD = ";
			cout << a;
			cout << "\n";
		}
		cout << "Changing values of a & b";
		cout << "\n";
		cout << "a = ";
		cout << b;
		cout << "\n";
		cout << "b = ";
		cout << a;
		cout << "\n";
		a %= b;
		swap(a, b);
	}
	cout << "Final NOD = ";
	cout << a;
	return a;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a = 0;
	int b = 1;
	cout << "Enter first integer value: ";
	cin >> a;
	cout << "Enter second integer value: ";
	cin >> b;
	int nod = gcd(a, b);
	cout << "\n";
	cout << "Press Enter to close the console ";
	_getch();
	return 0;
}

