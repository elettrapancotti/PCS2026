#include <vector>
#include <string>
#include <utility> //per swap
#include "insertionsort2.h"
//metodo dividi et impera ibrido per cui utilizza sotto una certa soglia un algoritmo quadratico
const int soglia = 18;

template<typename T>
int partition2(std::vector<T>& A, int p, int r) {//partizionamento con pivot a sx elementi minori o uguali del pivot a dx elementi maggiori
    T x = A[r];//sceglie ultimo elemento come pivot
    int i = p-1;//indice dell'ultimo elemento <= pivot (inizialmente nessuno)

    for (int j = p; j<r; j+=1){ //scorre il vettore da p a r-1

    for (int j = p; j<r; j+=1){
        if (A[j]<x) { //confronta con il pivot
            i += 1;
            std::swap(A[i], A[j]); //espande la zona degli elementi<= pivot
        }
    }
    std::swap(A[i+1], A[r]); //mette il pivot al posto giusto
    return i + 1; //restituisce l'indice del pivot

template<typename T>
void quicksort2(std::vector<T>& A, int p, int r) {
    if(r-p<soglia){  //se il sottoarray è minore di soglia usa insertionsort
        insertionsort2(A, p, r);
        return;
    }
    if(p<r){
        int q = partition2(A, p, r); //sposto gli elementi minori o uguali del pivot alla sua sinistra e quelli maggiori alla sua destra
        quicksort2(A, p, q-1); //ricorsione, applico quicksort al vettore già partizionato
        quicksort2(A, q+1, r);
    }
}