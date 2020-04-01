#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000;

int parent(int i) {
    return i/2;
}

int left(int i) {
    return 2*i;
}

int right(int i) {
    return 2*i+1;
}

int main() {
    int H;
    cin >> H;
    vector<int> A;
    int tmp = 0;
    A.push_back(tmp);
    for(int i = 1; i <= H; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }
    for (int i = 1; i <= H; i++) {
        cout << "node " << i << ": key=" << A[i] << ", ";
        if(parent(i) >=1) {
            cout << "parent key = " << A[parent(i)]<< ", ";
        }
        if(left(i) <= H) {
            cout << "left key = " << A[left(i)] << ", ";
        }
        if(right(i) <= H) {
            cout << "right key = " << A[right(i)] << ", ";
        }
        cout << endl;
    }
    return 0;
}