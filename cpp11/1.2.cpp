
class Foo {
 public:
  static int get() {
    return 0;
  }
};

class Bar {
 public:
  static const char* get() {
    return "0";
  }
};

template<typename A>
void func() {
  auto val = A::get();
}

int main() {
  func<Foo>();
  func<Bar>();
  return 0;
}