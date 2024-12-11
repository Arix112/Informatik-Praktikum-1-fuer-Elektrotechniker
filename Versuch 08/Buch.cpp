/*
 * Buch.cpp
 *
 *  Created on: 30.06.2024
 *      Author: arian
 */

#include "Buch.h"

Buch::Buch(std::string initTitel, std::string initAutor): Medium(initTitel), autor(Person(initAutor, Datum()))
{


}

/**
 * @brief Gibt die Bücher aus
 * @param std::ostream& out
 */
void Buch::ausgabe(std::ostream& out) const
{
	Medium::ausgabe(out);
	out << "Autor: " << this->autor.getName() << std::endl;
}
/**
 * @brief Leiht die Bücher aus
 * @param Person person, Datum ausleihdatum
 */
bool Buch::ausleihen(Person person, Datum ausleihdatum)
{
	return Medium::ausleihen(person, ausleihdatum);
}


Buch::~Buch()
{

}

