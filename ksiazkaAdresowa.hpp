//
//  ksiazkaAdresowa.hpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 26/02/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef KSIAZKAADRESOWA_HPP
#define KSIAZKAADRESOWA_HPP

#include <iostream>
#include "UzytkownikMenager.hpp"
#include "AdresatMenager.hpp"
using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenager uzytkownikMenager;
    AdresatMenager adresatMenager;
    //string nazwaPlikuZAdresatami;
public:
    
    
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string NAZWAPLIKUZADRESATAMI) : uzytkownikMenager(nazwaPlikuZUzytkownikami), adresatMenager(NAZWAPLIKUZADRESATAMI) {
        uzytkownikMenager.wczytajUzytkownikowZPliku();
        adresatMenager.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    };
    void rejestracja();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wypiszWszystkich();
    void wyswietlWszystkichAdresatow();
    
    void dodajAdresata();
};
#endif /* ksiazkaAdresowa_hpp */
