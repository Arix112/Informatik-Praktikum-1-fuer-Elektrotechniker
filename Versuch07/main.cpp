
/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include <vector>
#include "Student.h"

std::ostream& operator <<(std::ostream& out, Student& student)
{

	student.ausgabe(out);

	return out;
}



int main()
{
    std::vector<Student> liste;
    Student student;

    int abfrage;
    std::string dateiname;
    std::string olddateiname;

    unsigned int matNr;
	std::string name;
	std::string geburtstag;
	std::string adresse;

    {

		std::cout << "Bitte geben Sie eine Datei an, um die Datenbank zu füllen" << std::endl;

		std::cin >> dateiname;
		std::ifstream eingabe(dateiname);

		if(!eingabe)
		{
			std::cout << "Die Datei konnte nicht geoeffnet werden" << std::endl;
		}
		else
		{
			while(!eingabe.eof())
			{
				matNr = 0;
				name="";
				geburtstag = "";
				adresse = "";

				eingabe >> matNr;
				eingabe.ignore(1,'\n');
				std::getline(eingabe,name);
				std::getline(eingabe,geburtstag);
				std::getline(eingabe,adresse);

				if(matNr == 0 || name == "" || geburtstag == "" || adresse == "")
				{
					std::cout << std::endl;
					std::cout << "Die Liste wurde vollständig gefüllt" << std::endl;
					break;
				}

				student = Student(matNr,name,geburtstag,adresse);

				liste.push_back(student);

				olddateiname=dateiname;
			}
		}

    }


    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(01): Datenelement hinten hinzufuegen" << std::endl
                  << "(02): Datenelement vorne entfernen" << std::endl
                  << "(03): Datenbank vorwaerts ausgeben" << std::endl
				  << "(04): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
				  << "(05): Datenelement löschen" << std::endl
				  << "(06): Datenelement vorne hinzufuegen" << std::endl
				  << "(07): Datenelement hinten löschen" << std::endl
				  << "(08): Daten aus einer Datei einlesen" << std::endl
				  << "(09): Daten in Datei sicher" << std::endl
				  << "(10): Sortieren der Daten" << std::endl
                  << " (0): Beenden" << std::endl;

//        std::cin.clear();
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case 1:
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    liste.push_back(student);
                }
                break;

            // Datenelement vorne entfernen
            case 2:
                {
                    if(!liste.empty())
                    {
                        student = liste.front();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        std::cout << student << std::endl;
                        liste.erase(liste.begin());
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case 3:
                if(!liste.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    for(std::vector<Student>::const_iterator it = liste.cbegin(); it !=liste.cend(); ++it)
                    {
                    	it->ausgabe(std::cout);
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;

            // Datenbank rueckwaerts ausgeben
            case 4:
            	if(!liste.empty())
            	{
            		std::cout << "Inhalt der Liste in ruecklaufender Reihenfolge:" << std::endl;
            		for(std::vector<Student>::const_reverse_iterator rit = liste.crbegin(); rit!=liste.crend(); ++rit)
            		{
            			rit->ausgabe(std::cout);
            		}
            	}
            	else
            	{
            		std::cout << "Die Liste ist leer!\n\n";
            	}
            	break;
//
//            // Datenelement löschen
            case 5:
				if(!liste.empty())
				{
					std::vector<Student>::iterator it;
					unsigned int matNr;

					std::cout << "Geben Sie die zu löschende Matrikelnummer ein:" << std::endl;
					std::cin >> matNr;
					Student student = Student(matNr, "", "", "");

					it=find(liste.begin(), liste.end(), student);

					if(it!=liste.end())
					{
						liste.erase(it);
						std::cout << "Löschprozess successful" << std::endl;
					}
					else
					{
						std::cout << "Mat. Nummer wurde nicht gefunden!" << std::endl;
					}
				}
				else
				{
					std::cout << "Die Liste ist leer!";
				}
            	break;

           // Datenelement vorne hinzufügen
            case 6:
            	{
            		unsigned int matNr = 0;
					std::string name = "";
					std::string geburtstag = "";
					std::string adresse = "";

					std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
					getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

					std::cout << "Geburtsdatum: ";
					getline(std::cin, geburtstag);

					std::cout << "Adresse: ";
					getline(std::cin, adresse);

					std::cout << "Matrikelnummer: ";
					std::cin >> matNr;
					std::cin.ignore(10, '\n');

					student = Student(matNr, name, geburtstag, adresse);

					liste.insert(liste.begin(), student);
            	}
            	break;

            // Datenelement hinten löschen
            case 7:
            	{
            		if(!liste.empty())
            		{
            			student = liste.back();
            			std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
            			std::cout << student << std::endl;
            			liste.pop_back();
            		}
            		else
            		{
            			std::cout << "Die Liste ist leer!" << std::endl;
            		}
            	}
            	break;

            //Daten einlesen
            case 8:
            	{

            		// Sachen für stream
            		std::string dateiname;
            		std::cout << "Bitte geben Sie den Dateinamen ein:" << std::endl;
            		std::cin >> dateiname;

            		if(olddateiname == dateiname)
            		{
            			std::cout << "Bitte geben Sie nicht die gleiche Datei an!" << std::endl;
            			break;
            		}

            		std::ifstream eingabe(dateiname);

            		if(!eingabe)
            		{
            			std::cout << "Die Datei konnte nicht geoeffnet werden" << std::endl;
            			break;
            		}

            		while(!eingabe.eof())
            		{
            			matNr = 0;
            			name="";
            			geburtstag = "";
            			adresse = "";

            			eingabe >> matNr;
            			eingabe.ignore(1,'\n');
            			std::getline(eingabe,name);
            			std::getline(eingabe,geburtstag);
            			std::getline(eingabe,adresse);

            			if(matNr == 0 || name == "" || geburtstag == "" || adresse == "")
            			{
            				std::cout << std::endl;
            				std::cout << "Die Liste wurde vollständig gefüllt" << std::endl;
            				break;
            			}

            			student = Student(matNr,name,geburtstag,adresse);

            			liste.push_back(student);
            		}
            	}

            	break;

            //Daten speichern
            case 9:
            	{

            		std::string dateiname;

            		std::cout << "In welcher Datei wollen Sie die Daten speichern" << std::endl;
            		std::cin >> dateiname;

					std::ofstream ausgabe;

					ausgabe.open(dateiname);

					for(std::vector<Student>::iterator it = liste.begin(); it!=liste.end(); it++)
					{
//						ausgabe << it->getMatNr() << std::endl;
//						ausgabe << it->getName() << std::endl;
//						ausgabe << it->getGeburtstag() << std::endl;
//						ausgabe << it->getAdresse() << std::endl;
						//Genau das gleiche!
						it->ausgabe(ausgabe);
					}

					ausgabe.close();

					std::cout << "Ihre Daten wurden erfolgreich in die Datei " << dateiname <<  " gespeichert!" << std::endl;

					break;

				}

            //Daten sortieren
            case 10:
            {
            		if(liste.empty())
            		{
            			std::cout << "Die Liste ist leer!" << std::endl;
            		}
            		else
            		{
            			char abfrage;
            			std::sort(liste.begin(), liste.end());
            			std::cout << "Die Liste wurde erfolgreich sortiert!" << std::endl
            					  << "Soll die Liste ausgegeben werden? (j/n)" << std::endl;
            			std::cin >> abfrage;

            			if(abfrage == 'j')
            			{
            				std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
							for(std::vector<Student>::const_iterator it = liste.cbegin(); it !=liste.cend(); ++it)
							{
								it->ausgabe(std::cout);
							}
            			}

            		}

            }
            break;

            case 0:
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
