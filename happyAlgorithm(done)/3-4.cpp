#include <iostream>
#include <cstring>
using namespace std;

const int M = 100;
char sa[1000];
char sb[1000];

typedef struct _Node {
	int s[M];
	int l;
	int c;
} Node, *pNode;

