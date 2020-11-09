#pragma once

#include <recursive/primitive.hpp>

namespace rec {

// If x1 then x2 else x3.
constexpr auto If = Rec(Pi<2, 2>, Pi<2, 4>);

} // namespace rec
