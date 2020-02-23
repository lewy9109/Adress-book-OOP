#include <unistd.h> // do usypiania wyswietlania usleep(1000000) - 1 sek;
#include <iostream>
#include <stdio.h> // system("clear");
#include <string>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

struct Object
{
    string name;
    string lastname;
    string adress; // getline();
    string phone;
    string email;
    int id;
    int idUser;
};

struct User
{
    string login, password;
    int id;
};

void loadingFileAllusers (vector <Object> &uzytkownik);
void addUser(vector <Object> &userList, int idUser)
{
    vector <Object> fulllist;
    vector <Object> :: iterator itr;
    loadingFileAllusers(fulllist);
    
    int idperson = 0;
    for (itr = fulllist.begin(); itr != fulllist.end(); itr ++)
    {
        idperson = itr -> id;
    }
    
    system("clear");
    cout << "Dodaj znajomego do książki adresowej.\n";
    Object obiekt;
   
    
    obiekt.id = idperson + 1;
    obiekt.idUser = idUser;
    
    cout << "Podaj imię: ";
    cin >> obiekt.name;
    transform(obiekt.name.begin(), obiekt.name.end(), obiekt.name.begin(), ::toupper);
    
    cout << "Podaj nazwisko: ";
    cin >> obiekt.lastname;
    transform(obiekt.lastname.begin(), obiekt.lastname.end(), obiekt.lastname.begin(), ::toupper);
    
    cout << "Podaj adres: ";
    cin.ignore();
    getline(cin, obiekt.adress);
    cout << "Podaj nr telefonu: ";
    cin.ignore();
    getline(cin, obiekt.phone);
    cout << "Podaj emial ";
    cin >> obiekt.email;
    
    
    userList.push_back(obiekt);
   
    ofstream plik;
    plik.open("ksiazka.txt", ios::out | ios::app);
    
    if (plik.good()){
        
            plik << obiekt.id << "|"
            << idUser << "|"
            << obiekt.name << "|"
            << obiekt.lastname << "|"
            << obiekt.adress << "|"
            << obiekt.phone  << "|"
            << obiekt.email << "|" << endl;
        
        plik.close();
        
    }
    else{
        cout << "Nie mozna otworzyc pliku: ksiazka.txt" << endl;
    }
    
    cout << "Osoba zostala dodana." << endl;
    usleep(2000000);

}

void showListUser(const Object & obiekt)
{
    cout << obiekt.id << ". "<< obiekt.name << " " << obiekt.lastname << ", adres: " << obiekt.adress << ", tel - " << obiekt.phone << ", email: " << obiekt.email << endl;
}

void searchName(const Object & obiekt, string name)
{
    if (name == obiekt.name)
        cout << obiekt.id << ". "<< obiekt.name << " " << obiekt.lastname << ", adres: " << obiekt.adress << ", tel - " << obiekt.phone << ", email: " << obiekt.email << endl << endl;
}

void searchLastname(const Object & obiekt, string name)
{
   if (name == obiekt.lastname)
   cout << obiekt.id << ". "<< obiekt.name << " " << obiekt.lastname << ", adres: " << obiekt.adress << ", tel - " << obiekt.phone << ", email: " << obiekt.email << endl << endl;
}

int stringToInt(string str)
{
    int i;
    istringstream iss(str);
    iss >> i;
    return i;
}


void pauze()
{
    cin.ignore();
    do
    {
        cout << '\n' << "Press the Enter key to continue.";
    } while (cin.get() != '\n');
}

void deleteUser(int x, vector<Object> &userList)
{
    int punkty = 0;
    char choice;
    vector <Object>::iterator itr;
  
    vector <Object> allusers;
    loadingFileAllusers(allusers);
    vector<Object>::iterator it;
   
            for (it = userList.begin(); it != userList.end(); it++)
            {
                for(itr = allusers.begin(); itr != allusers.end(); itr ++)
                {
                    if ((it -> id == itr -> id) && (itr->id == x))
                    {
                        cout << "Czy na pewno chcesz usunąć użytkownika?" << itr->name << " " << itr->lastname << "\nWciśni t aby zatwierdzic. \n" << endl;
                        cin >> choice;
                          
                          if(choice == 't')
                          {
                              allusers.erase(itr);
                              userList.erase(it);
                              it --;
                              itr --;
                              punkty ++;
                          }
                    
                    }
                }
            }
    
    if (punkty == 1)
    {
         ofstream plik;
         plik.open("ksiazka.txt", ios::out | ios::trunc);
              
         if (plik.good())
         {
             for(itr = allusers.begin(); itr != allusers.end(); itr ++)
             {
                 plik << itr-> id << "|"
                     << itr -> idUser << "|"
                     << itr -> name << "|"
                     << itr -> lastname << "|"
                     << itr -> adress << "|"
                     << itr -> phone  << "|"
                     << itr -> email << "|" << endl;
             }
             plik.close();
                    
         }
             else
             cout << "Nie mozna otworzyc pliku: ksiazka.txt" << endl;
    }
    punkty = 0;
}
void loadingFileAllusers (vector <Object> &allUsers)
{
    Object obiekt;
    string linia, wyraz;
    fstream plik;
    plik.open("ksiazka.txt", ios::in);
    while(getline(plik, linia))
    {
        int punkt = 0;
        int liczba = 0;
        int idZalogowanego = 0;
        for(int i = 0; i < linia.length(); i++)
        {
            
            if (linia[i] == '|')
            {
                punkt ++;
                
                if(punkt == 1)
                {
                    liczba = stringToInt(wyraz);
                    obiekt.id = liczba;
                }
                else if (punkt == 2)
                {
                    idZalogowanego = stringToInt(wyraz);
                    obiekt.idUser = idZalogowanego;
                }
                else if (punkt == 3)
                {
                    obiekt.name = wyraz;
                }
                else if (punkt == 4)
                {
                    obiekt.lastname = wyraz;
                }
                else if (punkt == 5)
                {
                    obiekt.adress = wyraz;
                }
                else if (punkt == 6)
                {
                   
                    obiekt.phone = wyraz;
                }
                else if (punkt == 7)
                {
                  
                   obiekt.email = wyraz;
                }
                
                wyraz = "";
                i++;
                
            }
            wyraz += linia[i];
        }
        
        allUsers.push_back(obiekt);
        
        wyraz = "";
        
    }
    plik.close();
    
    
}

void editUser(vector<Object> &userList, int selectID)
{
    vector<Object>:: iterator itr;
    string edycja;
    char choice;
    vector <Object> allusers;
    loadingFileAllusers(allusers);
    vector<Object>::iterator it;
    
    for(itr = userList.begin(); itr != userList.end(); itr ++)
    {
       if(itr->id == selectID)
       {
           do
           {
               cout << "Co chcesz edytowc u Pana/Pani : " << itr->name << " " << itr->lastname << endl;
               cout << "1. Imie \n";
               cout << "2. Nazwisko \n";
               cout << "3. Adres \n";
               cout << "4. telefon \n";
               cout << "5. email \n";
               cout << "6. powrot do glownego menu \n";
               
               cin >> choice;

               if (choice == '1')
               {
                   itr->name.erase();
                   cout<< "Wprowadz imie:\n";
                   cin >> edycja;
                   transform(edycja.begin(), edycja.end(), edycja.begin(), :: toupper);
                   itr->name = edycja;
               }
               else if (choice == '2')
               {
                   itr->lastname.erase();
                   cout << "Wprowadz nazwisko:\n";
                   cin >> edycja;
                   transform(edycja.begin(), edycja.end(), edycja.begin(), :: toupper);
                   itr->lastname = edycja;
               }
               else if (choice == '3')
               {
                   itr->adress.erase();
                   cout << "Wprowadz adres:\n";
                   cin >> edycja;
                   itr->adress = edycja;
               }
               else if (choice == '4')
               {
                   itr->phone.erase();
                   cout << "Wprowadz telefon:\n";
                   cin >> edycja;
                   itr->phone = edycja;
               }
               else if (choice == '5')
               {
                    itr->email.erase();
                    cout << "Wprowadz email:\n";
                    cin >> edycja;
                    itr->email = edycja;
       
               }
                 
            }while(choice != '6');
       }
    }
    
    for (itr = userList.begin(); itr != userList.end(); itr ++)
    {
        if (selectID == itr ->id)
        {
          fstream plik, plikTemp;
          plikTemp.open("ksiazka_tymczasowa.txt", ios::out | ios::app);
          plikTemp.close();
       
           for (it = allusers.begin(); it != allusers.end(); it ++)
           {
               if (it ->id != itr->id)
               {
                   plikTemp.open("ksiazka_tymczasowa.txt", ios::out | ios::app);
                   if (plikTemp.good())
                   {
                       plikTemp << it-> id << "|"
                       << it -> idUser << "|"
                       << it -> name << "|"
                       << it -> lastname << "|"
                       << it -> adress << "|"
                       << it -> phone  << "|"
                       << it -> email << "|" << endl;
                   }else cout << "Nie mozna otworzyc pliku: ksiazka.txt" << endl;
                   plikTemp.close();
                   
               }
               else if (it->id == itr ->id)
               {
                   plikTemp.open("ksiazka_tymczasowa.txt", ios::out | ios::app);
                   if (plikTemp.good())
                   {
                       plikTemp << itr -> id << "|"
                       << itr -> idUser << "|"
                       << itr -> name << "|"
                       << itr -> lastname << "|"
                       << itr -> adress << "|"
                       << itr -> phone  << "|"
                       << itr -> email << "|" << endl;
                   }else cout << "Nie mozna otworzyc pliku: ksiazka.txt" << endl;
                   plikTemp.close();
                   
               }
               
           }
            remove("ksiazka.txt");
            rename("ksiazka_tymczasowa.txt", "ksiazka.txt");
       }
       
    }

}
 
void loadingFile(vector <Object> &usersList, int idZalogowanegoUzytkownika)
{
    Object obiekt;
    string linia, wyraz;
    fstream plik;
    plik.open("ksiazka.txt", ios::in);
    while(getline(plik, linia))
    {
        int punkt = 0;
        int liczba = 0;
        int idZalogowanego = 0;
        for(int i = 0; i < linia.length(); i++)
        {
            
            if (linia[i] == '|')
            {
                punkt ++;
                
                if(punkt == 1)
                {
                    liczba = stringToInt(wyraz);
                    obiekt.id = liczba;
                }
                else if (punkt == 2)
                {
                    idZalogowanego = stringToInt(wyraz);
                    obiekt.idUser = idZalogowanego;
                }
                else if (punkt == 3)
                {
                    obiekt.name = wyraz;
                }
                else if (punkt == 4)
                {
                    obiekt.lastname = wyraz;
                }
                else if (punkt == 5)
                {
                    obiekt.adress = wyraz;
                }
                else if (punkt == 6)
                {
                   
                    obiekt.phone = wyraz;
                }
                else if (punkt == 7)
                {
                  
                   obiekt.email = wyraz;
                }
                
                wyraz = "";
                i++;
                
            }
            wyraz += linia[i];
        }
        
        if(idZalogowanegoUzytkownika == obiekt.idUser)
        usersList.push_back(obiekt);
        
        wyraz = "";
       
    }
    plik.close();
    
    
}

void saveFileUser(vector <User> &registeredUsers);
void zmienHaslo (int idZalogowanegoUzytkownika, vector<User> &registeredUsers)
{
    string edycja;
    vector<User>::iterator itr;
    
    for (itr = registeredUsers.begin(); itr != registeredUsers.end(); itr++)
    {
        if (itr -> id == idZalogowanegoUzytkownika)
        {
            itr -> password.erase();
            cout << "Wprowadz nowe haslo: ";
            cin >> edycja;
            itr -> password = edycja;
        }
    }
    
    saveFileUser(registeredUsers);
    
}

int mainMenu(int idZalogowanegoUzytkownika, vector <User> &registeredUsers)
{
   
      vector <Object> usersList;
      string word;
      vector<Object>::iterator itr;
    
      loadingFile(usersList, idZalogowanegoUzytkownika);
     
      //system("clear");
      while (true){
          system("clear");
          cout << "Program - Książka adresowa \n\n";
          cout << "Wybierz opcje: \n";
          cout << "1 - Dodaj nową osobę \n";
          cout << "2 - Wyszukaj osobę po imieniu \n";
          cout << "3 - Wyszukaj osobe po nazwisku \n";
          cout << "4 - Wyświetle całą liste znajomych\n";
          cout << "5 - Usuń osobe \n";
          cout << "6 - Edytuj osobe\n";
          cout << "7 - Zmien haslo\n";
          cout << "9 - Wyloguj sie z programu \n\n";
          
          
          int pick;
          char choice;
          cin >> choice;
          
          
          if (choice == '1')
          {
              addUser(usersList, idZalogowanegoUzytkownika);
          }
          else if (choice == '2')
          {
              system("clear");
              cout << "Wpisz imie aby wyszykać wszystkie osoby z takim samym imieniem: " << endl;
              cin >> word;
              transform(word.begin(), word.end(), word.begin(), ::toupper);
              
              for(itr = usersList.begin(); itr != usersList.end(); itr ++){
              searchName (*itr, word);
              }
              pauze();
          }
          else if (choice == '3')
          {
              system("clear");
              cout << "Wpisz nazwisko aby wyszykać wszystkie osoby z takim samym nazwiskiem: " << endl;
              cin >> word;
              transform(word.begin(), word.end(), word.begin(), ::toupper);
             
              for(itr = usersList.begin(); itr != usersList.end(); itr ++){
              searchLastname (*itr, word);
              }
              pauze();
              
          }
          else if (choice == '4')
          {
              cout << "Cała lista osób w książce adresowej: \n";
              for(itr = usersList.begin(); itr != usersList.end(); itr ++)
              showListUser(*itr);
              pauze();
          }
          else if (choice == '5')
          {
              cout << "Podaj ID osoby ktorą chcesz usunąć: \n";
              cin >> pick;
              deleteUser(pick, usersList);
             
              
          }
          else if (choice == '6')
          {
              cout << "Podaj ID osoby ktorą chcesz edytowac: \n";
              cin >> pick;
              editUser(usersList, pick);
            
          }
          else if (choice == '7')
          {
              zmienHaslo(idZalogowanegoUzytkownika, registeredUsers);
              
          }
          else if (choice == '9')
              return 1;
             
      }
}


void rejestracja (vector <User> &registeredUsers)
{
    User objekt;
    string login, haslo;
    cout << "Podaj nazwe uzytkownika: ";
    cin >> login;
    
    vector<User>::iterator itr = registeredUsers.begin();
    while (itr != registeredUsers.end())
    {
        if (itr->login == login)
        {
            cout << "Taki użytkownik istnieje \nWpisz inna nazwe uzytkownika: ";
            itr = registeredUsers.begin();
            cin >> login;
        }
       
        itr++;
    }

    
    cout << "Podaj haslo: ";
    cin >> haslo;
    int iloscUzytkownikow = (int)registeredUsers.size() + 1;
    
    objekt.id = iloscUzytkownikow;
    objekt.login = login;
    objekt.password = haslo;
    registeredUsers.push_back(objekt);
    
   
    cout << "Uzytkownik został pomyslnie zarejestrowany." << endl;
    usleep(2000000);
}

int logowanie (vector <User> &registeredUsers)
{
    int idUzytkownika = 0;
    string login, haslo;
    
    cout << "Podaj login uzytkownika: ";
    cin >> login;
    
    vector<User>::iterator itr = registeredUsers.begin();
    while (itr != registeredUsers.end())
    {
         if (itr->login == login)
         {
             for (int i = 0; i < 3; i++)
             {
                 cout << "Podaj haslo: ";
                 cin >> haslo;
                 
                 if (itr -> password == haslo)
                 {
                     cout << "Zalogowales sie !!" << endl;
                     idUzytkownika = itr -> id;
                     pauze();
                     return idUzytkownika;
                 }
             }
             return 0;
         }
         itr++;
    }
    cout << "Nie ma takiego uzytkownika !"<< endl;
    pauze();
    return 0;
}

void loadingFileUser(vector <User> &registeredUsers)
{
    User obiekt;
    string linia, wyraz;
    fstream plik;
    
    plik.open("users.txt", ios::in);
    while(getline(plik, linia))
    {
        int punkt = 0;
        int liczba = 0;
        for(int i = 0; i < linia.length(); i++)
        {
            
            if (linia[i] == '|')
            {
                punkt ++;
                if(punkt == 1)
                {
                    liczba = stringToInt(wyraz);
                    obiekt.id = liczba;
                }
                else if (punkt == 2)
                {
                    obiekt.login = wyraz;
                }
                else if (punkt == 3)
                {
                    obiekt.password = wyraz;
                }
                wyraz = "";
                i++;
                
            }
            wyraz += linia[i];
        }
        registeredUsers.push_back(obiekt);
        wyraz = "";
        
    }
    plik.close();
    
}

void saveFileUser(vector <User> &registeredUsers)
{
    vector<User>:: iterator itr;
    ofstream plik;
    plik.open("users.txt", ios::out | ios::in | ios::trunc);
    
    if (plik.good()){
        for(itr = registeredUsers.begin(); itr != registeredUsers.end(); itr ++)
        {
            plik << itr-> id << "|"
            << itr -> login << "|"
            << itr -> password << "|" << endl;
        }
        plik.close();
        
    }
    else{
        cout << "Nie mozna otworzyc pliku: ksiazka.txt" << endl;
    }
}

void makeFileToSave()
{
    fstream plik;
    plik.open("ksiazka.txt", ios::out | ios::app);
    plik.close();
    
    fstream plikUser;
    plikUser.open("users.txt", ios::out | ios::app);
    plikUser.close();
}

int main() {
        
    vector <Object> usersList;
    makeFileToSave();
    
    vector <User> registeredUsers;
    int idZalogowanegoUrzytkownika = 0;
    
    loadingFileUser(registeredUsers);
    
    char choice;
    
    
    while (1){
        system("clear");
        cout << "1. Logowanie" << endl;
        cout << "2. Rejestracja" << endl;
        cout << "9. Zakoncz program" << endl;
        
        cin >> choice;
        
        if(choice == '1')
        {
            idZalogowanegoUrzytkownika = logowanie(registeredUsers);
            if(idZalogowanegoUrzytkownika != 0)
            mainMenu(idZalogowanegoUrzytkownika, registeredUsers);
        }
        else if (choice == '2')
        {
           rejestracja (registeredUsers);
           saveFileUser(registeredUsers);
           
        }
        else if (choice == '9')
            exit(0);
        
    }
    
    return 0;
}


