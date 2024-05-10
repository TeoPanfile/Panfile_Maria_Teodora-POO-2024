#include "pch.h" //librarie standard cli
#include <iostream>

using namespace std;
using namespace System;

// Clasa pentru Biblioteca
public ref class Biblioteca {
private:
    int numarCarti;

public:
    // Constructor
    Biblioteca(int carti) {
        numarCarti = carti;
    }
    // Metoda publica pentru a obtine valoarea lui numarCarti
    int getNumarCarti() {
        return numarCarti;
    }

    // Metoda pentru a adauga o carte in biblioteca
    void AdaugaCarte() {
        if (numarCarti < 100) {
            numarCarti++;
            Console::WriteLine("Cartea a fost adaugata in biblioteca. Numar total de carti: " + numarCarti);
        }
        else {
            Console::WriteLine("Biblioteca este plina. Nu se mai pot adauga carti.");
        }
    }

    // Metoda pentru a scoate o carte din biblioteca
    void ScoateCarte() {
        if (numarCarti > 0) {
            numarCarti--;
            Console::WriteLine("Cartea a fost scoasa din biblioteca. Numar total de carti: " + numarCarti);
        }
        else {
            Console::WriteLine("Biblioteca este deja goala. Nu se poate scoate nicio carte.");
        }
    }
};

// Clasa pentru Carte
public ref class Carte {
private:
    String^ titlu;
    String^ autor;

public:
    // Constructor
    Carte(String^ numeTitlu, String^ numeAutor) {
        titlu = numeTitlu;
        autor = numeAutor;
    }

    // Metoda pentru a obtine titlul cartii
    String^ GetTitlu() {
        return titlu;
    }

    // Metoda pentru a obtine autorul cartii
    String^ GetAutor() {
        return autor;
    }
};

// Functie pentru a citi numarul de carti de adaugat de la utilizator
int CitesteNumarCarti() {
    int numarCarti;
    Console::Write("Introduceti numarul de carti: ");
    String^ input = Console::ReadLine();
    numarCarti = Int32::Parse(input);
    return numarCarti;
}

// Functie pentru a citi numarul de carti de scos din biblioteca de la utilizator
int CitesteNumarCartiDeScoatere() {
    int numarCarti;
    Console::Write("Introduceti numarul de carti de scos din biblioteca: ");
    String^ input = Console::ReadLine();
    numarCarti = Int32::Parse(input);
    return numarCarti;
}

// Functie pentru a citi optiunea utilizatorului (adaugare sau scoatere)
char CitesteOptiune() {
    char optiune;
    Console::WriteLine("Doriti sa adaugati sau sa scoateti carti? (A/S)");
    String^ input = Console::ReadLine()->ToUpper();
    optiune = Convert::ToChar(input);
    return optiune;
}

void alegere() {
    // Cream o biblioteca cu 50 de carti
    Biblioteca^ biblioteca = gcnew Biblioteca(50);
    int numarCartiDisponibile = biblioteca->getNumarCarti();
    Console::WriteLine("Momentan sunt disponibile " + numarCartiDisponibile + " carti in biblioteca!");

    // Citim optiunea utilizatorului
    char optiune = CitesteOptiune();

    // Daca optiunea este adaugare, adaugam cartile in biblioteca
    if (optiune == 'A') {
        // Citim numarul de carti de adaugat de la utilizator
        int numarCartiDeAdaugat = CitesteNumarCarti();
        // Adaugam cartile in biblioteca
        for (int i = 0; i < numarCartiDeAdaugat; ++i) {
            biblioteca->AdaugaCarte();
        }
    }
    // Daca optiunea este scoatere, scoatem cartile din biblioteca
    else if (optiune == 'S') {
        // Citim numarul de carti de scos din biblioteca de la utilizator
        int numarCartiDeScoatere = CitesteNumarCartiDeScoatere();
        // Scoatem cartile din biblioteca
        for (int i = 0; i < numarCartiDeScoatere; ++i) {
            biblioteca->ScoateCarte();
        }
    }
    // Daca optiunea nu este valida, afisam un mesaj corespunzator
    else {
        Console::WriteLine("Optiunea introdusa nu este valida.");
    }
}

// Functia principala
int main() {
   
    alegere();
    Console::ReadLine(); // Asteptam sa se apese o tasta pentru a inchide consola

    return 0;
}
