//
//  uzytkownik.hpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 26/02/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#ifndef UZYTKOWNIK_HPP
#define UZYTKOWNIK_HPP

#include <iostream>

using namespace std;

class Uzytkownik    
{
    int id;
    string login;   
    string haslo;
    
public:
    void ustawId(int noweId);
    void ustawLogin(string nowyLogin);
    void ustawHaslo(string noweHaslo);
    
    int pobierzId();
    string pobierzLogin();
    string pobierzHaslo();
};
#endif /* uzytkownik_hpp */
