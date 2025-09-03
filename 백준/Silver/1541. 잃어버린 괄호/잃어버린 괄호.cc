#include <iostream>
#include <string>

using namespace std;

string equation;

string inline GetSubStr(string e, size_t start, size_t end) {
	return e.substr(start, (end == -1) ? e.size() - start : end - start);
}

int GetSum(string e)
{
	int sum = 0;
	size_t start = 0;
	size_t end = 0;
	do {
		end = e.find('+', start);
		sum += stoi(GetSubStr(e, start, end));
		start = end + 1;
	} while (end != -1);

	return sum;
}

int main()
{
	cin >> equation;

	size_t start = 0;
	size_t end = equation.find('-');

	int answer = GetSum(GetSubStr(equation, start, end));
	if (end == -1)
	{
		cout << answer;
		return 0;
	}

	start = end + 1;
	do {
		end = equation.find('-', start);
		answer -= GetSum(GetSubStr(equation, start, end));
		start = end + 1;
	} while (end != -1);

	cout << answer;

	return 0;
}