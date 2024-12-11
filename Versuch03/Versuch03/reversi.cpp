/**
 * Praktikum Informatik 1 
 * 
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "reversiKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i
        std::cout <<  std::endl;
    }  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }
    // Zählt, wer mehr Steine hat
    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{
    if(posX>=0 && posY>=0 &&posX<GROESSE_X && posY<GROESSE_Y)
    {
    	return true;
    }

    return false;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return true, wenn Zug gültig. Sonst false
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1

    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++) //j=y-Achse
	{
		for (int i = -1; i <= 1; i++) //i=x-Achse
		{
			if(spielfeld[posY+j][posX+i]==gegner)
			{
				// a ist ein skalar, der die Richtung vervielfacht
				for(int a=2; aufSpielfeld(posX+a*i,posY+a*j); a++)
				{
					if(spielfeld[posY+a*j][posX+a*i]== 0)
					{
						// Wenn freies Feld da ist, dann muss abgebrochen werden
						break;
					}
					else if( spielfeld[posY+a*j][posX+a*i]==aktuellerSpieler)
					{
						// Wenn ein Stein von dem Spieler da ist, dann ist der Zug gültig
						return true;
					}
				}

			}

        }

	}
    return false;
}

/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler;

    if(spielfeld[posY][posX]!=0) // Ist das Spielfeld leer?
    {
    	return;
    }

    // Platziert den ersten Stein
    spielfeld[posY][posX]=aktuellerSpieler;

    //Alle Richtungen bearbeiten
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {

            // Da an der Stelle j=0 und i=0 durch die if-Abfrage überprüft wurde,  muss man keine weitere Überprüfung machen
            if(spielfeld[posY+j][posX+i]==gegner)
            {
            	for(int a=2; aufSpielfeld(posX+a*i,posY+a*j) ; a++)
            	{
            		if(spielfeld[posY+a*j][posX+a*i]== 0)
            		{
            			break;
            		}
            		if( spielfeld[posY+a*j][posX+a*i]==aktuellerSpieler)
					{

            			for(int b=a-1; b>0; b--) // b ist nun da, damit wir den Weg zurück gehen
            			{
            				// Wandelt Felder nun auf dem Weg um!
            				spielfeld[posY+b*j][posX+b*i]=aktuellerSpieler;
            			}
            			break;

					}
            	}
            }
        }
    }

}
/**
 * \brief Funktion, die die Anzahl möglicher Züge berechnet
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 *
 * @return anzahl: Anzahl der möglichen Züge
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    int anzahl = 0;
    //Überprüfung aller Spielfelder
    for(int j=0; j<GROESSE_Y;j++)
    {
    	for(int i=0; i<GROESSE_X;i++)
    	{
    		//Guckt, ob der Zug gültig ist an der Stelle (i,j)
    		if(zugGueltig(spielfeld, aktuellerSpieler,j,i))
    		{
    			anzahl++;
    		}
    	}
    }
    
    return anzahl;
}

/**
 * @brief Ist für die Eingabe des Zuges für den Menschen verantwortlich
 *
 * @param spielfeld[GROESSE_Y][GROESSE_X] Spielfeldeingabe
 * @param aktuellerSpieler aktueller Spieler
 *
 * @return true or false
 *
 */
bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{

    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        posX = (int) eingabe[0] % 32 -1; // Berechnug hat mit ASCII-Tabelle zu tun! -1 weil wir von 0 Zählen
        posY = (int) eingabe[1] - 49; // Wieder ASCII-Tabelle! Zahln von 1 bis 9 geht von 49-57!

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;


    return true;
}

/**
 * \brief Hauptfunktion, um Reversi zu spielen
 *
 * @param spielerTyp[2] Ein Array, welches die Daten enthält, ob es sich um Mensch oder Computer handelt
 *
 */
void spielen(const int spielerTyp[2])
{


    int spielfeld[GROESSE_Y][GROESSE_X];
    

		//Erzeuge Startaufstellung
		initialisiereSpielfeld(spielfeld);

		int aktuellerSpieler = 1;
		zeigeSpielfeld(spielfeld);

		// solange noch Zuege bei einem der beiden Spieler moeglich sind
		// Wenn kein Zug mehr möglich ist, dann wird Schleife abgebrochen und es wird der Gewinner bestimmt
		while(moeglicheZuege(spielfeld,1)>0 || moeglicheZuege(spielfeld,2)>0)
		{

			bool zugErfolgreich = false;

			// Überprüfung, ob Bot oder net
			if(spielerTyp[aktuellerSpieler-1] == COMPUTER)
			{
				zugErfolgreich = computerZug(spielfeld,aktuellerSpieler);
			}
			else
			{
				zugErfolgreich = menschlicherZug(spielfeld,aktuellerSpieler);
			}

			if(zugErfolgreich)
			{
				zeigeSpielfeld(spielfeld);
			}
			else
			{
				std::cout << "Spieler" << aktuellerSpieler << " kann keinen Zug ausführen" << std::endl;
			}

			// Wechsel der Spieler
			aktuellerSpieler = 3-aktuellerSpieler;

		}

		switch (gewinner(spielfeld))
		{
			case 0: std::cout << "Unentschieden!" << std::endl; break;
			case 1: std::cout << "Spieler 1 hat gewonnen!" << std::endl; break;
			case 2: std::cout << "Spieler 2 hat gewonnen!" << std::endl; break;
		}

}

int main()
{
	int benutzerEingabe;

	int weiterSpielen=0;

    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl << std::endl;
    }
    



    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
//    int spielfeld[GROESSE_Y][GROESSE_X];
//
//    initialisiereSpielfeld(spielfeld);
//
//    zeigeSpielfeld(spielfeld);

    // int spielerTyp[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
    // spielen(spielerTyp);
    //


    do
    {
    	std::cout << "Wollen Sie einzelnd oder zusammen spielen?" << std::endl;
		std::cout << "1:= Mensch vs. Computer, 2:= Mensch vs. Mensch , 3:= Computer vs. Computer" << std::endl;
		std::cin >> benutzerEingabe;

    	if(benutzerEingabe == 1)
    	    {
    	    	int spielerTyp[2] = {MENSCH,COMPUTER};
    			spielen(spielerTyp);
    			std::cout << "Wollen Sie nochmal spielen? (0:= Nein, 1:= Ja )" << std::endl;
    			std::cin >> weiterSpielen;
    	    }
		else if(benutzerEingabe == 2)
    	    {
    	    	int spielerTyp[2] = {MENSCH,MENSCH};
    	    	spielen(spielerTyp);
    	    	std::cout << "Wollen Sie nochmal spielen? (0:= Nein, 1:= Ja )" << std::endl;
				std::cin >> weiterSpielen;
    	    }
		else if(benutzerEingabe == 3)
    	    {
    	    	int spielerTyp[2] = {COMPUTER,COMPUTER};
    	    	spielen(spielerTyp);
    	    	std::cout << "Wollen Sie nochmal spielen? (0:= Nein, 1:= Ja )" << std::endl;
				std::cin >> weiterSpielen;
    	    }


    }while(weiterSpielen==1);



    return 0;
}
