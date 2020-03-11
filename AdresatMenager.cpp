//
//  AdresatMenager.cpp
//  ksiazka wlasna obiektowo
//
//  Created by Krystian Lewandowski on 04/03/2020.
//  Copyright © 2020 Krystian Lewandowski. All rights reserved.
//

#include "AdresatMenager.hpp"

void AdresatMenager::dodajAdresata()
{   
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);     

}

Adresat AdresatMenager::podajDaneNowegoAdresata()
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;
    
    adresat.ustawIdAdresata((plikZAdresatami.pobierzIdOstatniegoAdresata() +1));
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(metodyPomocnicze.wczytajLinie());
    adresat.pobierzImie() = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie());

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(metodyPomocnicze.wczytajLinie());
    adresat.pobierzNazwisko() = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko());

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTel(metodyPomocnicze.wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(metodyPomocnicze.wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(metodyPomocnicze.wczytajLinie());

    return adresat;
}


void AdresatMenager::wyswietlWszystkichAdresatow()
{
    system("cls");
       if (!adresaci.empty())
       {
           cout << "             >>> ADRESACI <<<" << endl;
           cout << "-----------------------------------------------" << endl;
           for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
           {
               wyswietlDaneAdresata(*itr);
           }
           cout << endl;
       }
       else
       {
           cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
       }
    usleep(5000000);
}

void AdresatMenager::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzIdAdresata() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTel() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}
