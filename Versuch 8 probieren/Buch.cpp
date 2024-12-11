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

void Buch::ausgabe() const
{
	Medium::ausgabe();
	std::cout << "Autor:" << this->autor.getName() << std::endl;
}

Buch::~Buch()
{

}

