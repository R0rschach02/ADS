/*
 * Blatt2A1.cpp
 *
 *  Created on: 29.04.2024
 *      Author: swt
 */

#include <iostream>
using namespace std;
#include "pbma.h"
#include <vector>
#include <cstdlib>
#include <bitset>
#include <map>

vector <string> lexikon = { "Adler", "Ameise", "Wolf" };

void inspectwords(vector<string> woerter)
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int anzAlphabet[26] = {0}; // Array initialisieren

    // Wörter Anzahl:
    int anzWoerter = woerter.size();
    cout << "Anzahl der Wörter: " << anzWoerter << " \n" << endl;

    // Wie viele Buchstaben insgesamt:
    size_t letterNum = 0; // Buchstaben Anzahl

    string longWord, shortWord;

    size_t longWordSize = 0, shortWordSize = 0;

    // Initialisiere das kürzeste Wort mit dem ersten Wort
    if (anzWoerter > 0) {
        shortWord = woerter[0];
        shortWordSize = shortWord.length();
    }

    for (size_t wort = 0; wort < woerter.size(); wort++) // alle Wörter iterieren
    {
        string swort = woerter[wort]; // speicher das aktuelle Wort im string swort

        letterNum += swort.length(); // summiere mittels der Länge des aktuellen Wortes auf

        if (swort.length() > longWordSize)
        {
            longWord = swort;
            longWordSize = longWord.length();
        }

        if (swort.length() < shortWordSize)
        {
            shortWord = swort;
            shortWordSize = shortWord.length();
        }
    }

    // Alle Zeichen A-Z:
    for (size_t i = 0; i < alphabet.size(); ++i){
        char buchstabe = alphabet[i]; // momentanen Buchstaben aus Alphabet bereithalten für Vergleich

        for (size_t j = 0; j < woerter.size(); ++j){
            string wort = woerter[j]; // aktuelles Wort bereithalten für Vergleich

            if (wort.length() > 0) {
                char ersterBuchstabe = wort[0];
                if (ersterBuchstabe == buchstabe || (ersterBuchstabe >= 'a' && ersterBuchstabe <= 'z' && (ersterBuchstabe - 'a' + 'A') == buchstabe)) {
                    anzAlphabet[buchstabe - 'A']++;
                }
            }
        }
    }

    cout << "Anzahl der Buchstaben: " << letterNum << " \n" << endl;
    cout << "Längstes Wort: " << longWord << " | " << longWordSize << " \n" << endl;
    cout << "Kürzestes Wort: " << shortWord << " | " << shortWordSize << " \n" << endl;

    for (size_t i = 0; i < alphabet.size(); i++)
    {
        cout << alphabet[i] << ": " << anzAlphabet[i] << endl;
    }
}





int main (int argc, const char *argv[])
{
	string filename = argv[2];
	vector <string> datei = read_words(filename); // vektor trennt automatisch wörter ab!

	inspectwords(datei);
}
