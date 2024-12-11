///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

string verschluesseln(char schluessel[2][26], string wort)
{

	// Iteration durch das Wort

	for(int i=0;i<wort.length(); i++) // Iteration durch das Wort
	{
		for(int j=0;j<27;j++) // Iteration durch das Array
		{
			if(wort[i]==schluessel[0][j]) // Vergleich ob Zeichen gleich sind
			{
				wort[i]=schluessel[1][j]; // Wenn gleich, dann mit Verschlüsselung ersetzen
				break;
			}
		}
	}

	return wort;
}

string entschluesseln(char schluessel[2][26], string wort)
{

	// Iteration mit Pointer

	char *p=&wort[0];

	for(int i=0;i<wort.length();i++)
	{
		for(int j=0;j<27;j++)
		{
			if(*p==schluessel[1][j]) // Vergleich, ob Zeichen gleich sind
			{
				wort[i]=schluessel[0][j];;  // Wenn gleich, dann mit Entschlüsselung ersetzen
				break;
			}
		}

		p++;

	}

	return wort;
}

int main()
{

	string user1;
	string user2;

	char array[2][26]={
					  {'A','B','C','D','E','F','G','H',
					   'I','J','K','L','M','N','O','P',
					   'Q','R','S','T','U','V','W','X',
					   'Y','Z'},
					  {'D','B','I','J','Q','L','O','A',
					   'U','V','S','C','F','N','M','Y',
					   'Z','E','G','R','K','P','H','X',
					   'W','V'}
					  };

	cout << "Geben Sie ein Wort nur in Großbuchstaben an:";
	cin >> user1;
	cout << "Ihr Wort vor der Verschlüsselung:" << user1 << endl;
	cout << "Ihr Wort nach der Verschlüsselung:" << verschluesseln(array,user1) << endl;
	cout << endl;
	cout << "Geben Sie nun ein verschlüsseltes Wort ein und wir versuchen es, zu entschlüsseln.\n"
			"Auch wieder nur in Großbuchstaben:" << endl;
	cin >> user2;
	cout << "Ihr Wort wurde entschlüsselt:" << entschluesseln(array,user2) << endl;





	return 0;
}
