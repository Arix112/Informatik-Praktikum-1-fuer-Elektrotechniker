/*
 * Fibonacci.cpp
 *
 *  Created on: 16.04.2024
 *      Author: arian
 */

#include <iostream>


using std::cout;
using std::endl;
using std::cin;

int recursivFibo1(unsigned int x); //(Fibonacci-Folge)
int recursivFibo2(int c, int p, int q, int sum);

int main()
{
//	int n;
//	cout << "Wollen Sie die Fibonacci-Reihe komplett ausgeben lassen?";
//	cout << "Geben Sie eine Zahl an:" << endl ;
//	cin >> n;
//	cout << "Fib(" << n << ")=" << recursivFibo1(n);
//	cout<<"0 \n1"<<endl;
	recursivFibo2(4, 0, 1, 1);

	return 0;
}

int recursivFibo1(unsigned int a)
{
	if(a==0)
	{
		return 0;
	}
	else if(a < 3)
	{
		return 1;
	}

	return recursivFibo1(a-1)+recursivFibo1(a-2);
}
int recursivFibo2(int c, int p, int q, int sum)
{


	sum = p +q;
	p = q;
	q = sum;

	cout << sum << endl;

	if(c==0)
	{
		return 0;
	}

	recursivFibo2(c-1,p,q,sum);


	return 0;

}
