#include "set.h"

#include <iostream>
// using namespace std;
// using namespace s21;

int main() {
    // std::initializer_list<int> items{1,2,3};
    // std::initializer_list<int> items2{4,5,6};
    s21::set<int> my_set{1,2,3};

    s21::set<int> my_set2{4,3,6};
    my_set.merge(my_set2);
    auto my_iter = my_set.begin();
    while(my_iter!=my_set.end()) {
        // ASSERT_TRUE(*my_iter == *std_iter);
        // ++std_iter;
        std::cout << *my_iter << std::endl; 
        ++my_iter;
    }
    
    return 0;
}