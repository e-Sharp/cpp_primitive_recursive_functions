#include <recursive/all_general.hpp>

#include <iostream>

using namespace rec;

constexpr auto P = Rec(O<0>, Pi<1, 2>);

constexpr auto Sum = Rec(Pi<1, 1>, Comp(S, Pi<3, 3>));
// Truncated difference.
constexpr auto TDiff = Comp(Rec(Pi<1, 1>, Comp(P, Pi<3, 3>)), Pi<2, 2>, Pi<1, 2>);

int main() {
    constexpr auto Id = Min(Rec(Pi<1, 1>, Comp(P, Pi<3, 3>)));
    std::cout << eval(Id, 17u) << std::endl;
}
