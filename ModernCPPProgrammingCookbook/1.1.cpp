#include <atomic>
#include <iostream>
#include <map>
#include <string>
#include <vector>

auto v = std::vector<int>{1, 2, 3};
int size = v.size();

auto size2 = v.size();

auto size3 = int{v.size()};

class foo {
  int x_;

 public:
  foo(int x = 0) : x_{x} {
  }
  int& get() {
    return x_;
  }
};

decltype(auto) proxy_get(foo& f) {
  return f.get();
}

auto ai = std::atomic<int>(42);

using llong = long long;
auto l2 = llong{42};
auto l3 = 42LL;

auto fun1(int i) -> int {
  return i;
}

auto fun2(int i) {
  return i;
}

auto ladd = [] (const auto& a, const auto& b) {
  return a + b;
};

struct {
  template<typename T, typename U>
  auto operator()(T t, U u) const {
    return t + u;
  }
} L;

int main() {
  std::map<int, std::string> m;
  for (auto it = m.begin(); it != m.end(); ++it) {
    std::cout << it->first << " " << it->second << std::endl;
  }
  for (const auto& [key, value] : m) {
    std::cout << key << " " << value << std::endl;
  }

  foo f(42);
  auto x = f.get();
  x = 100;
  std::cout << f.get() << std::endl;
  decltype(auto) xx = proxy_get(f);
  auto l = ladd(1, 2);
  std::cout << l << std::endl;
  return 0;
}