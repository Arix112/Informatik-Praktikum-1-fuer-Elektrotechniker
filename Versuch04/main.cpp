//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <iomanip>
#define ERDRADIUS 6371
#define MENSCH_GROESSE 1.7
#define TOWER_HOEHE 555.7


using std::cout;
using std::endl;


int main()
{
//    Vektor vector1(1, 0, 0);
//    Vektor vector2(0, 1, 0);
//
//    vector1.ausgabe();
//    vector2.ausgabe();
//
//    cout << "Länge der Vektoren V_1(1,0,0) und V_2(0,1,0):" << endl;
//    cout << vector1.laenge() << endl;
//    cout << vector2.laenge() << endl << endl;
//
//    Vektor vecsca1(1,0,2);
//	Vektor vecsca2(-2,0,1);
//
//	cout << "Skalarprodukt von V_1(1,0,2) und V_2(-2,0,1):" << endl;
//	cout << vecsca1.skalarProd(vecsca2) << endl;
//
//	Vektor vecwin1(0,1,0);
//	Vektor vecwin2(1,0,0);
//
//	cout << "Winkel zwischen V_1(0,1,0) und V_2(1,0,0):" << endl;
//	cout << vecwin1.winkel(vecwin2) << endl;
//
//	cout << "Subtraktion von V_1(1,0,0) mit V_2(0,1,0):" << endl << endl;
//	(vector1.sub(vector2)).ausgabe();
//	cout << endl;
//
//	Vektor vecrot(1,0,1);
//
//	cout << "Rotiere Vektor um z-Achse:" << endl;
//	(vecrot.rotiereUmZ(3));
//	vecrot.ausgabe();

	// Geguckt, ob Funktionen funktionieren

	/*------------------------------------------------------------------------------------*/

	double rad;
	int i=0;

	Vektor human(0, (((TOWER_HOEHE + MENSCH_GROESSE)/1000)+ERDRADIUS), 0);
	Vektor earth(0,ERDRADIUS,0);
	Vektor distance = human.sub(earth);
	rad =  pow(10, -8);

	while(earth.skalarProd(distance)>0.01 || earth.skalarProd(distance) <-0.01)
	{
		earth.rotiereUmZ(rad);
		distance = human.sub(earth);
		i++;
	}

	double distanceNumber = distance.laenge();
	double winkel = human.winkel(earth);

	std::cout << "Der Horizont ist nach " << distanceNumber << " nicht mehr zu erkennen." << std:: fixed << std::endl;
	std::cout << "Sie sind " << (TOWER_HOEHE + MENSCH_GROESSE) << " km hoch "  << std::endl;
	std::cout << "Der Winkel betraegt " << std::setprecision(4) << winkel << "°" << std::endl;
	std::cout << "Anzahl der Schritte:" << i << std::endl;

	/*------------------------------------------------------------------------------------*/

//	// andere Implementierung
//
//	Vektor human(0, (((TOWER_HOEHE + MENSCH_GROESSE)/1000)+ERDRADIUS), 0);
//	Vektor earth(0,ERDRADIUS,0);
//	Vektor distance = human.sub(earth);
//
//
//	double rad=0;
//	int i=0;
//	double scalar=0.1;
//	double schrittweite = PI/2;
//
//
//	while((scalar>0.001) || (scalar <-0.001))
//	{
//		rad += scalar  < 0 ? -schrittweite : schrittweite;
//		earth = Vektor(0,ERDRADIUS,0);
//		earth.rotiereUmZ(rad);
//		scalar = earth.skalarProd(human.sub(earth));
//		distance = human.sub(earth);
//		schrittweite /= 2;
//		i++;
//	}
//
//	double distanceNumber = distance.laenge();
//	double winkel = human.winkel(earth);
//
//	std::cout << "Der Horizont ist nach " << distanceNumber << " nicht mehr zu erkennen." << std:: fixed << std::endl;
//	std::cout << "Sie sind " << (TOWER_HOEHE + MENSCH_GROESSE) << " km hoch "  << std::endl;
//	std::cout << "Der Winkel betraegt " << std::setprecision(4) << winkel << "°" << std::endl;
//	std::cout << "Anzahl der Schritte:" << i << std::endl;


    return 0;

}
