#pragma once

#include <recursive/primitive.hpp>

namespace rec {

// N-ary constants.
template<std::size_t Arity>
constexpr auto One = Comp(S, O<Arity>);

template<std::size_t Arity>
constexpr auto Two = Comp(S, One<Arity>);

template<std::size_t Arity>
constexpr auto Three = Comp(S, Two<Arity>);

// ...

// Defining N-ary constant in terms of 0-ary constant - for reference.

constexpr auto O1 = Rec(O<0>, Pi<2, 2>);
constexpr auto O2 = Rec(O1, Pi<3, 3>);
constexpr auto O3 = Rec(O2, Pi<4, 4>);
// ...

} // namespace rec
