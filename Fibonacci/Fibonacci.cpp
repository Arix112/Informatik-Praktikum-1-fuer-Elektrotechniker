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

int recursivFibo1(int n);
int recursivFibo2(int n);

int main()
{
	int user;
	int n;
	int m;

	// 1: Fibo2 2:Fibo2
	cout << "Wollen Sie die Fibonacci-Reihe komplett ausgeben lassen?\n"
			"Beantworten Sie diese Frage mit 0:=Nein oder 1:=Ja:";
	cin >> user;

	if(user==0)
	{
		cout << "Geben Sie eine Zahl an:" << endl ;
		cin >> n;
		cout << "Fib(" << n << ")=" << recursivFibo1(n);
	}
	else if(user==1)
	{
		cout << "Bis zur welcher Zahl wollen Sie ausgeben?:" << endl;
		cin >> m;
		cout << recursivFibo2(m);
	}

	return 0 ;
}
/**
 * @brief Fibonacci Folge
 * @param int n Fibonacci-Zahl an der Stelle n
 * @return int Fibonacci-Zahl
 */
int recursivFibo1(int n)
{
	if(n==0)
	{
		return 0;
	}
	else if(n < 3)
	{
		return 1;
	}

	return recursivFibo1(n-1)+recursivFibo1(n-2);
}
/**
 * @brief Fibonacci-Reihe, aber mit nur einem input
 * @param int n Fibonacci-Zahl an der Stelle n
 * @param array[2] Ein Array mit zwei Einträgen
 *
 * @return int Fibonacci-Zahl
 */
int recursivFibo2(int n, int array[2])
{

	 if(array==NULL) // Im ersten Durchlauf ist dass array immer leer
	 {
		if(n==0) return 0; // Sonderfälle für n
		cout << '0' << endl;
		if(n==1) return 1;
		cout << '1' << endl;
		n-=1;

		// Speicher wird reserviert, um die letzten beiden Zahlenwerte zu speichern.
		array=(int*)malloc(sizeof(int)*2);
		array[0]=0;
		array[1]=1;
	 }

	int sum= array[0]+array[1]; // Speichern der letzten beiden Zahlen in sum, um die später auszugeben
    n-=1;

	if(n==0)
	{
		free(array); // Speicher wird wieder freigegeben
		return sum;
	}

	array[0]=array[1];
	array[1]=sum;

	cout << sum << endl;

	return recursivFibo2(n, array);

}
int recursivFibo2(int n) // Ermöglicht den Aufruf nur mit einem Parameter
{
	return recursivFibo2(n, NULL);
}

