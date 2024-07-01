#include <iostream>
#include <memory>
#include <vector>

template<typename T>
class control {
 public:
  void draw() {
    static_cast<T*>(this)->erase_background();
    static_cast<T*>(this)->paint();
  }
};

class button : public T2::control<button> {
 public:
  void erase_background() { std::cout << "button::erase_background" << std::endl; }
  void paint() { std::cout << "button::paint" << std::endl; }
};

class checkbox : public T2::control<checkbox> {
 public:
  void erase_background() { std::cout << "checkbox::erase_background" << std::endl; }
  void paint() { std::cout << "checkbox::paint" << std::endl; }
};

template<typename T>
void draw_control(control<T> &c) {
  c.draw();
}

namespace T1 {
template<typename T>
class control {
  T* derived() { return static_cast<T*>(this); }
 public:
  void draw() {
    derived()->erase_background();
    derived()->paint();
  }
};
}

namespace T2 {
class control_base {
 public:
  virtual void draw() = 0;
  virtual ~control_base() = default;
};

template<typename T>
class control : public control_base {
 public:
  void draw() override {
    static_cast<T*>(this)->erase_background();
    static_cast<T*>(this)->paint();
  }
};

void draw_controls(std::vector<std::unique_ptr<control_base>> &controls) {
  for (auto &c : controls) {
    c->draw();
  }
}
}

int main() {
  button b;
  // draw_control(b);
  checkbox c;
  // draw_control(c);
  std::vector<std::unique_ptr<T2::control_base>> controls;
  controls.emplace_back(std::make_unique<button>());
  controls.emplace_back(std::make_unique<checkbox>());
  draw_controls(controls);
  return 0;
}