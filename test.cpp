#include <recursive/example/all.hpp>
// #include <recursive/primitive_functions.hpp>

#include <iostream>

using namespace rec;

int main() {
    std::cout << eval(Sum, 7u, 3u);
}
