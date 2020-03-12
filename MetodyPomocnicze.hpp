//
//  MetodyPomocnicze.hpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 27/02/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef METODYPOMOCNICZE_HPP
#define METODYPOMOCNICZE_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba);
    static int konwersjaStringNaInt(string liczba);
    
    string wczytajLinie();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    int wczytajLiczbeCalkowita();
    char wczytajZnak();
    
};
#endif /* MetodyPomocnicze_hpp */
