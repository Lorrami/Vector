#include "Vector.h"

#include <iostream>

int main()
{
    Vector<int> intList;
    intList.Add(12);
    intList.Add(13);
    intList.Add(14);
    intList.Add(15);
    intList.Add(16);
    intList.Add(17);

    intList.Remove(2);

    for (auto it : intList)
        std::cout << it << std::endl;

    Vector<std::string> stringList;
    stringList.Add("Gray");
    stringList.Add("Red");
    stringList.Add("Blue");
    stringList.Add("Green");
    stringList.Add("Yellow");
    stringList.Add("Black");

    for (auto it : stringList)
        std::cout << it << std::endl;

    Vector<int> testList = intList;
    //testList.Add(345);
    for (auto it : testList)
        std::cout << it << std::endl;

    return 777;
}
