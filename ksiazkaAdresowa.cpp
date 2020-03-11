//
//  ksiazkaAdresowa.cpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 26/02/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "ksiazkaAdresowa.hpp"
bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
   return uzytkownikMenager.czyUzytkownikJestZalogowany();
}
void KsiazkaAdresowa::rejestracja() 
{
    uzytkownikMenager.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenager.logowanieUzytkownika();
    if(uzytkownikMenager.czyUzytkownikJestZalogowany())
    {
        adresatMenager = new AdresatMenager(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenager.pobierzIdZalogowanegoUzytkownika());
    }
   
}
void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{   
    uzytkownikMenager.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowywanieUzytkownika()
{
    uzytkownikMenager.wylogowywanieUzytkownika();
    delete adresatMenager;
    adresatMenager = NULL;
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenager -> dodajAdresata();
}
void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenager -> wyswietlWszystkichAdresatow();
}
void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
{
    adresatMenager -> wyszukajAdresatowPoImieniu();
}



