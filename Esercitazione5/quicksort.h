#include <vector>
#include <string>
#include <utility> //per swap
//metodo dividi et impera
template<typename T>

int partition(std::vector<T>& A, int p, int r) { //partizionamento con pivot a sx elementi minori o uguali del pivot a dx elementi maggiori
    T x = A[r]; //sceglie ultimo elemento come pivot
    int i = p-1; //indice dell'ultimo elemento <= pivot (inizialmente nessuno)

    for (int j = p; j<r; j+=1){ //scorre il vettore da p a r-1
        if (A[j]<x) { //confronta con il pivot
            i += 1;
            std::swap(A[i], A[j]); //espande la zona di elementi minori o uguali del pivot
        }
    }
    std::swap(A[i+1], A[r]); //posiziona il pivot nella posizione corretta
    return i + 1; //restituisce l'indice finale del pivot
}

template<typename T>
void quicksort(std::vector<T>& A, int p, int r) {
    if(p<r){
        int q = partition(A, p, r);
        quicksort(A, p, q-1); //applico la ricorsione sulle due metà del vettore già partizionato
        quicksort(A, q+1, r);
    }
}