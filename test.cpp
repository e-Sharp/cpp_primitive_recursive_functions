#include <recursive/example/all.hpp>
// #include <recursive/primitive.hpp>

#include <iostream>

using namespace rec;

int main() {
    std::cout << eval(Impli, 0u, 0u) << std::endl;
    std::cout << eval(Impli, 0u, 1u) << std::endl;
    std::cout << eval(Impli, 1u, 0u) << std::endl;
    std::cout << eval(Impli, 1u, 1u) << std::endl;
    
}
