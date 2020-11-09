#pragma once

#include <recursive/primitive.hpp>

namespace rec {

// Natural to boolean conversion.
constexpr auto B = Rec(O<0>, Comp(Comp(S, O<1>), Pi<1, 2>));

// Constants.

// N-ary true constant.
template<std::size_t Arity>
constexpr auto T = Comp(S, O<Arity>);

// N-ary false constant.
template<std::size_t Arity>
constexpr auto F = O<Arity>;

// Basic operations.

constexpr auto And = Rec(F<1>, Pi<2, 3>);

constexpr auto Or = Rec(Pi<1, 1>, T<3>);

constexpr auto Not = Rec(T<0>, F<2>);

// Secondary operations.

constexpr auto Xor = Rec(Pi<1, 1>, Comp(Not, Pi<2, 3>));

constexpr auto Impli = Rec(T<1>, Pi<2, 3>);

constexpr auto Equiv = Rec(Comp(Not, Pi<1, 1>), Pi<2, 3>);

} // namespace rec
