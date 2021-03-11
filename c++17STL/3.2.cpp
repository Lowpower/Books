#include <iostream>
#include <algorithm>

class num_iterator {
  int i;
public:
  explicit num_iterator(int position = 0) : i(position) {}
  int operator*() const {return i;}
  num_iterator& operator++() {
    ++i;
    return *this;
  }
  bool operator!=(const num_iterator& other) const {
    return i!= other.i;
  }
  bool operator == (const num_iterator& other) const {
    return !(*this != other);
  }
};

class num_range {
  int a;
  int b;
public:
  num_range(int from, int to):a{from}, b{to} {}
  num_iterator begin() const {return num_iterator{a};}
  num_iterator end() const {return num_iterator{b};}
};

using namespace std;

int main() {
  num_range r{100, 110};
  auto min_max(minmax_element(r.begin(), r.end()));
  cout << *min_max.first << "-" << *min_max.second << "\n";
  return 0;
}
