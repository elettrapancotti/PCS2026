#include<iostream>
#include"rational.hpp"

int main(){
    rational<int> r1(0,0);
    rational<int> r2(38,-8);
    rational<int> r3(7,3);
    rational<int> r4(-12,-4);
    rational<int> r5(9,0);

    std::cout<<r1<<"\n";
    std::cout<<r2<<"\n";
    std::cout<<r3<<"\n";
    std::cout<<r4<<"\n";
    std::cout<<r5<<"\n";

    std::cout<<"r1+r2= "<<r1+r2<<"\n";
    std::cout<<"r2-r3= "<<r2-r3<<"\n";
    std::cout<<"r3*r4= "<<r3*r4<<"\n";
    std::cout<<"r4/r5= "<<r4/r5<<"\n";

    return 0;
}