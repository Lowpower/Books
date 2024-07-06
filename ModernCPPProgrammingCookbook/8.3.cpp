#include <mutex>

class foo_rec {
  std::recursive_mutex mutex;
  int data;
 public:    
  foo_rec(int d = 0) : data(d) {}
  void update(int d) {
    std::lock_guard<std::recursive_mutex> lock(mutex);
    data = d;
  }

  int update_with_return(int d) {
    std::lock_guard<std::recursive_mutex> lock(mutex);
    auto old_value = data;
    update(d);
    return old_value;
  }
};

class foo {
  std::mutex x;
  int data;
  void internal_update(int d) {
    data = d;
  }
 public:
  foo(int d = 0) : data(d) {}
  void update(int d) {
    std::lock_guard<std::mutex> lock(x);
    internal_update(d);
  }
  int update_with_return(int d) {
    std::lock_guard<std::mutex> lock(x);
    auto old_value = data;
    internal_update(d);
    return old_value;
  }
};

int main() {
  return 0;
}