/*
 * Magazin.h
 *
 *  Created on: 30.06.2024
 *      Author: arian
 */

#ifndef MAGAZIN_H_
#define MAGAZIN_H_

#include "Medium.h"

class Magazin: public Medium
{
public:
	Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
	virtual ~Magazin();

	void ausgabe(std::ostream& out) const;
	bool ausleihen(Person person, Datum ausleihdatum);

private:
	Datum erscheinungsdatum;
	std::string sparte;
};

#endif /* MAGAZIN_H_ */
