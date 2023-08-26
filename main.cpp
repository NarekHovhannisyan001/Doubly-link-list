#include "List.h"

//#include <iostream>

int main() {
    MyList<int>list;
    list.push_back(4);
    list.push_back(5);
    list.push_front(3);
    list.printList();
    std::cout << "\n";
    list.remove(1);
    list.insert(1,3);
    list.printList();
    std::cout << list.get(2);

}