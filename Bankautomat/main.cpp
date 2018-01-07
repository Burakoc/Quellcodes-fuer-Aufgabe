// Programmiersprache: C++
// Bankautomat v1.1
// Programmierer: Burak Koc
//
#include <iostream>
#include <string>
#include <windows.h>
#include <cmath>
using namespace std;
// Klassen erstellen
//
class Bankautomat{
public:
    //Konstruktor deklarieren
    //
    Bankautomat(string benutzername, short pin, float kontostand):
        m_benutzername(benutzername),
        m_pin(pin),
        m_kontostand(kontostand){}
    string getBenutzer(){return m_benutzername;}
    short getPin(){return m_pin;}
    float getKontostand(){return m_kontostand;}
    //Memberfunktionen deklarieren
    //
    void login();
    void eingeloggt();
private:
    //Membervariablen deklarieren
    //
    string m_benutzername;
    short m_pin;
    float m_kontostand;
};

void Bankautomat::login(){
    // Person wird nach Pin gefragt
    // Bei 3 falschen Eingaben wird der Benutzer abgemeldet
    //
    int l_pin;
    short l_versuche = 3;
    cout << "\nHallo, Herr " << m_benutzername << ".\n";
    cout << "Hinweis: Die PIN Nummer muss 4 Ziffern enthalten.\n";
    do {

        cout << "Geben Sie Ihren PIN ein: ";
        cin >> l_pin;
        int size = (int)(log10(l_pin)+1);
        if(size != 4){
            cout << "Hinweis: Die PIN Nummer muss 4 Ziffern enthalten.\n";
            l_pin = 0;
        } else {
            if(l_pin == m_pin){
                cout << "\nSie werden eingeloggt...\n";
                Sleep(1000);
                eingeloggt();
                break;
            }
            else {
                l_versuche--;
                cout << "Falscher PIN. Noch " << l_versuche << " Versuche uebrig.\n";
                if (l_versuche == 0) {
                    cout << "PIN zu oft falsch eingegeben. Sie werden automatisch abgemeldet.\n";
                    break;
                }
            }
        }

    } while(l_versuche != 0);

}

void Bankautomat::eingeloggt(){
    // Variablen fuer die Auswahl & fuer das Abheben
    //
    short l_auswahl;
    float l_abheben;
    short s = 0;
    // Auswahlmoeglichkeiten
    //
    while (s == 0){
        cout << "\n1. Kontostand aufrufen: 1\n";
        cout << "2. Geld abheben: 2\n";
        cout << "3. Abbruch: 3\n";
        cout << "Ihre Wahl: ";
        cin >> l_auswahl;
        cout << endl;
        // Kontostand wird aufgerufen
        //
        if(l_auswahl == 1){
            cout << "Ihr Kontostand betraegt " << m_kontostand << " Euro.\n";

        }
        // Geld wird abgehoben
        //
        else if(l_auswahl == 2){
            cout << "Wie viel Geld wollen Sie abheben?\n";
            cin >> l_abheben;
            if(m_kontostand - l_abheben >= 0){
                m_kontostand -= l_abheben;
                cout << "Ihr neuer Kontostand betraegt " << m_kontostand << " Euro.\n";
            } else {
                cout << "Sie koennen den gewuenschten Betrag nicht abheben.\n";
            }
        }
        // Programm wird beendet
        //
        else if(l_auswahl == 3){
            cout << "Abbruch erfolgt..." << endl;
            Sleep(1000);
            cout << "Erfolgreich abgemeldet. Vielen Dank fuer Ihr Vertrauen in unsere Filiale.\n\n";
            break;
        }
        // Falsche Auswahl
        //
        else {
            cout << "Falsche Wahl. Erneut versuchen.\n";

        }
    }
}
// Hauptprogramm
//
int main(){
    short s_menueauswahl = 0;
    bool b_login;
    string l_benutzername;
    Bankautomat person1("Schwarz", 1079, 5000);
    Bankautomat person2("Mueller", 2390, 6000);
    Bankautomat person3("Meier", 1232, 10000);
    do {
    cout << "------Auswahlmenue------\n";
    cout << "1. Anmelden: 1\n";
    cout << "2. Credits: 2\n";
    cout << "3. Programm beenden: 3\n";
    cout << "Ihre Auswahl: ";
    cin >> s_menueauswahl;
    if (s_menueauswahl == 1) {
        // Personen werden deklariert und definiert
        //

        // Textausgabe wiederholt ausgeben bei falscher Eingabe
        //
        do {
            cout << "----------------------------------------------------------------------------------\n";
            cout << "Infobox:\n";
            cout << "Zu Testzwecken sind bereits 3 Nachnamen registriert.\n";
            cout << "Geben Sie folgende Namen und die dazugehoerende Pinnummer zu Ihrer Auswahl ein:\n";
            cout << "Schwarz (1079), Mueller (2390), Meier (1232)\n";
            cout << "----------------------------------------------------------------------------------\n\n";
            cout << "---Fenster zum Einloggen---\n";
            cout << "Benutzernamen eingeben: ";

            // Person wird identifiziert
            //
            cin >> l_benutzername;
            if(l_benutzername == person1.getBenutzer()){
                b_login = true;
                person1.login();
            }
            else if(l_benutzername == person2.getBenutzer()){
                b_login = true;
                person2.login();
            }
            else if(l_benutzername == person3.getBenutzer()){
                b_login = true;
                person3.login();
            }
            else {
                cout << "Dieser Benutzername ist nicht registriert.\n";
                cout << "Bitte versuchen Sie es erneut.\n\n";
            }
        } while(b_login == false);
    }
    else if(s_menueauswahl == 2){
        cout << "------------------------\n";
        cout << "Bankautomat v1.1\n";
        cout << "Programmierer: Burak Koc\n\n";
    }
    else if(s_menueauswahl == 3){
        cout << "Programm wird beendet...\n" << endl;
        Sleep(1000);
        cout << "Vielen Dank fuer Ihr Vertrauen in unsere Filiale.\n";
    }
    else {
        cout << "Falsche Auswahl. Bitte versuchen Sie es noch einmal.\n";
    }
    }while(s_menueauswahl != 3);

}
