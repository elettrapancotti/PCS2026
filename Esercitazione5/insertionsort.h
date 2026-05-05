#include<vector>
//si parte considerando il primo elemento già ordinato e si considera via via la parte di sinistra ordinata
//si parte dal secondo elemento e lo si posiziona nella posizione corretta della parte già ordinata
//questo si fa spostando gli elementi maggiori verso destra
template<typename T>
void insertionsort(std::vector<T>& vec) {
    int N =vec.size();
    for (int j=1; j<N; ++j) {
        T key= vec[j]; //si salva in una variabile temporanea l'elemento da inserire nella parte ordinata
        int i = j-1;
        while(i>=0 && vec[i]>key) { //paragona gli elementi a key se non siamo ancora all'inizio del vettore
            vec[i+1] = vec[i]; //sposta  destra l'elemento maggiore di key 
            i -= 1; 
        }
        vec[i+1] = key; //assegnamo alla posizione in cui ci siamo fermati il valore di key
    }
}