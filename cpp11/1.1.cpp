
void func(auto a = 1) {}

struct Foo {
  auto var1_ = 0;
  static const auto var2_ = 0;
};

template <typename T>
struct Bar{};

int main() {
  int arr[10] = {0};
  auto aa = arr;
  auto rr[10] = arr;
  Bar<int> bar;
  Bar<auto> bb = var;
  return 0;
}