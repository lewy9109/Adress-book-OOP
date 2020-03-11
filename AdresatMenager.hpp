//
//  AdresatMenager.hpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 04/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef AdresatMenager_hpp
#define AdresatMenager_hpp

//#include <stdio.h>
#include "Adresat.hpp"
#include "UzytkownikMenager.hpp"
#include "MetodyPomocnicze.hpp"
#include "PlikZAdresatami.hpp"
using namespace std;
class AdresatMenager
{
    vector <Adresat> adresaci;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    //int idOstatniegoAdresata;
    Adresat podajDaneNowegoAdresata();
    PlikZAdresatami plikZAdresatami;
    void wyswietlDaneAdresata(Adresat adresat);
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);

   
    
public:
    AdresatMenager (string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();

    
};

#endif /* AdresatMenager_hpp */
    
