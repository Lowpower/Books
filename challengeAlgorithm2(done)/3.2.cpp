#include <iostream>
#include <vector>

using namespace std;

int bubbleSort(vector<int>& A) {
    int sw = 0;
    bool flag = 1;
    for(int i = 0; flag; i++) {
        flag = 0;
        for(int j = A.size()-1; j >= i + 1; j--) {
            if(A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = 1;
                sw++;
            }
        }
    }
    return sw;
}

int main() {
    vector<int> A;
    int  N;
    cin >> N;
    int tmp;
    while(N--) {
        cin >> tmp;
        A.push_back(tmp);
    }
    int sw = bubbleSort(A);
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