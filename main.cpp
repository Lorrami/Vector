#include "Vector.h"

#include <iostream>

int main()
{
    Vector<int> list;
    list.Add(12);
    list.Add(13);
    list.Add(14);
    list.Add(15);
    list.Add(16);
    list.Add(17);

    //list.Remove(6);
    list.Remove(2);

    for (auto it : list)
        std::cout << it << std::endl;

    Vector<std::string> stringList;
    stringList.Add("Gray");
    stringList.Add("Red");
    stringList.Add("Blue");
    stringList.Add("Green");
    stringList.Add("Yellow");
    stringList.Add("Black");

    //list.Remove(6);

    for (auto it : stringList)
        std::cout << it << std::endl;
}
