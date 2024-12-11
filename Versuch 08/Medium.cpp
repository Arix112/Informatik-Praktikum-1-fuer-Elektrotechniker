/*!
 * Praktikum Informatik 1 
 * 
 *
 * @file Medium.cpp
 */
 
#include "Medium.h"

#include <string>
#include <iostream>

unsigned int Medium::currentID = 1;

Medium::Medium(std::string initTitel)
: titel(initTitel)
, status(false)
{
    ID = currentID++;
}

Medium::~Medium(void)
{
}

/**
 * @brief Gibt das Medium aus
 * @param std::ostream& out
 */
void Medium::ausgabe(std::ostream& out) const
{
    out << "ID: " << ID << std::endl;
    out << "Titel: " << titel << std::endl;

    if (status)
    {
        out << "Status : Das Medium ist seit dem " << datumAusgeliehen << " an " << personAusgeliehen.getName() << " ausgeliehen." << std::endl;
    }
    else
    {
        out << "Status: Medium ist zurzeit nicht verliehen." << std::endl;
    }
}
/**
 * @brief Leiht das Meidum aus
 * @param Person person, Datum ausleihdatum
 * @return bool
 */
bool Medium::ausleihen(Person person,Datum ausleihdatum)
{
    if (status)
    {
        std::cout << "Das Medium \"" << titel << "\" ist bereits verliehen!" << std::endl;
        return false;
    }
    else
    {
        status = true;
        personAusgeliehen = person;
        datumAusgeliehen = ausleihdatum;
        std::cout << "Das Medium \"" << titel << "\" wird an " << person.getName() << " verliehen." << std::endl;
        return true;
    }
}

/**
 * @brief Gibt das Medium zurück
 */
void Medium::zurueckgeben()
{
    if (status)
    {
        status = false;
        std::cout << "Das Medium \"" << titel << "\" wurde zur�ckgegeben." << std::endl;
    }
    else
    {
        std::cout << "Das Medium \"" << titel << "\" ist nicht verliehen!" << std::endl;
    }
}
/**
 * @brief Getter-Methode für ID
 */
unsigned int Medium::getID()
{
    return ID;
}
/**
 * @brief Getter_Methode für status
 */
bool Medium::getStatus()
{
	return status;
}
/**
 * @brief Überladen von Operator <<
 * @param std::ostream& out, const Medium& typMedium
 * @return std.:ostream& out
 */
std::ostream& operator <<(std::ostream& out, const Medium& typMedium)
{
	typMedium.ausgabe(out);
	return out;
}
