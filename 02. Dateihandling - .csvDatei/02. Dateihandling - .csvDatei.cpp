#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct buch
{
	string autor;
	char titel[20]; 
	int anzahl;
	double preis;
	char standort; // H = Hannover, B = Berlin
};

int fuelleStruct(buch* db);
int dateiErstellen(buch* db, int anzahl);

int main()
{
	buch datenbank[2];
	int anzahlDatensaetze = 0;

	anzahlDatensaetze = fuelleStruct(datenbank);
	dateiErstellen(datenbank, anzahlDatensaetze);

	return 0;
}

// Zugegeben, diese Funktion ist armselig aber sonst wäre die
// Datenbankaufgabe nur Copy & Paste.
// Du machst das natuerlich variabel mit einer for und einem Index statt 0 und 1.
int fuelleStruct(buch* db) {
	db[0].autor = "Anton";
	strcpy_s(db[0].titel, "1. Titel");
	db[0].anzahl = 1; // MS Excel interpretiert eine Zahl gerne auch mal als Datum. Oeffne die Datei im Editor und die siehst was wirklich drin steht!
	db[0].preis = 1.11;
	db[0].standort = 'H';

	db[1].autor = "Bea";
	strcpy_s(db[1].titel, "2. Titel");
	db[1].anzahl = 2;
	db[1].preis = 2.22;
	db[1].standort = 'B';

	return 2;
}

int dateiErstellen(buch* db, int anzahl) {

	string dateiname = "Datenbank.csv";
	ofstream datei;

	datei.open(dateiname, ios::out);
	if (!datei.is_open())
	{
		cout << "Dateifehler beim Einlesen!" << endl;
		return 0;
	}

	for (int i = 0; i < anzahl; i++) {
		datei << db[i].autor << ';'
			<< db[i].titel << ';'
			<< db[i].anzahl << ';'
			<< db[i].preis << ';'
			<< db[i].standort << '\n';
	}
	datei.close();
}



