#include<vector>
//ad ogni passata l'elemento più piccolo va verso l'inizio
template<typename T>
void bubblesort(std::vector<T>& vec) {
    int N =vec.size();
    for (int i=0; i<N-1; ++i) {
        for(int j=N-1; j>i; --j) { //il ciclo interno parte dalla fine del vettore
            if(vec[j]<vec[j-1]) { //confronta coppie adiacenti
                T temp = vec[j];
                vec[j] = vec[j-1];
                vec[j-1] = temp;
            }
        }//dopo ogni passata l'eleemento in posizione i è al posto giusto
    }
}
