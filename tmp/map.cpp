#include <iostream>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <fstream>

using namespace std;

int main(int ac, char **av)
{
	srand(time(NULL));
	int n;
	if (ac == 1) n = rand() % 1000;
	else n = atoi(av[1]);
	cout << n << endl;
	cout << "." <<endl;
	fstream	out;
	out.open("real", ios::out | ios::trunc);
	for(int i = 0 ; i < n ; ++i)
	{
		for(int j = 0 ; j < n ; ++j)
		{
			int k = rand() % 10;
			cout << k;
			out << k;
		}
		out << endl;
		cout << endl;
	}
	out.close();
}
