#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
    double ad[4] = {0.0, 1.1, 2.2, 3.3};
    float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    int ai[3] = {0, 1, 2};

    int x = 1;
    float y = 1.1;

    (&y)[1] = 0;
    
    std::cout << x << "\n";

    std:: cout << "Indirizzo di x è " << &x << "\n";
    std:: cout << "Indirizzo di y è " << &y << "\n";
    std:: cout << "Indirizzo di ad è " << &ad << "\n";
    std:: cout << "Indirizzo di af è " << &af << "\n";
    std:: cout << "Indirizzo di ai è " << &ai << "\n";

    static const int N = 10;
    double arr[N] = {1.14, 4.53, 7.61, 9.2, 2.3, 8.5, 3.11, 5.5, 6, 0.99};

    double somma = 0;
    double minimo = arr[0];
    double massimo = arr[0];
    for (int i = 0; i < N; i++) {
        somma += arr[i];
        minimo = std::min(minimo, arr[i]);
        massimo = std::max(massimo, arr[i]);
        }
    
    double media = somma / N;
    double sommatoria = 0;
    for (int i = 0; i < N; i++) {
        double differenza = arr[i]-media;
        double quadrato = differenza * differenza;
        sommatoria += quadrato;
        }


    double var = sommatoria / N;
    double deviazione = std::sqrt(var);

    std:: cout << "La lunghezza del vettore è " << N << "\n";
    //std:: cout << "Il minimo del vettore è " << *std::min_element(arr, arr + N) << "\n";
    //std:: cout << "Il massimo del vettore è " << *std::max_element(arr, arr + N) << "\n";
    std:: cout << "Il minimo del vettore è " << minimo << "\n";
    std:: cout << "Il massimo del vettore è " << massimo << "\n";
    std:: cout << "La media del vettore è " << media << "\n";
    std:: cout << "La deviazione standard è " << deviazione << "\n";

    double* newarray = new double[N];
        for (int i = 0; i < N; i++) {
            newarray[i] = arr[i];
            }
            int contatore = 1;
            while(contatore > 0){
                contatore = 0;
                    for (int i = 0; i < N-1; i++) {
                        if (newarray[i] > newarray[i+1]){
                            double min= newarray[i+1];
                            double max= newarray[i];
                            newarray[i]=min;
                            newarray[i+1]=max;
                            contatore +=1;
                            }
                        }

                }
    std:: cout << "Il vettore ordinato è ";
    for (int i = 0; i < N; i++) {
        std:: cout << newarray[i]<< " ";
        }
    

    
    return 0;

}