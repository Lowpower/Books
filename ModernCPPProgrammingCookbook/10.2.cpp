#include <iomanip>
#include <iostream>
#include <string>
#include <memory>

class control {
  std::string text;
  int width = 0;
  int height = 0;
  bool visible = true;

  void draw() {
    std::cout << "control \n visable:" << std::boolalpha << visible
              << std::noboolalpha << "\n size: " << width << "," << height
              << "\n text: " << text << std::endl;
  }
 public:
  void set_text(std::string_view t) {
    text = t.data();
    draw();
  }

  void resize(int w, int h) {
    width = w;
    height = h;
    draw();
  }

  void show() {
    visible = true;
    draw();
  }

  void hide() {
    visible = false;
    draw();
  }
};

class control_pimpl;

class control_p {
  std::unique_ptr<control_pimpl, void (*)(control_pimpl *)> impl;

 public:
  control_p();
  void set_text(std::string_view t);
  void resize(int w, int h);
  void show();
  void hide();
};

control_p::control_p()
    : impl(new control_pimpl, [](control_pimpl *p) { delete p; }) {}

control_p::~control_p() = default;

void control_p::set_text(std::string_view t) { impl->set_text(t); }

void control_p::resize(int w, int h) { impl->resize(w, h); }

void control_p::show() { impl->show(); }

void control_p::hide() { impl->hide(); }

class control_pimpl {
  std::string text;
  int width = 0;
  int height = 0;
  bool visible = true;
  void draw() {
    std::cout << "control \n visable:" << std::boolalpha << visible
              << std::noboolalpha << "\n size: " << width << "," << height
              << "\n text: " << text << std::endl;
  }
 public:
  void set_text(std::string_view t) {
    text = t.data();
    draw();
  }

  void resize(int w, int h) {
    width = w;
    height = h;
    draw();
  }

  void show() {
    visible = true;
    draw();
  }

  void hide() {
    visible = false;
    draw();
  }
};

class control_copyable {
  std::unique_ptr<control_pimpl, void (*)(control_pimpl *)> impl;

 public:
  control_copyable();
  control_copyable(const control_copyable &);
  control_copyable &operator=(const control_copyable &);
  control_copyable(control_copyable &&) noexcept;
  control_copyable &operator=(control_copyable &&) noexcept;

  void set_text(std::string_view t);
  void resize(int w, int h);
  void show();
  void hide();
};

control_copyable::control_copyable()
    : impl(new control_pimpl, [](control_pimpl *p) { delete p; }) {}

control_copyable::control_copyable(const control_copyable &other)
    : impl(new control_pimpl(*other.impl), [](control_pimpl *p) { delete p; }) {}

control_copyable::control_copyable(control_copyable &&other) noexcept = default;

control_copyable &control_copyable::operator=(const control_copyable &other) {
  if (this != &other) {
    impl = std::unique_ptr<control_pimpl, void (*)(control_pimpl *)>(
        new control_pimpl(*other.impl), [](control_pimpl *p) { delete p; });
  }
  return *this;
}

control_copyable &control_copyable::operator=(control_copyable &&other) noexcept =
    default;

int main() { return 0; }