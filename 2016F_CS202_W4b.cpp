#include <iostream>
using namespace std;

class B
{
public:
	B() { b=0; }
	B(int t) { b = t;}
	//B(const B& src) {}
private:
	int b;
};

class D: public B
{
public:
	D() {}
	D(const D& src) : B(src)
	{
		n = src.n;
		p = new int[n];
		for (int i=0; i<n; ++i)
			p[i] = src.p[i];
	}
	D& operator=(const D& src){
		
		// self-assignment???

		B::operator=(src);
		n = src.n;
		
		// remove the old data????
		
		p = new int[n];
		for (int i=0; i<n; ++i)
			p[i] = src.p[i];
		
		return *this;
	}
private:
	int n;
	int* p;
};

int main()
{
	D x; // (1)
	//......
	// ... b=10, n=5, p[] = {....}

	D y(x); // (2) ===> B::B(), D::copy constructor

	return 0;
}