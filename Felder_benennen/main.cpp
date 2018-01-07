// Programmiersprache: C++
// Bankautomat v1.1
// Programmierer: Burak Koc
//
#include <iostream>
#include <windows.h>
using namespace std;
//Struktur erstellen
//
struct S_FeldInfo {
char Name[30];
bool Besetzt;
    };

//Konstante Arrays deklarieren & definieren
//
const int nBreite = 5;
const int nHoehe = 5;
//Arrays in Struktur einbinden
S_FeldInfo Spielfeld[nBreite][nHoehe];
// Funktionen deklarieren
//
void LoescheSpielfeld();
void ZeigeSpielfeld();
void ZeigeFelddaten();
void BesetzeFeld();

//Hauptprogramm
//
int main() {


    cout << "In diesem Programm kann man nach belieben Namen in bestimmte Felder (Arrays) einspeichern.\n";
    //Variablen
    //
    int Auswahl = 0;

    //Auswahl anzeigen
    //
    do {
        cout << "------------------------\n";
        cout << "1 - Spielfeld anzeigen\n";
        cout << "2 - Feld besetzen\n";
        cout << "3 - Felddaten anzeigen\n";
        cout << "4 - Spielfeld loeschen\n";
        cout << "5 - Programm beenden\n";
        cout << "------------------------\n";
        //Auswahl eingeben
        cout << "Ihre Auswahl: ";
        cin >> Auswahl;
        cout << "------------------------\n";
        //Auswahl
        switch (Auswahl)
        {
        case 1:
            //Spielfeld anzeigen
            //
            ZeigeSpielfeld();
            break;
        case 2:
            //Spielfeld besetzen
            //
            BesetzeFeld();
            break;
        case 3:
            //Felddaten anzeigen
            //
            ZeigeFelddaten();
            break;
        case 4:
            //Spielfeld loeschen
            //
            LoescheSpielfeld();
            break;
        case 5:
            //Programm beenden
            //
            cout << "Programm wird beendet...\n";
            Sleep(1000);
            break;
        default:
            //Falsche Auswahl
            cout << "Ungueltige Auswahl.\n";
            break;
        }
    } while (Auswahl != 5);
    cout << "Bis zum naechsten Mal.\n";


    return 0;
}
// Funktionen
// Funktion fuer Spielfeld loeschen
//
void LoescheSpielfeld() {
    for (int y = 0; y < nHoehe; y++)
    {
        for (int x = 0; x < nBreite; x++)
        {
            Spielfeld[x][y].Besetzt = false;
        }
    }
    cout << "Spielfeld wird geloescht...\n";
    Sleep(2000);
    cout << "Spielfeld wurde geloescht.\n";
}
// Funktion fuer Spielfeld anzeigen
//
void ZeigeSpielfeld() {
    cout << endl;
    for (int y = 0; y < nHoehe; y++)
    {
        for (int x = 0; x < nBreite; x++)
        {
            if (Spielfeld[x][y].Besetzt == true) {
                cout << "X    ";
            }
            else {
                cout << "O    ";
            }
        }
        cout << endl;
    }
    cout << endl;

}
// Funktion fuer Felddaten anzeigen
//
void ZeigeFelddaten() {
    int x = 0;
    int y = 0;
    do {
        cout << "x - Position (1-5): ";
        cin >> x;
    } while (x<1 || x>nBreite);
    do {
        cout << "y - Position (1-5): ";
        cin >> y;
    } while (y<1 || y>nHoehe);

    if (Spielfeld[x - 1][y - 1].Besetzt == false) {
        cout << "Dieses Feld ist noch nicht besetzt." << endl;
    }
    else {
        cout << "Feld ist besetzt von: ";
        cout << Spielfeld[x - 1][y - 1].Name << endl;
    }
}
// Funktion fuer Feld besetzen
//
void BesetzeFeld() {
    int x = 0;
    int y = 0;
    do {
        cout << "x-Position (1 - " << nBreite << "): ";
        cin >> x;
    } while (x<1 || x>nBreite);
    do {
        cout << "y-Position (1 - " << nHoehe << "): ";
        cin >> y;
    } while (y<1 || y>nBreite);

    cout << "Name: ";
    cin.ignore();
    cin.get(Spielfeld[x - 1][y - 1].Name, 29);
    Spielfeld[x - 1][y - 1].Besetzt = true;
}
