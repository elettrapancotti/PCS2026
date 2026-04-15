#include<vector>

template<typename T>
bool is_sorted(const std::vector<T>& vec) {
    if (vec.size() == 0) {
        return true; //se il vettore è vuoto è automaticamente ordinato
    }
    int N = vec.size();
    for (int i=0; i< N-1; ++i) { //scorre tutti gli elementi del vettore e li paragona a due a due
        if(vec[i]>vec[i+1]){
            return false; //se l'elemento a sinistra è maggiore di quello a destra la funzione resituisce false
        }
    }
    return true; //se nessun elemento di sx è maggiore dell'elemento adiacente a dx allora restituisce true
}
