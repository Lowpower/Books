#include <iostream>
#include <memory>
#include <vector>
#include <string_view>
#include <ranges>

class control {
 private:
  virtual void paint() = 0;

 protected:
  virtual void erase_background() {
    std::cout << "erasing background" << std::endl;
  }
  virtual void initialize_impl() {
    std::cout << "initializing control" << std::endl;
  }

 public:
  void initialize() {
    initialize_impl();
  }
  void draw() {
    erase_background();
    paint();
  }
  virtual ~control() = default;
};

class button : public control {
 private:
  virtual void paint() override {
    std::cout << "painting button" << std::endl;
  }

 protected:
  virtual void erase_background() override {
    control::erase_background();
    std::cout << "erasing button background" << std::endl;
  }
  virtual void initialize_impl() override {
    control::initialize_impl();
    std::cout << "initializing button" << std::endl;
  }
};

class checkbox : public button {
 private:
  virtual void paint() override {
    std::cout << "painting checkbox" << std::endl;
  }

 protected:
  virtual void erase_background() override {
    button::erase_background();
    std::cout << "erasing checkbox background" << std::endl;
  }
};

int main() {
  std::cout << "GCC version: " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << std::endl;
  std::vector<std::unique_ptr<control>> controls;
  controls.emplace_back(std::make_unique<button>());
  controls.emplace_back(std::make_unique<checkbox>());
  for (const auto &c : controls) {
    c->draw();
  }
  return 0;
}