/*
 * DVD.cpp
 *
 *  Created on: 30.06.2024
 *      Author: arian
 */

#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre):
		Medium(initTitel), altersfreigabe(initAltersfreigabe), genre(initGenre)
{


}
/**
 * @brief Ausgabe von DVD
 * @param std::ostream& out
 */
void DVD::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out);
	out << "FSK: ab " << this->altersfreigabe << " Jahre" << std::endl
		<< "Genre: " << this->genre << std::endl;
}
/**
 * @brief Ausleihen von DVDs
 * @param Person person, Datum ausleihdatum
 * @return true = Medium, welches ausgeliehen wird
 */
bool DVD::ausleihen(Person person, Datum ausleihdatum)
{

	if((ausleihdatum - person.getGeburtsdatum()) < (altersfreigabe * 12))
	{
		std::cout << "Sie dürfen leider die DVD aufgrund der FSK nicht ausleihen!" << std::endl;
						return false;
	}
	else
	{
		return Medium::ausleihen(person, ausleihdatum);
	}
}

DVD::~DVD()
{

}

