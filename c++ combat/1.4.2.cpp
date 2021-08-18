#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>

enum class jsontype {
  jsonTypeNull,
  jsonTypeInt,
  jsonTypeLong,
  jsonTypeDouble,
  jsonTypeBool,
  jsonTypeString,
  jsonTypeArray,
  jsonTypeObeject,
};

struct jsonNode {
  jsonNode(const char* key, const char* value) : m_type(jsontype::jsonTypeString),
    m_key(key), m_value(value) {
      std::cout << "jsonNode construct1 called." << std::endl;
  }

  jsonNode(const char* key, double value) : m_type(jsontype::jsonTypeDouble),
    m_key(key), m_value(std::to_string(value)) {
      std::cout << "jsonNode construct2 called." << std::endl;
  }

  jsontype m_type;
  std::string m_key;
  std::string m_value;
};

class json {
 public:
  static json& array(std::initializer_list<jsonNode> nodes) {
    m_json.m_nodes.clear();
    m_json.m_nodes.insert(m_json.m_nodes.end(), nodes.begin(), nodes.end());
    std::cout << "json::array() called." << std::endl;
    return m_json;
  }
  json() = default;
  ~json() = default;
  std::string toString() {
    size_t size = m_nodes.size();
    for(size_t i = 0; i < size; i++) {
      switch (m_nodes[i].m_type) {
      case jsontype::jsonTypeDouble:
        break;
      
      default:
        break;
      }
    }
  }
 private:
  std::vector<jsonNode> m_nodes;
  static json m_json;
};

int main() {
  return 0;
}