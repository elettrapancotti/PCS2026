#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string filename = "testo1.txt";
    ifstream ifs(filename);
    if ( ifs.is_open() ) { // Check if file successfully opened
        while( !ifs.eof() ) {
        string location;
        double temp1;
        double temp2;
        double temp3;
        double temp4;
        ifs >> location >> temp1 >> temp2 >> temp3 >> temp4; 
        double media = (temp1+temp2+temp3+temp4)/4.0;
        cout << "La temperatura media a " << location << " è di " << media << "\n";
    }
}
return 0;
}