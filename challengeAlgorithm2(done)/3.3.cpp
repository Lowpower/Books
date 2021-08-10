#include <iostream>
#include <vector>

using namespace std;

int selectSort(vector<int>& A) {
    int sw = 0;
    int minj;
    for(int i = 0; i < A.size()-1; i++) {
        minj = i;
        for(int j = i; j < A.size(); j++) {
            if(A[j] < A[minj]) {
                minj = j;
            }
        }
        swap(A[i], A[minj]);
        if(i != minj) {
            sw++;
        }
    }
    return sw;
}

int main() {
    vector<int> A;
    int N;
    cin >> N;
    int tmp;
    while(N--) {
        cin >> tmp;
        A.push_back(tmp);
    }
    int sw = selectSort(A);
    for (int i = 0; i < A.size(); i++) {
        if(i) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
    return 0;
}