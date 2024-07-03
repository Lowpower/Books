#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>

inline void print_time() {
  auto now = std::chrono::system_clock::now();
  auto in_time_t = std::chrono::system_clock::to_time_t(now);
  std::cout << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X") << '\n';
}

void func1() {
  std::cout << "thread 1 id: " << std::this_thread::get_id() << '\n';
}

void func2(int i, double d, std::string s) {
  std::cout << "thread 2 id: " << std::this_thread::get_id() << '\n';
  std::cout << "i: " << i << ", d: " << d << ", s: " << s << '\n';
}

void func3(int& i) {
  i *= 2;
}

void func4() {
  using namespace std::chrono;
  print_time();
  std::this_thread::sleep_for(2s);
  print_time();
}

void func5() {
  using namespace std::chrono;
  print_time();
  std::this_thread::sleep_until(system_clock::now() + 2s);
  print_time();
}

void func6(std::chrono::seconds timeout) {
  auto now = std::chrono::system_clock::now();
  auto then = now + timeout;
  do {
    std::this_thread::yield();
  } while (std::chrono::system_clock::now() < then);
}

int main() {
  print_time();
  std::thread t1(func1);
  std::thread t2([]() {
    std::cout << "thread 3 id: " << std::this_thread::get_id() << '\n';
  });
  t1.join();
  t2.detach();
  int n = 42;
  std::thread t3(func3, std::ref(n));
  t3.join();
  std::cout << "n: " << n << '\n';
  std::thread t4(func4);
  t4.join();
  std::thread t5(func5);
  t5.join();
  print_time();
  std::thread t6(func6, std::chrono::seconds(2));
  t6.join();
  print_time();
  return 0;
}