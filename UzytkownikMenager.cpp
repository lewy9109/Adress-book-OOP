//
//  UzytkownikMenager.cpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 27/02/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "UzytkownikMenager.hpp"

void UzytkownikMenager::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);       
    
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    usleep(2000000);
   // system("pause"); include <windows.h>
}

Uzytkownik UzytkownikMenager::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login, haslo;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}
int UzytkownikMenager::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenager::czyIstniejeLogin(string login)
{
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin() == login)
        {
        cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
        return true;
        }
    }
    return false;
}
void UzytkownikMenager::wypiszWszystkichUzytkownikow()
{
    vector <Uzytkownik>:: iterator itr;
    for (itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        cout << itr->pobierzId() << itr->pobierzLogin() << endl;
    }
}

void UzytkownikMenager::wczytajUzytkownikowZPliku()
{
   uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

int UzytkownikMenager::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = wczytajLinie();

                if (itr -> pobierzHaslo() == haslo)
                {
                     cout << endl << "Zalogowales sie." << endl << endl;
                   idZalogowanegoUzytkownika = itr -> pobierzId();
                   system("pause");
                   return idZalogowanegoUzytkownika;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UzytkownikMenager::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> pobierzId() == idZalogowanegoUzytkownika)
        {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            usleep(2000000);
        }
    }
    
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
int UzytkownikMenager::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
string UzytkownikMenager::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}
