//
//  main.cpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 26/02/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include <iostream>
#include "ksiazkaAdresowa.hpp"

using namespace std;
char wybierzOpcjeZMenuGlownego();
char wybierzOpcjeZMenuUzytkownika();
char wczytajZnak();
int main() {
 
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt", "Adresaci.txt");
   
    
 
    int idZalogowanegoUzytkownika = 0;
    //ksiazkaAdresowa.wypiszWszystkich();
    char wybor;
    while (true)
    {
        if (idZalogowanegoUzytkownika == 0)
        {
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracja();
                break;
            case '2':
                idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika(); 
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {

            //if (adresaci.empty() == true)
                // Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
                // Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
                // to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
           //     idOstatniegoAdresata = wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);

            wybor = wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                    ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
        //        wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
        //        wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
         //       idUsunietegoAdresata = usunAdresata(adresaci);
         //       idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
        //        edytujAdresata(adresaci);
                break;
            case '7':
                    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(); // nie dziala u"czysci plik z uzytkownicy.txt"
                break;
            case '8':
                idZalogowanegoUzytkownika = 0;
        //        adresaci.clear();
                break;
            }
        }
    
    
    }
     
    return 0;
}


char wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}

char wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}
char wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    
    wybor = wczytajZnak();

    return wybor;
}


