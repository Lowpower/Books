#include <type_traits>
#include <typeinfo>
#include <iostream>
#include <cxxabi.h>
#include <memory>

template <typename T>
std::string type_name() {
  // using TR = std::remove_reference_t<T>;
  using TR = T;
  std::unique_ptr<char, void(*)(void*)> own(abi::__cxa_demangle(typeid(TR).name(), nullptr, 0, nullptr), std::free);
  std::string r = own != nullptr ? own.get() : typeid(TR).name();
  if (std::is_const_v<TR>) {
    r += " const";
  }
  if (std::is_volatile_v<TR>) {
    r += " volatile";
  }
  if (std::is_lvalue_reference_v<TR>) {
    r += " &";
  }
  if (std::is_rvalue_reference_v<TR>) {
    r += " &&";
  }
  return r;
}

template<typename T>
void Func(T&& t) {
  std::cout << type_name<T&&>() << std::endl;
}


int main() {
  std::string str = "test";
  Func(str);
  Func(std::move(str));
}