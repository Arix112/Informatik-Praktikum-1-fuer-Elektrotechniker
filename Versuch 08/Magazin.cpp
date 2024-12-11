/*
 * Magazin.cpp
 *
 *  Created on: 30.06.2024
 *      Author: arian
 */

#include "Magazin.h"

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte):
			Medium(initTitel),erscheinungsdatum(initDatumAusgabe), sparte(initSparte)
{


}
/**
 * @brief Gibt das Magazin aus
 * @param std::ostream& out
 */
void Magazin::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out);

	out << "Ausgabe: " << this->erscheinungsdatum << std::endl
		<< "Sparte: "  << this->sparte << std::endl;
}
/**
 * @brief Ist ausleihen möglich oder net
 * @param Person person, Datum ausleihdatum
 * @bool true =
 */
bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
	if((ausleihdatum - this->erscheinungsdatum) <=0)
	{
		std::cout << "Die neueste Ausgabe von Magazinen darf nicht ausgeliehen werden." << std::endl;
		return false;
	}
	else
	{
		return Medium::ausleihen(person, ausleihdatum);
	}
}

Magazin::~Magazin()
{

}

