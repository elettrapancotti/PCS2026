#include<Eigen/Dense> //per matrici e vettori

Eigen::VectorXd gradiente_coniugato(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, const double tol, const unsigned int it_max, unsigned int& it){       //matrixXd vuol dire matrice a righe e colonne dinamiche di double //unsigned dice che non può essere negativo //it viene modificato direttamente tramite riferimento (la funzione riceve un alias alla variabile originale)

    Eigen::VectorXd x = Eigen::VectorXd::Zero(b.size());  //creo il vettore iniziale arbitrario (x0)
    Eigen::VectorXd r = b - A * x; //residuo iniziale (r0)
    Eigen::VectorXd p = r; //direzione iniziale (p0)

    const double r_norm_0 = r.norm(); //norma del residuo iniziale


    while(it < it_max && r.norm() > tol * r_norm_0){ //finché le iterazioni sono minori delle iterazione massime E la norma del residuo è maggiore della tolleranza relativa
        
        const double ptAp = (p.transpose() * A * p).value(); //lo calcolo una volta (pAp) //costante dentro la singola iterazione

        const double alpha_k = (p.transpose()*r).value() / ptAp; //const perche alpha_k è costante nella singola iterazione //.value() converte la matrice 1x1 in scalare
        x = x + alpha_k*p;
        r = b - A * x;

        const  double beta_k = (p.transpose()*A*r).value() / ptAp; //coefficiente per aggiornare la direzione A-ortogonale

        p = r - beta_k * p; //nuova direzione A-ortogonale alle precedenti
        it++;
    
    }

    return x;

}