#include "Vector.h"

#include <iostream>

int main()
{
    Vector<int> list;
    list.Add(12);
    list.Add(13);
    list.Add(14);

    std::cout << list;
}
