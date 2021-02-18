#include <iostream>
#include <vector>

using namespace std;

int main() {
  const size_t container_size{ 1000 };
  vector<int> v(container_size, 123);
  cout << "Out of range element value; "
    << v[container_size + 10] << endl;
  try {
    cout << "Out of range element value; "
      << v.at(container_size + 10) << endl;
  } catch(const std::out_of_range &e) {
    cout << e.what() << endl;
  }

}