#include "pch.h"
#include <iostream>

using namespace System; //pt Visual C++/CLI
using namespace std; //pt biblioteci cu functii standard
//de citit despre modificatorii private, public, protected
struct Persoana
{
    unsigned vs;
    char nume[20];
    char prenume[20];
};
class Pers
{
public:
    //doua metode cu acelasi nume cu cel al clasei, adica Pers
    //o metoda cu params si una fara params
    Pers(unsigned vs1, char* num1, char* prenum1)
    {
        vs = vs1;
        strcpy_s(nume, 20, num1);
        strcpy_s(prenume, 20, prenum1);
    }
    Pers() {}
    unsigned arata_vs() { return this->vs; }
    char* arata_nume() { return this->nume; }

private:
    unsigned vs;
    char nume[20];
    char prenume[20];
};

int main()
{


    Console::WriteLine("Introduceti numarul de persoane: ");
    int nr_persoane;
    cin >> nr_persoane;
    Persoana* persoane = new Persoana[nr_persoane];
    for (int i = 0; i < nr_persoane; i++) {
        Console::WriteLine("Introduceti numele persoanei{0}:, ", i + 1);
        char nume[20];
        cin >> nume;
        strcpy_s(persoane[i].nume, 20, nume);
        Console::WriteLine("Introduceti prenumele persoanei{0}:, ", i + 1);
        char prenume[20];
        cin >> prenume;
        strcpy_s(persoane[i].prenume, 20, prenume);
        Console::WriteLine("Introoduceti varsta persoanei {0} ", i + 1);
        unsigned vs;
        cin >> vs;
        persoane[i].vs = vs;
    }
    Console::WriteLine("Afisam numele persoanelor si varstele aferente: "); //Specific Visual C++ / CLI
    for (int i = 0; i < nr_persoane; i++) {
        cout << persoane[i].nume << "\t" << persoane[i].vs << endl;
    }
    Console::ReadKey();//Mentine fereastra deschisa
}