#include <iomanip>
#include <iostream>
#include <string>
#include <memory>

class control {
  int id_;
  std::string text_;
  int width_;
  int height_;
  bool visible_;

 public:
  control::control(int id, std::string_view text = "", int width = 0, int height = 0, bool visible = false)
      : id_(id), text_(text), width_(width), height_(height), visible_(visible) {}
  control(const control_properties& cp)
      : id_(cp.id_), text_(cp.text_), width_(cp.width_), height_(cp.height_), visible_(cp.visible_) {}
};

class control_properties {
  int id_;
  std::string text_;
  int width_ = 0;
  int height_ = 0;
  bool visible_ = false;
  friend class control;
 public:
  control_properties(int const id) : id_(id) {}
  control_properties& text(std::string_view t) {
    text_ = t;
    return *this;
  }
  control_properties& width(int const w) {
    width_ = w;
    return *this;
  }
  control_properties& height(int const h) {
    height_ = h;
    return *this;
  }
  control_properties& visible(bool const v) {
    visible_ = v;
    return *this;
  }
};

int main() {
  control c(control_properties(1044).visible(true).width(100).height(200).text("Hello"));
  return 0;
}