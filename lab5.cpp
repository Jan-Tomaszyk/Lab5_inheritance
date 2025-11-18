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

class Pojazd {
protected:
    string marka;
    string model;
    double obecna_predkosc;
public:
    // Konstruktor
    Pojazd(){}
    Pojazd(string ma, string mo)
    {
        marka = ma;
        model = mo;
    }
    virtual ~Pojazd()
    {

    }
    // Gettery

    // Settery

    virtual void przyspiesz()
    {}
    void zatrzymaj()
    {
        obecna_predkosc=0;
    }
};

class Rower
 : public Pojazd
{
    public:
    Rower()
        : Pojazd()
    {
        obecna_predkosc=0;
    }
    Rower(string ma, string mo)
        : Pojazd(ma, mo)
    {
        obecna_predkosc=0;
    }
    ~Rower()
    {}
    void przyspiesz()
    {
        obecna_predkosc+=5;
        cout<<"prędkość(roweru: "<<marka<<" "<<model<<") = "<<obecna_predkosc<<"\n";
    }
};

class Samochod
 : protected Pojazd
// : private Pojazd
{
    public:
    Samochod()
        : Pojazd()
    {
        obecna_predkosc=0;
    }
    Samochod(string ma, string mo)
        : Pojazd(ma, mo)
    {
        obecna_predkosc=0;
    }
    ~Samochod()
    {}
    void przyspiesz()
    {
        obecna_predkosc+=10;
        cout<<"prędkość(samochodu: "<<marka<<" "<<model<<") = "<<obecna_predkosc<<"\n";
    }
};

class Silnikowy
 : virtual public Pojazd
{
protected:
    //double obecna_predkosc;
public:
    Silnikowy()
    : Pojazd(){}
    ~Silnikowy(){}

    virtual void przyspiesz()
    {
        obecna_predkosc+=10;
        cout<<obecna_predkosc<<"\n";
    }
};

class Elektryczny
 : virtual public Pojazd
{
protected:
    double akumulator;
public:
    Elektryczny()
    : Pojazd(){}
    ~Elektryczny(){}

    virtual void ladowanie()
    {
        akumulator+=10;
        cout<<akumulator<<"\n";
    }
};

class Hybryda
: public Silnikowy, Elektryczny
{
public:
    Hybryda()
        : Silnikowy(), Elektryczny()
    {}

    void przyspiesz()
    {
        obecna_predkosc+=10;
        cout<<obecna_predkosc<<"\n";
        ladowanie();
    }
};

class ElektrycznySamochod
: public Samochod
{
public:
    void przyspiesz()
    {
        obecna_predkosc+=15;
         cout<<"prędkość(samochodu elektrycznego "/*<<marka<<" "<<model<<") = "*/<<obecna_predkosc<<"\n";
    }
};

void z1_2_3_5_6()
{
    Rower sklad("minikon", "składak");
    Samochod autocie("truckkun", "Optimus Prime");

    sklad.przyspiesz();
    sklad.przyspiesz();
    sklad.zatrzymaj();
    sklad.przyspiesz();
    //cout<<sklad.marka<<" "<<autocie.model;

    autocie.przyspiesz();
    autocie.przyspiesz();
    //autocie.zatrzymaj();
    autocie.przyspiesz();
    //cout<<autocie.marka<<" "<<autocie.model;
    //nie ma dostrzegalnej różnicy między private i protected dla atrybutów protected i klas public, jak jest u mnie
}


void z7_9_10()
{
    Silnikowy diesel;
    Elektryczny tesla;
    Hybryda hyundai;
    ElektrycznySamochod tes;

    diesel.przyspiesz();
    tesla.przyspiesz();
    hyundai.przyspiesz();
    tes.przyspiesz();
}

void z3()
{

}

int main()
{
    string kont = "T";
    while (kont == "T" || kont == "t")
    {
        int odp;
        cout << "Wybierz zestaw zadań do aktywacji:\n1 - 1,2,3,5\n2 - 7\n";
        cin >> odp;
        switch (odp)
        {
        case 1:
            cout << "Zadanie 1,2,3,5,6\n";
            z1_2_3_5_6();
            break;
        case 2:
            cout << "Zadanie 7_10\n";
            z7_9_10();
            break;
        }
        cout << "Czy chcesz kontynuacji?(T/N)";
        cin >> kont;
    }
    return 0;
}

