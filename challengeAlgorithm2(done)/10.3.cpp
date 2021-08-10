#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX = 2000000;
int h, A[MAX+1];

void maxHeapify (int i) {
    int l, r, larger;
    l = 2*i;
    r = 2*i +1;
    if (l <= h && A[l] > A[i]) {
        larger = l;
    } else {
        larger = i;
    }
    if (r <= h && A[r] > A[larger]) {
        larger = r;
    }
    if (larger != i) {
        swap(A[i], A[larger]);
        maxHeapify(larger);
    }
}

int main() {
    std::string com;
    int key;
    while (1) {
        cin >> com;
        if (com[0] == 'e' && com[1] == 'n') {
            break;
        }
        if (com[0] == 'i') {
            cin >> key;
            insert(key);
        } else {
            cout << extract() << endl;
        }
        return 0;
    }