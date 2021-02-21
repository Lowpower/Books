#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

template<typename C, typename T>
void insert_sort(C &v, const T &word) {
  const auto insert_pos(lower_bound(begin(v), end(v), word));
  v.insert(insert_pos, word);
}

int main() {
  vector<string> v{
    "some", "radom", "words", "without",
    "order", "aaaa", "yyy"
  };
  assert(false == is_sorted(begin(v), end(v)));
  sort(begin(v), end(v));
  assert(true == is_sorted(begin(v), end(v)));
  insert_sort(v, "foobar");
  insert_sort(v, "zzz");
  for(const auto &w: v) {
    cout << w<< " ";
  }
  cout << endl;
}