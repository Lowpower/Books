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
};

template<typename T>
void move_between(container<T>& from, container<T>& to, const T value) {
  std::lock(from.mutex, to.mutex);
  std::lock_guard<std::mutex> lock_from(from.mutex, std::adopt_lock);
  std::lock_guard<std::mutex> lock_to(to.mutex, std::adopt_lock);
  from.data.erase(std::remove(from.data.begin(), from.data.end(), value), from.data.end());
  to.data.push_back(value);
}

template<typename M>
class lock_guard{
 public:
  typedef M mutex_type;
  explicit lock_guard(mutex_type& mtx) : mtx(mtx) {
    mtx.lock();
  }

  lock_guard(const lock_guard&) = delete;
  lock_guard& operator=(const lock_guard&) = delete;
  lock_guard(mutex_type& mtx, std::adopt_lock_t) noexcept : mtx(mtx) {}

  ~lock_guard() noexcept {
    mtx.unlock();
  }
 private:
  mutex_type& mtx;
};

int main() {
  std::vector<std::thread> threads;
  for (int i = 0; i < 10; i++) {
    threads.push_back(std::thread(thread_func));
  }
  for (auto& thread : threads) {
    thread.join();
  }
  return 0;
}