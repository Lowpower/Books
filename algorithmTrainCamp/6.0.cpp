typedef struct Node {
  int val;
  struct Node* forward[MAX_LEVEL];
}*Nodeptr;
Nodeptr head, update[MAX_LEVEL];
int level;

void init() {
  level = 0;
  head = new Node;
  for(int i = 0; i < MAX_LEVEL; i++) {
    head->forward[i] = nullptr;
  }
  head->val = INF;
}