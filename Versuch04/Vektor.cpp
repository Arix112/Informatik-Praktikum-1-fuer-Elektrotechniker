//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"


Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}
/**
 * @brief Gibt Länge vom Vektor
 *
 * @return double laenge
 */
double Vektor::laenge() const
{
	return sqrt(x*x + y*y + z*z);
}
/**
 * @brief Skalarprodukt von input und betrachtetem Vektor
 * @param input Input Vektor
 * @return double Skalarprodukt
 */
double Vektor::skalarProd(const Vektor& input) const
{
	return (x*input.x+y*input.y+z*input.z);
}
/**
 * @brief Winkel zwischen zwei Vektoren
 * @param input Input Vektor
 * @return double Winkel
 */
double Vektor::winkel(const Vektor& input) const
{

	return (acos(Vektor::skalarProd(input)/(laenge()*input.laenge()))*180/PI);
}
/**
 * @brief Differenz von zwei Vektoren
 * @param input Input Vektor
 * @return Vektor neuer Vektor
 */
Vektor Vektor::sub(const Vektor& input) const
{
	return Vektor(this->x-input.x,this->y-input.y,this->z-input.z);
}
/**
 * @brief Rotiere um Achse
 * @param const double rad Radiant
 */
void Vektor::rotiereUmZ(const double rad)
{
	double newx=x*cos(rad)+y*sin(rad);
	double newy=-x*sin(rad)+y*cos(rad);
	this->x=newx;
	this->y=newy;
}
