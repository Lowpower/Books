#include <string>
#include <map>
#include <memory>
#include <functional>

using namespace std;

template<typename T>

class IocContainer {
 public:
  IocContainer() {}
  ~IocContainer() {}

  template<typename Derived>
  void RegisterType(string strKey) {
    std::function<T*()> function = []{
      return new Derived();
    };
    RegisterType(strKey, function);
  }
  T* Resolve(string strKey) {
    if(m_creatorMap.find(strKey) == m_creatorMap.end()) {
      return nullptr;
    }
    std::function<T*()> function = m_creatorMap[strKey];
    return function();
  }
  std::shared_ptr<T> RegisterShard(string strKey) {
    T* ptr = Resolve(strKey);
    return std::shared_ptr<T>(ptr);
  }
 private:
  void RegisterType(string strKey, std::function<T*()> creator) {
    if(m_creatorMap.find(strKey) != m_creatorMap.end()) {
     throw std::invalid_argument("already exist!");
    }
    m_creatorMap.emplace(strKey, creator);
  }
  map<string, std::function<T*()>> m_creatorMap;
};