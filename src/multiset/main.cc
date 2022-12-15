#include "multiset.h"

using namespace std;

int main() {
    s21::multiset<int> my_multiset{10,50,30,30,60,20,23,40};
    auto iter = my_multiset.begin();
    while (iter!=my_multiset.end()) {
        cout << *iter <<endl;
        ++iter;
    }
    auto a = my_multiset.count(2);
    cout << "number of 2 is " << a << endl;
    auto aa = my_multiset.upper_bound(30);
    cout << *aa << endl;
    return 0;
}
