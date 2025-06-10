// liadi.haim@gmail.com
#include "MyContainer.hpp"
#include <iostream>
#include <string>

using namespace MyNamespace;
using std::cout, std::endl;

template<typename It>
void print_range(It begin, It end) {
    for (auto it = begin; it != end; ++it) cout << *it << ' ';
    cout << endl;
}

int main() {
    cout << "=== MyContainer Demo ===\n";

    
    MyContainer<int> cont;               
    for (int v : {7, 15, 6, 1, 2}) cont.add(v);

    cout << "Original  : " << cont   << endl;
    cout << "Size      : " << cont.size() << endl;

    cout << "\n=== Iterator Tests ===\n";

    cout << "Ascending : ";
    MyContainer<int>::AscendingOrder asc(cont);
    print_range(asc.begin(), asc.end());

    // DescendingOrder 
    cout << "Descending: ";
    MyContainer<int>::DescendingOrder desc(cont);
    print_range(desc.begin(), desc.end());

    // SideCrossOrder 
    cout << "SideCross : ";
    MyContainer<int>::SideCrossOrder cross(cont);
    print_range(cross.begin(), cross.end());

    // ReverseOrder 
    cout << "Reverse   : ";
    MyContainer<int>::ReverseOrder rev(cont);
    print_range(rev.begin(), rev.end());

    // Order 
    cout << "Order : ";
    MyContainer<int>::Order ord(cont);
    print_range(ord.begin(), ord.end());

    // MiddleOutOrder 
    cout << "MiddleOut : ";
    MyContainer<int>::MiddleOutOrder mid(cont);
    print_range(mid.begin(), mid.end());

   
    cout << "\n=== remove(7) ===\n";
    cont.add(7);
    cout << "Before : " << cont << endl;
    cont.remove(7);
    cout << "After  : " << cont << endl;

    
    cout << "\n=== String Container ===\n";
    MyContainer<std::string> scont {"hello", "world", "cpp", "programming"};
    cout << scont << endl;

    cout << "Ascending : ";
    MyContainer<std::string>::AscendingOrder sasc(scont);
    print_range(sasc.begin(), sasc.end());

    cout << "\n=== Double Container ===\n";
    MyContainer<double> dcont {3.14, 2.71, 1.41, 9.81};
    cout << dcont << endl;

    cout << "Descending: ";
    MyContainer<double>::DescendingOrder ddesc(dcont);
    print_range(ddesc.begin(), ddesc.end());

    cout << "\nDemo completed successfully!\n";
    return 0;
}
