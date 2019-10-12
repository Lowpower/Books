#include <iostream>
#include <optional>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <vector>
#include <string>

using namespace std;

template<typename T>
class trie {
	map<T, trie> tries;
public:
	template<typename It>
	void insert(It it, It end_it) {
		if(it == end_it) {
			return;
		}
		tries[*it].insert(next(it), end_it);
	}
	template<typename C>
		void insert(const C &container) {
			insert(begin(container), end(container));
		}
}

int main() {
	return 0;
}
