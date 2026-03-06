#include <iostream>
#include <stack>
#include <set>

using namespace std;

int A, B, C;

class Bottles {
public:
	int a;
	int b;
	int c;

	Bottles() : a(0), b(0), c(0) {}
	Bottles(int a, int b, int c) :a(0), b(0), c(c) {}

	void Set(const Bottles& b)
	{
		Set(b.a, b.b, b.c);
	}
	void Set(int a, int b, int c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}

	void C2A()
	{
		int dif = min(A - a, c);
		a += dif; c -= dif;
	}
	
	void C2B() 
	{
		int dif = min(B - b, c);
		b += dif; c -= dif;
	}

	void A2C() 
	{
		int dif = min(C - c, a);
		c += dif; a -= dif;
	}

	void A2B()
	{
		int dif = min(B - b, a);
		b += dif; a -= dif;
	}

	void B2C()
	{
		int dif = min(C - c, b);
		c += dif; b -= dif;
	}

	void B2A()
	{
		int dif = min(A - a, b);
		a += dif; b -= dif;
	}
};

bool isVisited[201][201][201] = { false };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B >> C;

	set<int> result;
	stack<Bottles> s;
	s.push(Bottles(A, B, C));
	isVisited[A][B][C] = true;

	while (s.empty() == false)
	{
		Bottles b = s.top(); s.pop();
		if(b.a == 0)
			result.insert(b.c);

		Bottles nb(b);
		nb.C2A();
		if (isVisited[nb.a][nb.b][nb.c] == false)
		{
			isVisited[nb.a][nb.b][nb.c] = true;
			s.push(nb);
		}

		nb.Set(b); nb.C2B();
		if (isVisited[nb.a][nb.b][nb.c] == false)
		{
			isVisited[nb.a][nb.b][nb.c] = true;
			s.push(nb);
		}

		nb.Set(b); nb.B2C();
		if (isVisited[nb.a][nb.b][nb.c] == false)
		{
			isVisited[nb.a][nb.b][nb.c] = true;
			s.push(nb);
		}

		nb.Set(b); nb.A2C();
		if (isVisited[nb.a][nb.b][nb.c] == false)
		{
			isVisited[nb.a][nb.b][nb.c] = true;
			s.push(nb);
		}

		nb.Set(b); nb.A2B();
		if (isVisited[nb.a][nb.b][nb.c] == false)
		{
			isVisited[nb.a][nb.b][nb.c] = true;
			s.push(nb);
		}

		nb.Set(b); nb.B2A();
		if (isVisited[nb.a][nb.b][nb.c] == false)
		{
			isVisited[nb.a][nb.b][nb.c] = true;
			s.push(nb);
		}
	}

	for (auto iter = result.begin(); iter != result.end(); ++iter)
	{
		cout << *iter << " ";
	}

	return 0;
}