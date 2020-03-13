//
//  PlikTekstowy.h
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 12/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef PlikTekstowy_h
#define PlikTekstowy_h
#include <iostream>
#include <fstream>
 
using namespace std;
 
class PlikTekstowy {
 
    const string NAZWA_PLIKU;

public:
 
    PlikTekstowy(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {
    }
 
    string pobierzNazwePliku()
    {
        return NAZWA_PLIKU;
    }
 
    bool czyPlikJestPusty()
    {
        bool pusty = true;
        fstream plikTekstowy;
        plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);   
 
        if (plikTekstowy.good() == true)
        {
            plikTekstowy.seekg(0, ios::end);
            if (plikTekstowy.tellg() != 0)
                pusty = false;
        }
 
        plikTekstowy.close();
        return pusty;
    }
    
};

#endif /* PlikTekstowy_h */
