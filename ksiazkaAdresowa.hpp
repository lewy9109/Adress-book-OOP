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
    AdresatMenager *adresatMenager;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenager(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        adresatMenager = NULL;
    };
    ~KsiazkaAdresowa()
    {
        delete adresatMenager;
        adresatMenager = NULL;
    };
    
    bool czyUzytkownikJestZalogowany();
    void rejestracja();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wyswietlWszystkichAdresatow();
    void wylogowywanieUzytkownika();
    void dodajAdresata();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void edytujAdresata();
    void usunAdresata();
};
#endif /* ksiazkaAdresowa_hpp */
