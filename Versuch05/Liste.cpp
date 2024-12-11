 //////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */



Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);
    if(front == nullptr) // Wenn Liste leer ist
    {
    	front=neuesElement;
    	back=neuesElement;
    }
    else
    {
    	neuesElement->setPrev(back);
    	back->setNext(neuesElement);
    	back=neuesElement;
    }

}
/**
 * @brief Fügt ein Element ganz am Anfang hinzu
 *
 * @param Student mit Daten
 * @return void
 */
void Liste::pushFront(Student pData)
{
	ListenElement *neuesElement = new ListenElement(pData, nullptr,nullptr);

	if(front == nullptr) // Wenn Liste leer ist
	{
		front=neuesElement;
		back=neuesElement;
	}
	else
	{
		neuesElement->setNext(front);
		front->setPrev(neuesElement);
		front = neuesElement;
	}
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{

	ListenElement* cursor = front;

    if(front == back) // Liste hat nur einen Eintrag
    {
    	delete front; 	// Listenelement löschen
    	front = nullptr;
    	back = nullptr;
    }
    else
    {
    	front = front->getNext();
    	front->setPrev(nullptr);
    	delete cursor;
    }

}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}
/*
 * @brief Gibt die Liste rueckwärts aus
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
	ListenElement* cursor = back;

	while (cursor != nullptr)
	{
		cursor->getData().ausgabe();
		cursor = cursor->getPrev();
	}
}
/*
 * @brief Löscht die Liste je nach MatNr.
 *
 * @param matNr Matrikelnummer
 */
bool Liste::loeschen(unsigned int matNr)
{
	ListenElement* cursor=front;

	while(cursor->getData().getMatNr()!= matNr) // Suche nach der jeweiligen Nummer
	{

		cursor = cursor->getNext(); // Setze Pointer auf das nächste Element
		if(cursor == nullptr)
		{
			return false;
		}

	}

	if(front == back) // Liste enthält nur einen Eintrag
	{
		front = nullptr;
		back = nullptr;
	}
	else if(cursor == front) // Gesuchte Mat. Nummer ist am Anfang
	{
		front = cursor->getNext();
		cursor->getNext()->setPrev(cursor->getPrev());

	}
	else if(cursor == back) // Gesuchte Mat. Nummer ist am Ende
	{
		back = cursor->getPrev();
		cursor->getPrev()->setNext(cursor->getNext());
	}
	else // Gesuchte Mat. Nummer ist random in der Liste
	{
		cursor->getNext()->setPrev(cursor->getPrev());
		cursor->getPrev()->setNext(cursor->getNext());
	}

	delete cursor;
	return true;
}


