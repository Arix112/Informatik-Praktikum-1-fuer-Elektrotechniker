//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;


int main()
{
//    int iErste;
//    int iZweite;
//
//    cout << "Geben Sie zwei ganze Zahlen an:" << endl;
//    cin >> iErste >> iZweite;
//
//    int iSumme = iErste + iZweite; // Ergebnis als Int
//    int iQuotient =iErste/iZweite; // Ergebnis typecast in
//
//    double dSumme=iErste + iZweite; // Beide Ergebnisse als double
//    double dQuotient=iErste/iZweite; // Integer Divison returns int
//
//    double dSummeCast=iErste+iZweite;
//    double dQuotientCast=(double)iErste/(double)iZweite;
//
//    cout << "Summe(int):" << iSumme << endl;
//    cout << "Quotient(int):" << iQuotient << endl;
//
//
//    cout << "Summe(double):" << dSumme << endl;
//    cout << "Quotient(double):" << dQuotient << endl;
//
//    cout << "Summe(gecastet double):" << dSummeCast << endl;
//    cout << "Quotient(gecastet double):" << dQuotientCast << endl;

    /*---------------------------------------------------------------------*/

    string sVorname,sNachname;


    cout << "Geben Sie nun ihren Vor- und Nachnamen an:" << endl;
    cin >> sVorname >> sNachname;

    string sVornameName = sVorname + ' ' + sNachname;
    string sNameVorname = sNachname+ ',' + sVorname;

    cout << "Ausgabe: sVornameName:" << sVornameName << endl;
    cout << "Ausgabe: sNameVorname:" << sNameVorname<< endl;

    /*---------------------------------------------------------------------*/

    cout << "Wir definieren intern nun ein Array:" << endl; // Aufgabe 5a.)
    {
    	int iFeld[2]={1,2};
    	for(int i = 0; i<2; i++)
    	{
    		cout << iFeld[i] << endl;
    	}

    }
    cout << "Wir definieren nun ein anderes Array:" << endl; // Aufgabe 5b.)
    {
    	int spielfeld[2][3]={{1,2,3},{4,5,6}}; //spielfeld[Zeile][Spalte]
    	for(int i=0; i<2; i++) // Für Zeile
    	{
    		for(int j=0; j<3; j++) // Für Spalte
    		{
    			cout << spielfeld[i][j];
    			cout << ' ';
    		}

    		cout << endl;

    	}
    }
    cout << "Wir definieren nun eine Konstante:" << endl; // Aufgabe 5c.)
    {
    	int iZweite = 1;
    	cout << iZweite << endl;
    }
    /*cout << iZweite << endl;*/ //Geht nicht, da iZweite nur im Block gültig ist

    /*----------------------------------------------------------------------*/

//    cout << "Geben Sie ihren Vornamen an:"<< endl;
//
//    string sVorname;
//    int iName1;
//    int iName2;
//
//    cin >> sVorname;
//
//    iName1=sVorname[0];
//    iName2=sVorname[1];
//
//    cout << "Ausgabe:" << iName1 << ' ' << iName2 << endl;
//
//    int Position1;
//    int Position2;
//
//    // Trennelement a: 97
//
//    if(iName1>= 64 && iName1 < 97)
//    {
//    	Position1=iName1%64;
//    }
//    else
//    {
//    	Position1=(iName1%64)-32;
//    }
//
//    if(iName2>= 64 && iName2 < 97)
//	{
//		Position2=iName2%64;
//	}
//	else
//	{
//		Position2=(iName2%64)-32;
//	}
//
//    cout << "Die Position der ersten beiden Buchstaben des Vornamens sind:" << Position1<<" "<< Position2;


    return 0;
    
}
