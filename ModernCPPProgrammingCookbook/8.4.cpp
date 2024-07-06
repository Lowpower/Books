#include <exception>
#include <iostream>
#include <mutex>
#include <vector>
#include <thread>

std::vector<std::exception_ptr> g_exceptions;
std::mutex g_mtx;

void func1() {
  throw std::runtime_error("exception from func1");
}

void func2() {
  throw std::runtime_error("exception from func2");
}

void thread_func1() {
  try {
    func1();
  } catch (...) {
    std::lock_guard<std::mutex> lock(g_mtx);
    g_exceptions.push_back(std::current_exception());
  }
}

void thread_func2() {
  try {
    func2();
  } catch (...) {
    std::lock_guard<std::mutex> lock(g_mtx);
    g_exceptions.push_back(std::current_exception());
  }
}

int main() {
  std::thread t1(thread_func1);
  std::thread t2(thread_func2);
  t1.join();
  t2.join();
  for (auto &e : g_exceptions) {
    try {
      if (e != nullptr) {
        std::rethrow_exception(e);
      }
    } catch (const std::exception &ex) {
      std::cerr << ex.what() << std::endl;
    }
  }
g_exceptions.clear();
  return 0;
}


