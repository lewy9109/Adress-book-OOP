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
using namespace std;
class PlikZAdresatami
{
    int  idOstatniegoAdresata;
    const string nazwaPlikuZAdresatami;
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    
    
    int idUzytkownika;
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);


public:
    PlikZAdresatami(string PLIKZADRESATAMI) : nazwaPlikuZAdresatami(PLIKZADRESATAMI){
    };
    void dopiszAdresataDoPliku(Adresat adresat); 
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    

};



#endif /* PlikZAdresatami_hpp */
