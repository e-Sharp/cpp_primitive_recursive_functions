#include <recursive/general.hpp>
#include <recursive/all_primitive.hpp>

#include <iostream>

using namespace rec;

auto P = Rec(O<0>, Pi<1, 2>);

auto Sum = Rec(Pi<1, 1>, Comp(S, Pi<3, 3>));
// Truncated difference.
auto TDiff = Comp(Rec(Pi<1, 1>, Comp(P, Pi<3, 3>)), Pi<2, 2>, Pi<1, 2>);

int main() {
    std::cout << eval(Diff, 17u, 13u) << std::endl;
}
