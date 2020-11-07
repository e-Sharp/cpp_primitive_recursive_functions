#include <recursive/all_primitive.hpp>

#include <iostream>

using namespace rec;

auto P = Rec(O<0>, Pi<1, 2>);

auto Plus = Rec(Pi<1, 2>, Comp(S, Pi<3, 3>));

int main() {
    std::cout << eval(P, 10u) << std::endl;
}
