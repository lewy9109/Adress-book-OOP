//
//  ksiazkaAdresowa.cpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 26/02/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "ksiazkaAdresowa.hpp"
void KsiazkaAdresowa::rejestracja()
{
    uzytkownikMenager.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::wypiszWszystkich()
{
    uzytkownikMenager.wypiszWszystkichUzytkownikow();
}
int KsiazkaAdresowa::logowanieUzytkownika()
{
    return uzytkownikMenager.logowanieUzytkownika();
}
void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenager.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenager.dodajAdresata();
}
void KsiazkaAdresowa:: wyswietlWszystkichAdresatow()
{
    adresatMenager.wyswietlWszystkichAdresatow();   
}


