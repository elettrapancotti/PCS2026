#include<string>
#include<iostream>
#include<cmath>

template<typename I> requires std::integral<I>
class rational{
    I num_;
    I den_;
    std:: string controllo_;
    
private:
    //Massimo comune divisore
    I mcd(I a, I b) {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            I r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    //riduce ai minimi termini
    void simplify(){
        if (den_==0) return;
        I g = mcd(num_, den_);
        num_ /= g;
        den_ /= g;
        if (den_ <0){
            num_ = -num_;
            den_ = -den_;
        }
    }

public:
    //verifica se è infinito o indefinita
    rational(): num_(0), den_(1), controllo_(""){}
    rational(I n, I d) : num_(n), den_(d) {
        if(den_==0 && num_==0){
            controllo_ = "NaN";
        }
        else if(den_==0 && num_>0) {
            controllo_ = "Inf";
        }
        else{
            simplify();
        }
    }

    //stampa il numero razionale
    //friend permette di violare l'incapsulamento e accedere a membri privati
    friend std::ostream&
    operator<<(std::ostream& os, const rational<I>& r){
        if (r.controllo_ == "NaN" || r.controllo_ == "Inf" ) {
            os<< r.controllo_;
        }
        else if (r.num_ == 0){
            os<< "0";
        }
        else{
            os<< r.num_ << "/" << r.den_;
        }
    return os;
    }

    //stampa numeratore e denominatore getter
    I num() const {return num_;}
    I den() const {return den_;}
    std::string controllo() const {return controllo_;}

    //somma con incremento
    rational& operator+=(const rational& other) {
        if(controllo_== "NaN" || other.controllo_ == "NaN") {
            *this = rational(0,0);

        }
        else if (controllo_=="Inf" || other.controllo_ == "Inf") {
            *this = rational(1,0);
        }
        else{
            num_ = (num_*other.den_)+(other.num_*den_);
            den_ = den_*other.den_;
            simplify();
        }
        return *this;
    }
    //somma
    rational operator+(const rational& other) const {
        rational ret;
        if(controllo_== "NaN" || other.controllo_ == "NaN") {
            ret = rational(0,0);

        }
        else if (controllo_=="Inf" || other.controllo_ == "Inf") {
            ret = rational(1,0);
        }
        else{
            ret = *this;
            ret += other;   
        }
        return ret;
    }

    //differenza con decremento
    rational& operator-=(const rational& other) {
        if(controllo_== "NaN" || other.controllo_ == "NaN") {
            *this = rational(0,0);
        }
        else if (controllo_=="Inf" && other.controllo_ == "Inf") {
            *this = rational(0,0);
        }
        else if (controllo_=="Inf" || other.controllo_ == "Inf") {
            *this = rational(1,0);
        }
        else{
            num_ = (num_*other.den_)-(other.num_*den_);
            den_ = den_*other.den_;
            simplify();
        }
        return *this;
    }

    //differenza
    rational operator-(const rational& other) const {
        rational ret;
        if(controllo_== "NaN" || other.controllo_ == "NaN") {
            ret = rational(0,0);
        }
        else if (controllo_=="Inf" && other.controllo_ == "Inf") {
            ret = rational(0,0);
        }
        else if (controllo_=="Inf" || other.controllo_ == "Inf") {
            ret = rational(1,0);
        }
        else{
            ret = *this;
            ret -= other;
        }
        return ret;
    }
    //prodotto con modifica
    rational& operator*=(const rational& other) {
        if(controllo_== "NaN" || other.controllo_ == "NaN") {
            *this = rational(0,0);
        }
        else if ((controllo_=="Inf" && other.num_ == 0) || (num_== 0 && other.controllo_ == "Inf")) {
            *this = rational(0,0);
        }
        else if (controllo_=="Inf" || other.controllo_ == "Inf") {
            *this = rational(1,0);
        }
        else{
            num_ = num_*other.num_;
            den_ = den_*other.den_;
            simplify();
        }
        return *this;
    }

    //prodotto
    rational operator*(const rational& other) const {
        rational ret;
        if(controllo_== "NaN" || other.controllo_ == "NaN") {
            ret = rational(0,0);
        }
        else if ((controllo_=="Inf" && other.num_ == 0) || (num_== 0 && other.controllo_ == "Inf")) {
            ret = rational(0,0);
        }
        else if (controllo_=="Inf" || other.controllo_ == "Inf") {
            ret = rational(1,0);
        }
        else{
            ret = *this;
            ret *= other;
        }
        return ret;
    }
    //divisione con modifica
    rational& operator/=(const rational& other) {
        if(controllo_== "NaN" || other.controllo_ == "NaN") {
            *this = rational(0,0);
        }
        else if (controllo_=="Inf" && other.controllo_ == "Inf") {
            *this = rational(0,0);
        }
        else if (controllo_=="Inf" && other.controllo_ !="Inf") {
            *this = rational(1,0);
        }
        else if (controllo_ !="Inf" && other.controllo_ =="Inf") {
            *this = rational(0,1);
        }
        else if (other.num_ == 0) {
            *this = rational(0,0);
        }
        else{
            num_ = num_*other.den_;
            den_ = den_*other.num_;
            simplify();
        }
        return *this;
    }

    //divisione
    rational operator/(const rational& other) const {
        rational ret;
        ret = *this;
        ret /= other;
        return ret;
    }


};

