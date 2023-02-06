#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

class IntSequene {
  private:
    int value;
  public:
    IntSequene(int initialValue) : value(initialValue) {}
    int operator()() {
      return ++value;
    }
};

int main() {
  list<int> coll;
  generate_n(back_inserter(coll), 9, IntSequene(1));
  generate(next(coll.begin()), prev(coll.end()),IntSequene(42));
  return 0;
}