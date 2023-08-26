#include "List.h"

int main() {
    MyList<int>list;
    list.push_back(4);
    list.push_back(5);
    list.push_front(3);
    MyList<int>list1;
    list1.push_back(3);
    list1.push_back(3);
    list1 = list;
    MyList<int>list2{1,2,3};
    list2.printList();
    MyList<int>list3(list2);
    list3.printList();
    return 0;
}
