/*
 * DVD.h
 *
 *  Created on: 30.06.2024
 *      Author: arian
 */

#ifndef DVD_H_
#define DVD_H_

#include "Medium.h"

class DVD: public Medium
{
public:
	DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
	virtual ~DVD();

	void ausgabe(std::ostream& out) const;
	bool ausleihen(Person person, Datum ausleihdatum);

private:
	int altersfreigabe;
	std::string genre;

};

#endif /* DVD_H_ */
