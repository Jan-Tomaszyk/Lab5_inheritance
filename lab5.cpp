#include <iostream>
#include <string>
/*#include <memory>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <random>
#include <cstdlib>
#include <ctime>*/

using namespace std;

const int domysl = -10000;
const int dlugNumeruTelefonu = 9;

class Osoba {
private:
    string imie;
    string nazwisko;
    int wiek;
    string mail;
    string telefon;
public:
    // Konstruktor
    Osoba(string imi, string nazwisk, int wie)
    {
        imie=imi;
        nazwisko=nazwisk;
        wiek=wie;
        mail="";
        telefon="";
    }

    // Gettery
    string get_imie() const
    {
        return imie;
    }
    string get_nazwisko() const
    {
        return nazwisko;
    }
    int get_wiek() const
    {
        return wiek;
    }
    string get_mail() const
    {
        return mail;
    }
    string get_telefon()  const
    {
        return telefon;
    }

    // Settery
    void set_imie(string nowe)
    {
        imie=nowe;
    }
    void set_nazwisko(string nowe)
    {
        nazwisko=nowe;
    }
    void set_wiek(int nowy)
    {
        wiek=nowy;
    }
    void set_mail(string nowy)
    {
        for (int i=0; i<nowy.length(); i++)
        {
            if(nowy[i]=='@')
            {
                mail=nowy;
            }
        }
        if(mail!=nowy)
        {
            cout<<"\nb³êdny mail - brak @\n";
        }
    }
    void set_telefon(string nowy)
    {
        if (nowy.length()==dlugNumeruTelefonu)
        {
            telefon=nowy;
        }
        else
        {
            cout<<"\nb³êdna d³ugoœæ numeru\n";
        }
    }

    // Sprawdzenie poprawnoœci wieku

    // Metoda wyœwietlaj¹ca dane

};

class Pracownik{
protected:
    string stanowisko;
    float wynagrodzenie;

public:
    Pracownik(string s, float wyn)
    {
        stanowisko=s;
        wynagrodzenie=wyn;
    }
    // Metoda wyœwietlaj¹ca stanowisko (dostêpna tylko dla klas dziedzicz¹cych)

};

class Nauczyciel
 : public Pracownik
{
    public:
    Nauczyciel(string s, float wyn)
        : Pracownik(s, wyn)
    {}
    void pokazDane()
    {
        cout<<stanowisko<<" "<<wynagrodzenie;
    }
};

class Administracja
 : public Pracownik
{
    public:
    Administracja(string s, float wyn)
        : Pracownik(s, wyn)
    {}
    void pokazDane()
    {
        cout<<stanowisko<<" "<<wynagrodzenie;
    }
};

void z1()
{
    Osoba geniusz("Waldo", "Schaeffer", 45);
    cout<<geniusz.get_imie()<<" "<<geniusz.get_nazwisko()<<" "<<geniusz.get_wiek();
    geniusz.set_imie("Franz");
    geniusz.set_nazwisko("Hopper");
    geniusz.set_wiek(54);
    cout<<geniusz.get_imie()<<" "<<geniusz.get_nazwisko()<<" "<<geniusz.get_wiek();
}


void z2()
{
    Osoba geniusz("Waldo", "Schaeffer", 45);
    string mail, telefon;
    cin>>mail>>telefon;
    geniusz.set_mail(mail);
    geniusz.set_telefon(telefon);
    cout<<geniusz.get_imie()<<" "<<geniusz.get_nazwisko()<<" "<<geniusz.get_wiek()<<geniusz.get_mail()<<geniusz.get_telefon();
}

void z3()
{
    Administracja Leciej("dyrektor", 6125.23);
    Nauczyciel Wilczynska("matematyczka", 4784.98);
    Leciej.pokazDane();
    Wilczynska.pokazDane();
}

int main()
{
    string kont = "T";
    while (kont == "T" || kont == "t")
    {
        int odp;
        cout << "Wybierz zadanie do aktywacji:";
        cin >> odp;
        switch (odp)
        {
        case 1:
            cout << "Zadanie 1\n";
            z1();
            break;
        case 2:
            cout << "Zadanie 2\n";
            z2();
            break;
        case 3:
            cout << "Zadanie 3\n";
            //cout<<2.0/3.0;
            //cout<<findRepeatingSequence(4, 9)<<"\n";
            //cout<<findRepeatingSequence(27, 33)<<"\n";
            z3();
            break;
        }
        cout << "Czy chcesz kontynuacji?(T/N)";
        cin >> kont;
    }
    return 0;
}

