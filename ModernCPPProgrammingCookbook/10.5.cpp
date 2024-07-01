#include <iostream>

class Client {
  int data_1;
  int data_2;

  void action1(){}
  void action2(){}
  friend class Attorney;
 public:
};

class Attorney {
  static inline void run_action1(Client &c) { c.action1(); }
  static inline int get_data1(Client &c) { return c.data_1; }
  friend class Friend;
};

class Friend {
 public:
  void access_client_data(Client &c) {
    Attorney::run_action1(c);
    auto d1 = Attorney::get_data1(c);
  }
};

class B {
  virtual void execute() {
    std::cout << "B::execute" << std::endl;
  }
  friend class BAttorney;
};

class D : public B {
  void execute() override { std::cout << "D::execute" << std::endl; }
};

class BAttorney {
  static inline void execute(B &b) { b.execute(); }
  friend class F;
};

class F {
 public:
  void run() {
    B b;
    BAttorney::execute(b);

    D d;
    BAttorney::execute(d);
  }
};

int main() {
  return 0;
}