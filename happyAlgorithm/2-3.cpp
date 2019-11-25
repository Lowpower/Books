#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

struct Meet {
	int beg;
	int end;
	int num;
}meet[1000];

class SetMeet {
	public:
		void init();
		void solve();
	private:
		int n,ans;
};

void SetMeet::init() {
	int s,e;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		meet[i].beg = s;
		meet[i].end = e;
		meet[i].num = i+1;
	}
}

void SetMeet::solve() {
	sort(meet, meet+n, [](Meet x, Meet y) {
		if(x.end == y.end) {
			return x.beg > y.beg;
		}
		return x.end < y.end;
	});
}

int main() {
	SeetMeet sm;
	sm.init();
	sm.solve();
	return 0;
}
