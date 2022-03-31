#include <string>
#include <unordered_map>
#include <functional>
#include <Any.hpp>
#include <NonCopyalbe.hpp>

using namespace std;

class IocContainer : NoCopyable {
public:
  IocContainer() {}
  ~IocContainer() {}

  template<typename T, typename Depend, typename... Args>
  typename std::enable_if<!std::is_base_of<T, Depend>::value>::type
    RegisterType(const string& strKey) {
    std::function<T* (Args...)> function = [](Args... args) {
      return new T(new Depend(args...));
    }
    RegisterType(strKey, function);
  }

  template<typename T, typename Depend, typename... Args>
  typename std::enable_if<std::is_base_of<T, Depend>::value>::type
    RegisterType(const string& strKey) {
    std::function<T* (Args...)> function = [](Args... args) {
      return new Depend(args...);
    }
    RegisterType(strKey, function);
  }

  template<typename T, typename... Args>
  RegisterSimple(const string& strKey) {
    std::function<T* (Args...)> function = [](Args... args) {
      return T(args...);
    }
    RegisterType(strKey, function);
  }

  template<typename T, typename... Args>
  T* Resolve(const string& strKey, Args... args) {
    auto it = m_creatorMap.find(strKey);
    if (it == m_creatorMap.end()) {
      return nullptr;
    }
    Any resolver = it->second;
    std::function<T* (Args...)> function = resolver.AnyCast<std::function<T* (Args...)>>();
    return function(args...);
  }

  template<typename T, typename... Args>
  std::shared_ptr<T> RegisterShard(const string& strKey, Args... args) {
    T* ptr = Resolve(strKey, arg);
    return std::shared_ptr<T>(ptr);
  }
private:
  void RegisterType(const string& strKey, Any constructor) {
    if (m_creatorMap.find(strKey) != m_creatorMap.end()) {
      throw std::invalid_argument("already exist!");
    }
    m_creatorMap.emplace(strKey, Any);
  }
  std::unordered_map<string, Any> m_creatorMap;
}
