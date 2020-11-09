#pragma once

#include <recursive/example/constants.hpp>
#include <recursive/primitive.hpp>

namespace rec {

constexpr auto P = Rec(O<0>, Pi<1, 2>);

constexpr auto Sum = Rec(Pi<1, 1>, Comp(S, Pi<3, 3>));

// Truncated difference.
constexpr auto TDiff = Comp(Rec(Pi<1, 1>, Comp(P, Pi<3, 3>)), Pi<2, 2>, Pi<1, 2>);

constexpr auto Prod = Rec(O<1>, Comp(Sum, Pi<2, 3>, Pi<3, 3>));

constexpr auto Pow = Comp(Rec(One<1>, Comp(Prod, Pi<2, 3>, Pi<3, 3>)), Pi<2, 2>, Pi<1, 2>);

} // namespace rec
