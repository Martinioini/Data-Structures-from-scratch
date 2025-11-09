#include "Vector.hpp"
#include <iostream> 

int main(){
    Vector<int> v(15);
    for(int i = 0; i < 1000; i++){
        v.push_back(4);
    }      
    std::cout << v.pop() << "Negro \n";
    for(int i = 0; i < 1000; i++){
        std::cout << v.pop() << i << "Negro \n";
    }
}
