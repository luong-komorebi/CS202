#include <iostream>
using namespace std;

class Fraction
{
public:
	Fraction(int x, int y); //1

	Fraction(int x)
	{
		num = x;
		denom = 1;
	}

	void operator+=(Fraction z); //2
	//...
	//Fraction add(const Fraction& z);
	static Fraction div(const Fraction& z,const Fraction&y);
	static Fraction add(const Fraction& z,const Fraction& y);
	static Fraction multi(const Fraction& z,const Fraction&y);
	void display()
	{
		cout << "Fraction = " << num << "/" << denom << endl;
	}

	//int getNum() const {return num;}
	//int getDe() const {return denom;}

	friend Fraction operator+(const Fraction& x, const Fraction& y);

private:
	int num, denom;
};

//global functions
Fraction operator+(const Fraction& x, const Fraction& y);
//Fraction operator+(const Fraction& x, int y);
//Fraction operator+(int x, const Fraction& y);

int main()
{
	Fraction x(1, 3), y(2, 5), z(0, 1);

	//1
	//z = x.add(y);
	// z = x.add(5);
	// z = 5.add(x); <<<<<<<<<<

	//2
	z = Fraction::add(x, y);

	//3
	//z = add(x, y);
	z = x+y;
	z = x+5;
	z = 5 + x;

	// z = add(x, 5);
	// z = add(5, x); <<<<<< OK

	return 0;
}
/*
Fraction add(const Fraction& x, const Fraction& y)
{
	Fraction tmp(x);
	tmp += y;
	return tmp;
}
*/

Fraction operator+(const Fraction& x, const Fraction& y)
{
	int num = x.num * y.denom + y.num * x.denom;
	int denom = x.denom * y.denom;
	return Fraction(num, denom);
}


//1
Fraction Fraction::add(const Fraction& z)
{
	Fraction tmp(0, 1);
	tmp.num = z.num*denom + num*z.denom;
	tmp.denom = z.denom*denom;
	return tmp;
}

//2
Fraction Fraction::add(const Fraction& z, const Fraction& y)
{
	int num = z.num* y.denom + y.num*z.denom;
	int denom = z.denom*y.denom;
	return Fraction(num,denom);
}

Fraction Fraction::multi(const Fraction& z,const Fraction& y)
{
	int num = z.num*y.num;
	int denom = z.denom*y.denom;
	return Fraction(num,denom);
}
Fraction Fraction::div(const Fraction& z,const Fraction &y)
{
	int num = z.num*y.denom;
	int denom = z.denom*y.num;
	return Fraction(num,denom);
}
				
Fraction::Fraction(int x, int y):num(x),denom(y)
{
}

void Fraction::operator+=(Fraction z)
{
	num=num*z.denom + denom*z.num;
	denom=denom*z.denom;
}
