# Primitive Recursive Functions in C++

This library provides facilities to play around with primitive and general recursive functions.
It is designed for educational purposes such that the syntax is as simple and natural as possible.

It also enables important features:
- Strong static typing
- Compile-time evaluation
- Intellegible compilation errors
- Mixing with regular C++ functions

# Usage

This is an header-only library. You need only to include the required headers into your own source files.

Everything is nicely packed into the `rec` namespace.
```cpp
using namespace rec; // To avoid having to prefix it.
```

Include `recursive/primitive.hpp` for *primitive recursive functions*:
- N-ary constant function: `O<N> : N`
- Successor function: `S : 1`
- Projection function: `Pi<I, N> : N`
- Composition: `Comp(f : M, [g : N] ^ M) : N`
- Primitive recursion: `Rec(b : N, h : N + 2) : N + 1`

Note: While the *N-ary constant function* can be crafted from the *0-ary constant function* it is an convenient convention.

Include `recursive/general.hpp` for *general recursive functions*:
- All of the above
- Minimisation: `Min(g : N + 1) : N`

An `eval` function is provided in order to simplify evaluation of *recursive functions* like so:
```cpp
auto Plus = Rec(Pi<1, 1>, Comp(S, Pi<3, 3>));
std::cout << eval(Plus, 17, 13); // Prints 30.
```

See more examples in below.

## Adaptating this for your own needs

You can, according to the MIT licence, do almost whatever you want with this library.
For example you might want to adapt it to your own conventions - naming, parameter order - or to provide additional facilities.

In order to do that, you can just fork this repository, modify it and redistribute it.

It might get a little difficult if you're not familiar with C++ so don't hesitate to ask.

# Examples

// TODO

# Compatibility

It requires a compiler supporting some early C++20 features.

Developped under `MSVC 19.27`.
As of now some work may be required to make it work under a different compiler - please do not hesitate to submit an issue or a PR.

# Future

I don't have any further plan for this library.
You're welcome to suggest anything.

I will still look at issues and PRs so don't hesitate to submit one.

## Possible improvements

### Older standards compatibility

*C++17* compatibility should be easily achievable.

Is *C++14* compatibility straightforward enough ?

### Lazy primitive recursion

The *recursion term* is recursively computed whether the right hand side function uses it or not. This will induces a big overhead in some cases.

For example:
```cpp
    auto P = Rec(O<0>, Pi<1, 2>); // Unused recurrence term.
    eval(P, n); // P will be evaluated for each value in [0, n].
    // n - 1 computations for basically nothin' :(

    // This will also produce suboptimal performances for 'If' function and others.
```

I did not find a way to implement lazy evaluation which wouldn't break the syntax or compile-time evaluation.

**Giving up the syntax:** Functions would return lambdas instead of values.
But lambda types are implementation defined and vary from one lambda to another.
Therefore any crafted function would need to become variadic. This is the most reasonable way in my opinion but syntax is to important to be discarded for educational purposes and I didn't have the courage to look into macros.

**Giving up compile-time evaluation:** Functions would return `std::function<nat()>` instead of values. This is the most straightforward way.

# Origin

I made this library while following a class on calculability in my master's degree during the autumn semester of 2020. We had some exercises on paper so I decided to make a programming library in order both to verify my solutions and make it more fun.

While using a functional language would have been a much wiser choice - and much faster and easier -, I happen to quite fancy C++; that's it. I got to try some recent and advanced features which was really interesting.

It was made over a span of less than a week.

# Contact

You can contact me on my mail or on my twitter for whatever reason - links on my profile.
