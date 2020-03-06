//
//  UzytkownikMenager.hpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 27/02/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef UZYTKOWNIKMENAGER_HPP
#define UZYTKOWNIKMENAGER_HPP

// #include <stdio.h>

#include <iostream>
#include <vector>
#include <unistd.h> // usypianie usleep();
#include <fstream>
#include <sstream>
#include <unistd.h> 


#include "uzytkownik.hpp"
#include "PlikZUzytkownikami.hpp"
using namespace std;
class UzytkownikMenager
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    PlikZUzytkownikami plikZUzytkownikami;  

public:
    UzytkownikMenager (string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami){};
    void rejestracjaUzytkownika();
    void wczytajUzytkownikowZPliku();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    string wczytajLinie();
    void zmianaHaslaZalogowanegoUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    
};
#endif /* UzytkownikMenager_hpp */
