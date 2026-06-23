#include<iostream> //per cout
#include"find_path.hpp"
#include"de_pina.hpp"

int main() {
    //costruisco il mio grafo
    unidirected_graph<int> G;
    G.add_edge(1,2);
    G.add_edge(1,3);
    G.add_edge(2,3);
    G.add_edge(3,4);
    G.add_edge(3,5);
    G.add_edge(4,5);
    G.add_edge(4,6);
    G.add_edge(5,6);


    std::vector<std::vector<unidirected_edge<int>>> cicli = fundamental_cycles(G, 1);

    std::cout<< "Base cicli non necessariamnete minimi (" << cicli.size() << " cicli): " << "\n";
    for(int i=0; i < cicli.size(); ++i){
        std::cout<<"Ciclo "<< i + 1 <<" : ";
        for(int e=0; e < cicli[i].size(); ++e){
            std::cout<< cicli[i][e]<<" ";
        }
        std::cout<<"\n";
    }

    int sorgente = 1;
    std::map<unidirected_edge<int>, double> pesi; //vuota ma trova_ciclo_minimo inizializza tutto a 1

    std::vector<std::vector<unidirected_edge<int>>> base_cicli = De_Pina(G, sorgente, pesi);

    std::cout<< "Base cicli minimi (" << base_cicli.size() << " cicli): " << "\n";
    for (int i = 0; i < base_cicli.size(); ++i){
        std::cout<< "Ciclo " << i + 1 << " : ";
        for(int e = 0; e < base_cicli[i].size(); ++e){
             std::cout<< base_cicli[i][e] << " ";
        }
        std::cout<< "\n";
    }

    return 0;

}