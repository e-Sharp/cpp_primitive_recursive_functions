#pragma once

#include <algorithm> // std::copy
#include <array> // std::array, std::begin, std::end
#include <span> // std::span, std::begin, std::end

namespace rec {
namespace detail {

template<typename Ty, std::size_t N> constexpr
std::array<Ty, N + 1> pushed_front_as_array(
    std::span<const Ty, N> s, const Ty& e)
{
    auto a = std::array<Ty, N + 1>{e};
    std::copy(std::begin(s), std::end(s), std::begin(a) + 1);
    return a;
}

} // namespace detail
} // namespace rec
