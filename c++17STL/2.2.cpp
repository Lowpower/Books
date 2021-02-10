#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> v{123, 456, 789, 100, 200};
  quic_remove_at(v, 2);
  return 0;  
}