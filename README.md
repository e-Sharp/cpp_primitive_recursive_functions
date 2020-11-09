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
auto Sum = Rec(Pi<1, 1>, Comp(S, Pi<3, 3>));
std::cout << eval(Sum, 17, 13); // Prints 30.
```

See more examples in below.

## Adaptating this to your own needs

You can, according to the MIT licence, do almost whatever you want with this library.
For example you might want to adapt it to your own conventions - naming, parameter order - or to provide additional facilities.

In order to do that, you can just fork this repository, modify it and redistribute it.

It might get a little difficult if you're not familiar with C++ so don't hesitate to ask.

# Examples

```cpp
auto And = Rec(F<1>, Pi<2, 3>);
auto Or = Rec(I, T<3>);
auto Not = Rec(T<0>, F<2>);

auto P = Rec(O<0>, Pi<1, 2>);

auto Sum = Rec(Pi<1, 1>, Comp(S, Pi<3, 3>));
auto TDiff = Comp(Rec(Pi<1, 1>, Comp(P, Pi<3, 3>)), Pi<2, 2>, Pi<1, 2>);
auto AbsDiff = Comp(Sum, TDiff, Comp(TDiff, Pi<2, 2>, Pi<1, 2>));

auto Prod = Rec(O<1>, Comp(Sum, Pi<2, 3>, Pi<3, 3>));
auto Fact = Rec(One<0>, Comp(Prod, Comp(S, Pi<1, 2>), Pi<2, 2>));

auto Eq = Comp(Not, AbsDiff);

auto Mod = Rec(O<1>, Comp(If, Comp(Eq, Comp(S, Pi<3, 3>), Pi<2, 3>), O<3>, Comp(S, Pi<3, 3>)));
auto Div = Comp(Not, Mod);
auto Prim = Comp(Eq, Comp(S, Comp(Rec(O<1>, Comp(Sum, Comp(Div, Pi<2, 3>, Pi<1, 3>), Pi<3, 3>)), I, I)), Two<1>);
```

You can find more examples in `recursive/examples.hpp`.

# Compatibility

It requires a compiler supporting some early C++20 features.

It was developped under `MSVC 19.27`.
As of now some work may be required to make it work under a different compiler - please do not hesitate to submit an issue or a PR.

# Future

I don't have any further plan for this library.
You're welcome to suggest anything.

I will still look at issues and PRs so don't hesitate to submit one.

## Possible improvements

### Lazy primitive recursion

Every single term is evaluated whether it used or not. This will induces an overhead for all functions but `O<0>`, `S` and `Min`.

I did not find a way to implement lazy evaluation which wouldn't break the syntax or compile-time evaluation.

**Giving up the syntax:** Functions would return lambdas instead of values.
But lambda types are implementation defined and vary from one lambda to another.
Therefore any crafted function would need to become variadic. Alas syntax is too important for educational purposes to be discarded and I didn't have the courage to look into macros.

**Giving up compile-time evaluation:** Functions would return `std::function<nat()>` instead of values. This is the most straightforward way and probably the most reasonnable one as compile-time is more of a whim of mine.

### Older standards compatibility

*C++17* compatibility should be easily achievable.

Is *C++14* compatibility straightforward enough ?

### Single header library

This more of a CI task. Having a single header generated would facilitate integration.

# Origin

I made this library while following a class on calculability in my master's degree during the autumn semester of 2020. We had some exercises on paper so I decided to make a programming library in order both to verify my solutions and make it more fun.

While using a functional language would have been a much wiser choice - and much faster and easier -, I happen to quite fancy C++; that's it. I got to try some recent and advanced features which was really interesting.

It was made over a span of less than a week.

# Contact

You can contact me on my mail or on my twitter for whatever reason - links on my profile.
