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

void Insert(int val) {
  Nodeptr p, s sl;
  int lay = RandomLevel();
  if(lay > level) {
    level = lay;
  }
  p = Find(val);
  s = new Node;
  s->val = val;
  for(int i = 0; i < MAX_LEVEL; i++) {
    s->forward[i] = nullptr;
  }
  for(int i = 0; i <= lay; i++) {
    s->forward[i] = update[i]->forward[i];
    update[i]->forward[i] = s;
  }
}