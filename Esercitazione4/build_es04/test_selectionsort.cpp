#include<iostream> //per std:cerr, std::cout
#include<vector> //per std::vector
#include<string> //per std::string
#include<cstdlib> //per EXIT_SUCCESS EXIT_FAILURE
#include"selectionsort.h"
#include"is_sorted.h"
#include"randfiller.h"

int main() {

    randfiller rf; // genera numeri casuali per riempire i vettori


    for(int test=0; test< 100; ++test){
        std::vector<int> numero(1); //creo un vettore di dimensione 1
        rf.fill(numero, 1, 1000); //ci metto dentro un numero casuale da 1 a 1000
        int size = numero[0]; // il primo e unico elemento del vettore è la mia size

        std::vector<int> vec(size); //creo il vettore di dimensione size
        rf.fill(vec, -1000, 1000); //riempie il vettore con numeri casualli usando randfiller

        selectionsort(vec);

        if(!is_sorted(vec)) { //se is sorted è false allora resituisce errore
            std::cerr<< "Errore: Selectionsort fallisce sui numeri" <<"\n";
            return EXIT_FAILURE;
        }
    }

    std::vector<std::string> parole= {
        "matematica", "italiano", "geografia", "storia", "filosofia", "scienze", "geometria" 
    };

    selectionsort(parole);

    if(!is_sorted(parole)) {
        std::cerr<< "Errore: Selectionsort fallisce sulle stringhe"<<"\n";
        return EXIT_FAILURE;
    }

    std::cout<<"Tutti i test di Selectionsort passati"<<"\n";
    return EXIT_SUCCESS;

}