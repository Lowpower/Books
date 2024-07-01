#include <iostream>

class Singleton {
 public:
  static Singleton& instance() {
    static Singleton s;
    return s;
  }
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;
  Singleton(Singleton&&) = delete;
  Singleton& operator=(Singleton&&) = delete;
 private:
  Singleton() = default;
};

template<typename T>
class SingletonBase {
 protected:
  SingletonBase() = default;
 public:
  static T& instance() {
    static T s;
    return s;
  }
  SingletonBase(const SingletonBase&) = delete;
  SingletonBase& operator=(const SingletonBase&) = delete;
  SingletonBase(SingletonBase&&) = delete;
  SingletonBase& operator=(SingletonBase&&) = delete;
};

class Single : public SingletonBase<Single> {
 private:
  Single() = default;
  friend class SingletonBase<Single>;
 public:
  void foo() {
    std::cout << "foo" << std::endl;
  }
};

int main() {
  return 0;
}