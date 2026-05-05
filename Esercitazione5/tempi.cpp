#include <iostream> //per std::cout
#include <vector>
#include <algorithm> //per sort
#include <iomanip> //per std::scientific per std::setprecision, per allienare la tabella
#include "timecounter.h" //per misurare il tempo
#include "randfiller.h" //per riempire i vettori di numeri casuali
#include "bubblesort.h"
#include "insertionsort.h"
#include "selectionsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "quicksort2.h"


int main() {
    randfiller rf; //genera numeri casuali per riempire i vettori
    timecounter tc;

    std::cout << std::scientific; //scrive i numeri in notazione scientifica
    std::cout << std::setprecision(3);

    std::cout << "Size"<<"\t"<<"Merge"<<"\t"<<"\t"<<"Quick"<<"\t"<<"\t"<<"Quick2"<<"\t"<<"\t"<<"Bubble    "<<"\t"<<"Insertion"<<"\t"<<"Selection"<<"\t"<<"std::sort"<<"\n"; //intestiamo la tabella

    for(int taglia = 1; taglia<= 100; taglia+=1) {

        std::vector<std::vector<int>> vettori(100);

        for(int test=0; test< 100; ++test){
            std::vector<int> vec(taglia);
            rf.fill(vec, -1000, 1000); //riempie il vettore con numeri casualli usando randfiller

            vettori[test] = vec; //il vettore sarà posizionato all'indice "test" all'interno del vettore di vettori
        }

        std::vector<std::vector<int>> vecvec1=vettori;
        tc.tic();
        for(int i=0; i< 100; ++i){
            mergesort(vecvec1[i], 0, vecvec1[i].size()-1);
        }
        double tot_merge = tc.toc();
        double media_merge = tot_merge/100;
        
        std::vector<std::vector<int>> vecvec2=vettori;
        tc.tic();
        for(int i=0; i< 100; ++i){
            quicksort(vecvec2[i], 0, vecvec2[i].size()-1);
        }
        double tot_quick = tc.toc();
        double media_quick = tot_quick/100;

        std::vector<std::vector<int>> vecvec3=vettori;
        tc.tic();
        for(int i=0; i< 100; ++i){
            quicksort2(vecvec3[i], 0, vecvec3[i].size()-1);
        }
        double tot_quick2 = tc.toc();
        double media_quick2 = tot_quick2/100;

        std::vector<std::vector<int>> vecvec4=vettori;
        tc.tic();
        for(int i=0; i< 100; ++i){
            bubblesort(vecvec4[i]);
        }
        double tot_bubble = tc.toc();
        double media_bubble = tot_bubble/100;        

        std::vector<std::vector<int>> vecvec5=vettori;
        tc.tic();
        for(int i=0; i< 100; ++i){
            insertionsort(vecvec5[i]);
        }
        double tot_insertion = tc.toc();
        double media_insertion = tot_insertion/100;  
        
        std::vector<std::vector<int>> vecvec6=vettori;
        tc.tic();
        for(int i=0; i< 100; ++i){
            selectionsort(vecvec6[i]);
        }
        double tot_selection = tc.toc();
        double media_selection = tot_selection/100;

        std::vector<std::vector<int>> vecvec7=vettori;
        tc.tic();
        for(int i=0; i< 100; ++i){
            std::sort(vecvec7[i].begin(), vecvec7[i].end());
        }
        double tot_sort = tc.toc();
        double media_sort = tot_sort/100;

        std::cout<<taglia<<"\t"<<media_merge<<"\t"<<media_quick<<"\t"<<media_quick2<<"\t"<<media_bubble<<"\t"<<media_insertion<<"\t"<<media_selection<<"\t"<<media_sort<<"\n";
        
    }
}