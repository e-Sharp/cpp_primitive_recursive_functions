#pragma once

#include <recursive/detail/arity.hpp> // rec::detail::arity_v
#include <recursive/aliases.hpp> // rec::arr

#include <utility> // std::forward

// Provides a handy facility to evaluate recursive constructions.

namespace rec {

template<typename F, typename... Args> constexpr
nat eval(const F& f, Args&&... args) {
    static_assert(detail::arity_v<F> == sizeof...(Args),
        "eval<F, ...Args>: Argument count must be equal to function arity.");
    auto packed_args = arr<detail::arity_v<F>>{std::forward<Args>(args)...};
    return f(packed_args)[0];
}

} // namespace rec
