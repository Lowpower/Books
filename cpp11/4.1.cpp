#include <iostream>
#include <memory>

using namespace std;

struct A {
	shared_ptr<A> GetSelf() {
		return shared_ptr<A>(this);
	}
};

int main() {
	shared_ptr<A> sp1(new A);
	shared_ptr<A> sp2 = sp1->GetSelf();
	return 0;
}
