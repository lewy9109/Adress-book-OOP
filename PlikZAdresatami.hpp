//
//  PlikZAdresatami.hpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 05/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef PlikZAdresatami_hpp
#define PlikZAdresatami_hpp
#include <vector>
#include <iostream>
#include <fstream>
#include "Adresat.hpp"
#include "MetodyPomocnicze.hpp"
#include "PlikTekstowy.h"
using namespace std;
class PlikZAdresatami : public PlikTekstowy
{

    string nazwaTymczasowegoPlikuZAdresatami;
    int idOstatniegoAdresata;
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku){
        idOstatniegoAdresata = 0;
        nazwaTymczasowegoPlikuZAdresatami = "Adresaci-tmp.txt"; 
    };
    void dopiszAdresataDoPliku(Adresat adresat); 
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);
    void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);    
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void usunWybranaLinieWPliku(int numerUsuwanejLinii);



};



#endif /* PlikZAdresatami_hpp */
