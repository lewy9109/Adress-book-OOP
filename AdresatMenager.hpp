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
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    Adresat podajDaneNowegoAdresata();
    PlikZAdresatami plikZAdresatami;
    void wyswietlDaneAdresata(Adresat adresat);
   
    
public:
    AdresatMenager (string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};
    int dodajAdresata();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wyswietlWszystkichAdresatow();
    
};

#endif /* AdresatMenager_hpp */
    
