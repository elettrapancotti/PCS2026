#include<iostream> //per std::cout e std::ostream
#include<sstream> //per std::ostringstream
#include"unidirected_graph.hpp" //la classe per i grafi
//non includo unidirected_edge.hpp perché già inclusa in unidirected_graph.hpp

int main() {

    //Test 1: il costruttore di edge garantisce u<v
    unidirected_edge<int> e1(3,1);
    if(e1.from()!=1 || e1.to()!=3) {
        std::cout<<"Test 1 fallito: il costruttore di edge non garantisce u < v" << "\n";
        return 1;
    }
    std::cout<<"Test 1 superato: il costruttore di edge garantisce u < v" << "\n";

    //Test 2: operator ==
    unidirected_edge<int> e2(1,3);
    if(!(e1 == e2)) {
        std::cout<<"Test 2 fallito: (3,1) e (1,3) dovrebbero essere uguali" << "\n";
        return 1;
    }
    std::cout<<"Test 2 superato: operator == corretto" << "\n";


    //Test 3: operator <
    unidirected_edge<int> e3(2,4);
    if(!(e2 < e3)) {
        std::cout<<"Test 3 fallito: (1,3) dovrebbe essere minore di (2,4)" << "\n";
        return 1;
    }

    //controlliamo anche il caso in cui il primo nodo è uguale
    unidirected_edge<int> e3b(1,2);
    if(!(e3b < e2)) {
        std::cout<<"Test 3 fallito: (1,2) dovrebbe essere minore di (1,3)" << "\n";
        return 1;
    }
    std::cout<<"Test 3 superato: operator < corretto" << "\n";

    //Test 4: operator <<
    //usiamo uno stringstream per catturare l'output e confrontarlo
    std::ostringstream oss;
    oss << e1;
    if(oss.str() != "(1,3)") { // .str() per leggere il testo come stringa
        std::cout<<"Test 4 fallito: (1,3) non viene stampato correttamente" << "\n";
        return 1;
    }
    std::cout<<"Test 4 superato: operator << corretto" << "\n";

    //Test 5: costruttore di default crea grafo vuoto (lo verificheremo dopo) e add_edge
    unidirected_graph<int> G;
    G.add_edge(1,2);
    G.add_edge(2,3);
    G.add_edge(1,3);
    std::cout<<"Test 5 superato: add_edge non crasha" << "\n"; //non possiamo ancora testarlo con all_nodes e all_edges non ancora verificati

    //Test 6: all_edges
    std::list<unidirected_edge<int>> archi = G.all_edges();
    if(archi.size() != 3) {
        std::cout<< "Test 6 fallito: all_edges non corretto" << "\n";
        return 1;
    }
    std::cout<< "Test 6 superato: all_edges corretto"<< "\n";

    //Test 7: all_nodes
    std::set<int> nodi = G.all_nodes();
    if(nodi.find(1) == nodi.end() || nodi.find(2) == nodi.end() || nodi.find(3) == nodi.end() || nodi.size() != 3) { //find permette di trovare un elemento all'interno del set se non c'è restituisce nomeset.end()
        std::cout<< "Test 7 fallito: all_nodes non corretto"<<"\n";
        return 1;
    }
    std::cout<< "Test 7 superato: all_nodes corretto"<<"\n";

    //Test 8: add_edge ignora i duplicati
    G.add_edge(2,1);
    if(G.all_edges().size() != 3 || G.all_nodes().size() != 3) {
        std::cout<< "Test 8 fallito: add_edge non ignora i duplicati"<<"\n";
        return 1;
    }
    std::cout<< "Test 8 superato: add_edge ignora i duplicati"<<"\n";

    //Test 9: neighbours
    std::set<int> vicini_1 = G.neighbours(1);
    if(vicini_1.find(2) == vicini_1.end() || vicini_1.find(3) == vicini_1.end() || vicini_1.size() != 2) {
        std::cout<< "Test 9 fallito: neighbours non corretto"<<"\n";
        return 1;
    }

    std::set<int> vicini_100 = G.neighbours(100); //nodo che non esiste
    if(vicini_100.size() != 0) {
        std::cout<< "Test 9 fallito: neighbours di nodo inesistente non vuoto"<<"\n";
        return 1;
    }

    std::cout<< "Test 9 superato: neighbours corretto"<< "\n";

    //Test 10: edge_number
    unidirected_edge<int> e4(1,2);
    int num = G.edge_number(e4); 
    if(num != 0){ //essendo (1,2) il primo arco inserito la sua numerazione deve essere 0
        std::cout<< "Test 10 fallito: edge_number non corretto" <<"\n";
        return 1;
    }
    std::cout<< "Test 10 superato: edge_number corretto"<< "\n";

    //Test 11: edge_at
    if(!(G.edge_at(0) == e4)) { //il primo arco (numero 0) deve essere e4 (che sarebbe e1)
        std::cout<< "Test 11 fallito: edge_at non corretto" <<"\n";
        return 1;
    }
    std::cout<< "Test 11 superato: edge_at corretto"<< "\n";
    
    //Test 12: costruttore di default
    unidirected_graph<int> G_vuoto;
    if(G_vuoto.all_edges().size() != 0 || G_vuoto.all_nodes().size() != 0) {
        std::cout<< "Test 12 fallito: il costruttore di default non crea un grafo vuoto" <<"\n";
        return 1; 
    }
    std::cout<< "Test 12 superato: il costruttore di default crea un grafo vuoto" << "\n";

    //Test 13:costruttore di copia
    unidirected_graph<int> G2 = G;
    std::set<int> nodi2 = G2.all_nodes();
    if(G2.all_edges().size() != 3 || G2.all_nodes().size() != 3 || nodi2.find(1) == nodi2.end() || nodi2.find(2) == nodi2.end() || nodi2.find(3) == nodi2.end()) {
        std::cout << "Test 13 fallito: il costruttore di copia non ha copiato correttamente il grafo" <<"\n";
        return 1;
    }

    //controlliamo che la copia sia indipendente
    G2.add_edge(3,4);
    if(G.all_edges().size() != 3) {
        std::cout << "Test 13 fallito: il costruttore di copia non ha fatto una copia indipendente" <<"\n";
        return 1;
    }

    std::cout<< "Test 13 superato: il costruttore di copia ha fatto una copia indipendente" << "\n";

    //Test 14: operator-
    unidirected_graph<int> G3;
    G3.add_edge(1,2); //aggiungo un arco presente in G
    G3.add_edge(2,4); //aggiungo un arco che non c'è in G
    unidirected_graph<int> G_diff = G - G3;
    if(G_diff.all_edges().size() != 2) { // devono rimanere solo (2,3) e (1,3)
        std::cout << "Test 14 fallito: operator - non è corretto" <<"\n";
        return 1;
    }

    unidirected_edge<int> e5(1,2);
    if(G_diff.edge_number(e5) != -1){ //dovrebbe dare -1 perché non deve trovare l'arco nel grafo
        std::cout << "Test 14 fallito: operator - non ha rimosso correttamente l'arco" <<"\n";
        return 1;
    }

    std::cout<< "Test 14 superato: operator - corretto" <<"\n";

    std::cout<< "Tutti i test sono stati superati" << "\n";
    return 0;

}