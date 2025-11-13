#include "Vector.hpp"
#include "LinkedList.hpp"
#include <iostream> 

int main(){
    LinkedList<int> list = {1, 2, 3, 4};
    std::cout << list.get_top() << " " << list.get_last() << "\n";
    LinkedList<int> list2 = {33, 55, 44};
    list = list2;
    LinkedList<int> l3{list2};
    std::cout << list2.get_top() << " " << list2.get_last() << "\n";
    std::cout << l3.get_top() << " " << l3.get_last() << "\n";

}
