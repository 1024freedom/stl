#include"Map.hpp"
#include<iostream>
int main(){
    Set s;
    s.insert(1);
    s.insert(3);
    s.insert(5);
    std::cout<<s.find(1)->value<<std::endl;
    std::cout<<s.find(3)->value<<std::endl;
    std::cout<<s.find(5)->value<<std::endl;
    return 0;
}