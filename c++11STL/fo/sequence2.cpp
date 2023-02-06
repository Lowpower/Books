#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

class IntSequence {
  private:
    int value;
  public:
    IntSequence(int initialValue):value(initialValue){
    }
    int operator()() {
      return ++value;
    }
};

int main() {
  list<int> coll;
  IntSequence seq(1);
  generate_n<back_insert_iterator<list<int>>, int, IntSequence&>(back_inserter(coll), 4, seq);
  auto print = [&]() {
  for(const auto& l : coll) {
    cout << l << " ";
  }
  cout << endl;
  };
  print();
  generate_n(back_inserter(coll), 4, IntSequence(42));
  print();
  generate_n(back_inserter(coll), 4, seq);
  print();
  generate_n(back_inserter(coll), 4, seq);
  print();
  return 0;
}