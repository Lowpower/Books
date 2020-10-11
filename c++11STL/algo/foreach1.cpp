#include <iostream>
using namespace std;

int main() {
	vector<int> coll;
	INSERT_ELEMENTS(coll,1,9);
	for_each (coll.cbegin(); coll.end(),
	[](int elem) {
		cout << elem << ' ';
	});
	cout << "aa" << endl;
}
