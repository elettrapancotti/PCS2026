#include <iostream> //per std::cout
#include <Eigen/Dense> //per matrici e vettori
#include "gradiente_coniugato.hpp"

int main(){

    const double tol = 1.0e-15; //tolleranza per il determinante di B
    const unsigned int n = 3; //dimensione della mia matrice

    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n,n);  //creo una matrice casuale nxn

    if(abs(B.determinant()) < tol){ //controllo che la matrice non sia quasi singolare
        return -1;
    }

    Eigen::MatrixXd A = B.transpose() * B; //  A = BtB sommetrica e definita positiva per costruzione
    Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n); //soluzione esatta
    Eigen::VectorXd b = A * x_ex; //termine noto costruito dalla soluzione esatta
    
    const unsigned int it_max = 10000; //iterazioni massime
    const double res_tol = 1.0e-12; //per il criterio di arresto del gc
    unsigned int it = 0; //verrà modificato tramite riferimento dentro gradiente_coniugato



    Eigen::VectorXd x = gradiente_coniugato(A, b, res_tol, it_max, it);

    const Eigen::VectorXd res = b - A * x; //residuo finale
    const double res_norm = res.norm();
    const double res_norm_0 = b.norm(); //norma del residuo iniziale (x0 = 0 quindi r0= b-0 = b)

    const auto err_rel = (x_ex.norm()==0) ? (x-x_ex).norm() : (x-x_ex).norm() / (x_ex).norm();   //if-else compatto se la soluzione esatta è il vettore di zeri usa l'errore assoluto anziché il relativo affinché non ci sia 0 a denominatore

    std::cout.precision(4);
    std::cout<<std::scientific<< "it"<<"/"<<"it_max"<<std::endl; //end line va a capo e svuota il buffer (zona di memoria temporanea che accumula i dati prima di scriverli sull'ouput)
    std::cout<<std::scientific<< it <<"/"<< it_max <<std::endl; //se non sono state raggiunge le it max (allora il res relativo è minore dellla tolleranza) il metodo ha converso
    std::cout<< std::scientific<< "res"<< "/"<< "res_tol"<< std::endl;
    std::cout<< std::scientific<< res_norm / res_norm_0<< "/"<< res_tol<< std::endl; //residuo relativo(res finale/res iniziale)  / tolleranza   //se è minore il metodo ha converso
    std::cout<< std::scientific<< "err_rel"<< std::endl;
    std::cout<< std::scientific<< err_rel<< std::endl; //errore relativo tra soluzione calcolata e soluzione esatta
    std::cout<< std::scientific<< "soluzione"<< std::endl;
    std::cout<< std::scientific<< x << std::endl;

    return 0;
}