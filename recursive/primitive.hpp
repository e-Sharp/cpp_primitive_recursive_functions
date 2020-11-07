#pragma once

#include <recursive/detail/parallel_evaluation.hpp> // detail::parallel_evaluation
#include <recursive/aliases.hpp>

#include <algorithm> // std::copy
#include <array>
#include <iostream>
#include <span>
#include <tuple> // std::make_tuple

namespace rec {

// Constant function
template<std::size_t Arity> constexpr
arr<1> O(span<Arity>) {
    return {0};
}

// Successor function
constexpr
arr<1> S(span<1> s) {
    return {s[0] + 1};
}

// Projection function
// Mathematician indexing [1, n]
template<std::size_t Ith, std::size_t Arity> constexpr
arr<1> Pi(span<Arity> s) {
    static_assert(Ith > 0 && Ith <= Arity,
        "Pi<Ith, Arity>: Template parameter Ith must belong to [1, Arity].");
    return {s[Ith - 1]};
}

// Composition
template<typename F, typename... Gs> constexpr
auto Comp(const F& f, Gs&&... gs) {
    static_assert(detail::arity_v<F> == sizeof...(Gs));
    // Capture by copy to avoid dangling references.
    // I had to write 'f = f' otherwise constexpr would fail on MSVC (?).
    return [f = f, gs = std::make_tuple(std::forward<Gs>(gs)...)]
        (span<detail::arity_v<Gs...>> input) constexpr -> arr<1>
    {
        return {f(detail::parallel_evaluation(gs, input))};
    };
}

// Recursion
// Performances could be improved by lazy evaluating reccurence term.
template<typename B, typename H> constexpr
auto Rec(const B& b, const H& h) {
    static_assert(detail::arity_v<B> + 2 == detail::arity_v<H>,
        "Rec<B, H>: Incoherent arity of parameters. 'arity of h' must be equal to 'arity of b + 2'.");
    return [b = b, h = h](span<detail::arity_v<B> + 1> input) -> arr<1> {
        auto h_input = arr<detail::arity_v<B> + 2>{};
        std::copy(std::begin(input) + 1, std::end(input), std::begin(h_input) + 1); 
        h_input[detail::arity_v<B> + 1] = b(input.subspan<1>())[0];
        while(h_input[0] < input[0]) {
            h_input[detail::arity_v<B> + 1] = h(h_input)[0];
            h_input[0] += 1;
        }
        return {h_input[detail::arity_v<B> + 1]};
    };
}

} // namespace rec
