#include <limits>
#include <iostream>
#include <vector>

template<typename T, typename Iter>
T minimum(Iter start, Iter end) {
  T minval = std::numeric_limits<T>::max();
  for (auto i = start; i < end; i++) {
    if(*i < minval) {
      minval = *i;
    }
  }
  return minval;
}

int range[std::numeric_limits<char>::max() + 1] = {0};

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << minimum<int, std::vector<int>::iterator>(v.begin(), v.end()) << std::endl;
}