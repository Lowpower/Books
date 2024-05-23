#include <utility>

template <typename TbooleanCont, typename TFunCont>
struct CompileTimeSwitch_;

template <bool curBool, bool... Tbools, template <typename...> class TFunCont,
          typename currFunc, typename... TFuncs>
struct CompileTimeSwitch_<std::integer_sequence<bool, curBool, Tbools...>, TFunCont<currFunc, TFuncs...>> {
  static_assert((sizeof...(Tbools) == sizeof...(TFuncs)) || 
    (sizeof...(Tbools) + 1 == sizeof...(TFunCont)));
    using type = typename conditional_t<curBool, Identity_<curFunc>,
      CompileTimeSwitch_<std::integer_sequence<bool, Tbools...>, TFunCont<TFuncs...>>>::type;
};

template<template<typename...> class TFunCont, typename currFunc>
struct CompileTimeSwitch_<std::integer_sequence<bool>, TFunCont<currFunc>> {
  using type = currFunc;
};

template<typename TBooleanCont, typename TFunCont>
using CompileTimeSwitch = typename CompileTimeSwitch_<TBooleanCont, TFunCont>::type;

using ChooseResult = CompileTimeSwitch<std::integer_sequence<bool, Cond1, ..., CondN>, Cont<Res1, ..., ResN(, Def)>>;