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
    string imie, nazwisko;
    adresat.ustawIdAdresata((plikZAdresatami.pobierzIdOstatniegoAdresata() +1));
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    imie = metodyPomocnicze.wczytajLinie();
    imie = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);

    cout << "Podaj nazwisko: ";
    nazwisko = metodyPomocnicze.wczytajLinie();
    nazwisko = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);
    
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
    usleep(3000000);
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

void AdresatMenager::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;
    MetodyPomocnicze metodyPomocnicze;
    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = metodyPomocnicze.wczytajLinie();
        imiePoszukiwanegoAdresata = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);  
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
    usleep(3000000);
}

void AdresatMenager::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void AdresatMenager::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;
    MetodyPomocnicze metodyPomocnicze;
    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = metodyPomocnicze.wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
         wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
    usleep(3000000);
}

void AdresatMenager::edytujAdresata()
{
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
   // int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";
    MetodyPomocnicze metodyPomocnicze;
    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzIdAdresata() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                itr ->ustawImie(metodyPomocnicze.wczytajLinie());
                itr ->ustawImie(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(itr -> pobierzImie()));
                zaktualizujDaneWybranegoAdresata(*itr, idEdytowanegoAdresata);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                itr ->ustawNazwisko(metodyPomocnicze.wczytajLinie());
                itr ->ustawNazwisko(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(itr -> pobierzImie()));
                zaktualizujDaneWybranegoAdresata(*itr, idEdytowanegoAdresata);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                itr ->ustawNumerTel(metodyPomocnicze.wczytajLinie());
                zaktualizujDaneWybranegoAdresata(*itr, idEdytowanegoAdresata);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                itr -> ustawEmail(metodyPomocnicze.wczytajLinie());
                zaktualizujDaneWybranegoAdresata(*itr, idEdytowanegoAdresata);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                itr -> ustawAdres(metodyPomocnicze.wczytajLinie());
                zaktualizujDaneWybranegoAdresata(*itr, idEdytowanegoAdresata);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
    usleep(3000000);
}
int AdresatMenager::podajIdWybranegoAdresata()
{
    MetodyPomocnicze metodyPomocnicze;
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  =  metodyPomocnicze.wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}
void AdresatMenager::zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata)   
{
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";
    
    numerLiniiEdytowanegoAdresata = plikZAdresatami.zwrocNumerLiniiSzukanegoAdresata(idEdytowanegoAdresata);    
    liniaZDanymiAdresata = plikZAdresatami.zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    plikZAdresatami.edytujWybranaLinieWPliku(numerLiniiEdytowanegoAdresata, liniaZDanymiAdresata);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

char AdresatMenager::wybierzOpcjeZMenuEdycja()
{
    MetodyPomocnicze metodyPomocnicze;
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = metodyPomocnicze.wczytajZnak();

    return wybor;
}

int AdresatMenager::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;
    MetodyPomocnicze metodyPomocnicze;
    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzIdAdresata() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = metodyPomocnicze.wczytajZnak();
            if (znak == 't')
            {
                numerLiniiUsuwanegoAdresata = plikZAdresatami.zwrocNumerLiniiSzukanegoAdresata(idUsuwanegoAdresata);
                plikZAdresatami.usunWybranaLinieWPliku(numerLiniiUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                usleep(3000000);
                return idUsuwanegoAdresata;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("p       ause");
                return 0;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
        usleep(3000000);
    }
    return 0;
}

