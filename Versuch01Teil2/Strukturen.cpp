/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int main()
{

	struct Person
	{
		string sVorname, sNachname;
		int iGeburtsjahr, iAlter;
	};



	Person nBenutzer;

	cout << "Geben Sie ihre Daten an:" << endl;
	cout << "Name:";
	cin >> nBenutzer.sVorname >> nBenutzer.sNachname;
	cout << "Geburtsjahr:";
	cin >> nBenutzer.iGeburtsjahr;
	cout << "Alter:";
	cin >> nBenutzer.iAlter;
	cout << endl;
	cout << "Name:" << nBenutzer.sVorname + ' ' + nBenutzer.sNachname << endl << "Alter:" << nBenutzer.iAlter << endl
		 << "Geburtsjahr:" << nBenutzer.iGeburtsjahr << endl;

	//Einzeln Speichern

	Person nKopieEinzeln;

	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;

	//Gesamt Speichern

//	Person nKopieEinzeln = nBenutzer;

	cout << endl;
	cout << nKopieEinzeln.sVorname + ' ' + nKopieEinzeln.sNachname << endl;
	cout << nKopieEinzeln.iAlter << endl;
	cout << nKopieEinzeln.iGeburtsjahr;


    return 0;
    
}
