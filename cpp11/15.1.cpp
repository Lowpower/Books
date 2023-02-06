template<typename T>
class Task;

template<typename R, typename... Args>
class Task<R(Args...)> {
  std::function<R(Args...)> m_fn;
 public:
  typedef R return_type;
  Task(std::function<R(Args...)>&& f) : m_fn(std::move(f)) {}
  Task(std::function<const R(Args...)>& f) : m_fn(f) {}

  ~Task(){}

  void Wait() {
    std::async(m_fn).wait();
  }

  template<typename... Args>
  R Get(Args&&... args) {
    return std::async(m_fn, std::forward<Args>(args)...).get();
  }

  std::shared_future<R> Run() {
    return std::async(m_fn);
  }
};