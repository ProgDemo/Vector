#include <iostream>
#include "Standard.h"
#include <vector>

#define NORMAL
#ifdef NORMAL

int main()
{
    Standard::vector<int> vec;
    for (int i = 1; i <= 20; ++i) {
        vec.push_back(i);
    }

    std::cout << vec.getSize() << std::endl;
    for (int i = 0; i < 20; ++i) {
        std::cout << vec[i] << std::endl;
    }

    vec.pop_back();
    vec.pop_back();
    std::cout << vec.pop() << std::endl;

    vec[vec.getSize() - 1] = 456;
    std::cout << vec.pop() << std::endl;

    try {
        vec[21];
    } catch (Standard::vector<int>::VectorExceptions e) {
        if (e == Standard::vector<int>::ArrayIndexOutOfBoundsException) {
            std::cerr << "Index out of bounds!\n";
        }
    }

    std::vector<int> vec2;
    return 0;
}

#else

using namespace std;
using namespace Standard;

int main() {

    vector<int> vec;

}

#endif
