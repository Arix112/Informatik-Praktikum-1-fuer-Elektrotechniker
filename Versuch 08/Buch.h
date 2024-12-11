/*
 * Buch.h
 *
 *  Created on: 30.06.2024
 *      Author: arian
 */

#ifndef BUCH_H_
#define BUCH_H_

#include "Medium.h"
#include <string>

class Buch: public Medium
{
public:
	Buch(std::string initTitel, std::string initAutor);
	virtual ~Buch();
	void ausgabe(std::ostream& out) const;
	bool ausleihen(Person person, Datum ausleihdatum);


private:
	Person autor;

};

#endif /* BUCH_H_ */
