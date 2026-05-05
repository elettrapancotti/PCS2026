#include<vector>
//all'inizio si assume il primo elemento come minimo
//ad ogni iterazione cerca il minimo della parte non ordinata
template<typename T>
void selectionsort(std::vector<T>& vec) {
    int N =vec.size();
    for(int i=0; i<N-1; ++i) {
        int min = i;
        for(int j=i+1; j<N; ++j) { //l'elemento più piccolo va all'inizio della parte non ordinata e all'iterazione successiva si considerano solo gli elementi dopo
            if(vec[j]<vec[min]) {
                min = j; //se l'elemento paragonato con il minimo ssunto è minore l'elemento diventa il nuovo minimo
            }
        }
        T temp = vec[i]; //scambia il minimo effettivo con l'elemento nella posizione i assunto come minimo all'inizio del for
        vec[i] = vec[min];
        vec[min] = temp;
    }
}