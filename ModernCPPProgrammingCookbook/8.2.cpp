#include <mutex>
#include <thread>
#include <iostream>
#include <vector>

std::mutex g_mutex;

void thread_func() {
  using namespace std::chrono_literals;
  {
    std::lock_guard<std::mutex> lock(g_mutex);
    std::cout << "thread id: " << std::this_thread::get_id() << " entered\n";
  }
  std::this_thread::yield();
  std::this_thread::sleep_for(1s);
  {
    std::lock_guard<std::mutex> lock(g_mutex);
    std::cout << "thread id: " << std::this_thread::get_id() << " exiting\n";
  }
}

template <typename T>
struct container {
  std::mutex mutex;
  std::vector<T> data;
}

int main() {
    return 0;
}