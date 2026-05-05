#include <vector>
#include <limits>
#include <string>
//metodo dividi et impera dividiamo il vettore in elementi singoli che sono naturalmente ordinati e poi attraverso merge li ordiniamo
template<typename T>

void merge(std::vector<T>& A, int p, int q, int r) {
    int n1= q - p + 1;
    int n2= r - q;

    std::vector<T> L(n1+1);
    std::vector<T> R(n2+1);

    for (int i=0; i<n1; i+=1) {
        L[i]= A[p+i]; //copiamo la prima metà del vettore in L
    }
    for (int j=0; j<n2; j+=1) {
        R[j]= A[q+j+1]; //copiamo la seconda metà del vettore in R
    }
   
    L[n1] = 1;  //creo una sentinella con un numero casuale da mettere alla fine perche non dia un errore out of range
    R[n2] = 1;  //utilizzo le sentinelle perché non debba comparare i vettori quando uno dei due è finito

    int i = 0;
    int j = 0;
    for (int k = p; k< r+1; k+=1){  // quando entrmabi i vettori sono finiti k=r+1  e il ciclo si ferma
        if ((L[i]<=R[j] || j>=n2) && i<n1) { //se sono arrivata all'ultimo indice del vettore R ma non del vettore L aumento i
            A[k] = L[i];
            i += 1;
        }
        else { //se sono arrivata alla fine del vettore L aumento j fino a che k non diventa r+1 (finisco tutto il vettore)
           A[k] = R[j];
            j += 1; 
        }
    }
}


template<typename T>
void mergesort(std::vector<T>& A, int p, int r) {
    if (p < r) {
        int q  = (p+r)/2; //per definizione prende già il floor
        mergesort(A, p, q); //ricorsione, applico mergesort alle due parti del vettore
        mergesort(A, q+1, r);
        merge(A, p, q, r); //riunisce ordinando i vettori divisi 
    }
}