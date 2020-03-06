//
//  Adresat.cpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 04/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "Adresat.hpp"

void Adresat::ustawIdAdresata (int noweIdAdresata)
{
    idAdresata = noweIdAdresata;
}

void Adresat::ustawIdUzytkownika (int noweIdUzytkownika)
{
    idUzytkownika = noweIdUzytkownika;
}
void Adresat::ustawImie (string noweImie)
{
    imie = noweImie;
}
void Adresat::ustawNazwisko (string noweNazwisko)
{
    nazwisko = noweNazwisko;
}

void Adresat::ustawNumerTel (string nowyNumerTel)
{
    numerTel = nowyNumerTel;
}
void Adresat::ustawEmail (string nowyEmail)
{
    email = nowyEmail;
}

void Adresat::ustawAdres (string nowyAdres)
{
    adres = nowyAdres;
}

int Adresat::pobierzIdAdresata ()
{
    return idAdresata;
}

int Adresat::pobierzIdUzytkownika ()
{
    return idUzytkownika;
}
string Adresat::pobierzImie ()
{
    return imie;
}
string Adresat::pobierzNazwisko ()
{
    return nazwisko;
}

string Adresat::pobierzNumerTel ()
{
    return numerTel;
}

string Adresat::pobierzEmail ()
{
    return email;
}

string Adresat::pobierzAdres ()
{
    return adres;
}

