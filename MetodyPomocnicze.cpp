//
//  MetodyPomocnicze.cpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 27/02/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "MetodyPomocnicze.hpp"

string MetodyPomocnicze::konwerjsaIntNaString(int liczba)   
{
    ostringstream ss;       
    ss << liczba;
    string str = ss.str();
    return str;
}

int MetodyPomocnicze::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;
    return liczbaInt;
}


string MetodyPomocnicze::wczytajLinie() 
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}
string MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}


