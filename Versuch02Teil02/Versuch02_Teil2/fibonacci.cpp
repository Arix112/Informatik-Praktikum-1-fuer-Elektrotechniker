//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

int fibonacci(int n)
{
    int previousFib = 0; // Wert muss bei 0 starten!
    int currentFib = 1;
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    if(n == 2) // Bedingung muss auch exisiteren, damit Reihe stimmt!
    {
    	return 1;
    }
    for (int i = 0; i < n-1; i++) // Abbruchbedingung muss n-1 sein, da wir 2 mal den Fall = 1 haben!
    {
    	// Falsche Zuweisungen wurden hier vorgenommen!
        int newFib = previousFib + currentFib ;
        previousFib = currentFib ;
        currentFib = newFib ;
    }
    return currentFib ;
}

int main ()
{
    std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl ;
    for (int i = 0; i <= 12 ; i ++) // Wenn i=1 ist, dann wird f(0) nie = 0 sein!
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }
    return 0;
}
	// Bei i<=47 ensteht ein "int overflow". Das bedeutet, dass der Wertebereich für int überschritten wird und nun wieder von 0 angefangen wird, zu zählen!
	// Iterative Implementierung ist schneller, da man nur Rechnen muss. Bei Rekursion muss man auch jede einzelne Funktion aufrufen!
