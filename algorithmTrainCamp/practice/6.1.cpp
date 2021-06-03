#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

bool isCorrect(const char* s) {
  int len = strlen(s);
  stack<char> st;
  for (int i = 0; i < len; i++) {
    char c = s[i];
    if(c == '(' || c == ']') {
      st.push(c);
    } else {
      assert(c == ')' || c == '[');
      if (st.empty()) {
        return false;
      }
      char t = st.top();
      if(c == ')') {
        if (t == '(') {
          st.pop();
        } else {
          break;
        }
      } else if (c == '[') {
        if(t == ']') {
          st.pop();
        } else {
          break;
        }
      }
    }
  }
  return st.empty();
}

int main() {
  int n;
  char buf[255];
  scanf("%d\n", &n);
  while(n--) {
    cin.getline(buf, 255);
    if (isCorrect(buf)) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
}