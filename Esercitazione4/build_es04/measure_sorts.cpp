#include <iostream> //per std::cout
#include <vector> //per std::vector
#include <algorithm> //per sort
#include <iomanip> //per std::scientific per std::setprecision, per allienare la tabella
#include "timecounter.h" //per misurare il tempo
#include "randfiller.h" //per riempire i vettori di numeri casuali
#include "bubblesort.h"
#include "insertionsort.h"
#include "selectionsort.h"

int main() {
    randfiller rf; //generatore di numeri casuali

    std::cout << std::scientific; //scrive i numeri in notazione scientifica
    std::cout << std::setprecision(3);

    std::cout << "Size"<<"\t"<<"Bubble    "<<"\t"<<"Insertion"<<"\t"<<"Selection"<<"\t"<<"std::sort"<<"\n"; //intestiamo la tabella

    for(int size=4; size <= 8192; size*=2) {
        //crea vettore di dimensione size e poi lo riempiamo con numeri casuali
        std::vector<int> original(size);
        rf.fill(original, -1000, 1000);

        timecounter tc;

        std::vector<int> v1= original; //copiamo il vettore
        tc.tic(); //avviamo il cronometro
        bubblesort(v1);
        double time_bubble= tc.toc(); //calcoliamo il tempo in secondi

        std::vector<int> v2= original;
        tc.tic();
        insertionsort(v2);
        double time_insertion= tc.toc();

        std::vector<int> v3= original;
        tc.tic();
        selectionsort(v3);
        double time_selection= tc.toc();;

        std::vector<int> v4= original;
        tc.tic();
        std::sort(v4.begin(), v4.end());
        double time_sort= tc.toc();

        std::cout<<size<<"\t"<<time_bubble<<"\t"<<time_insertion<<"\t"<<time_selection<<"\t"<<time_sort<<"\n";
        }
        return 0;
}