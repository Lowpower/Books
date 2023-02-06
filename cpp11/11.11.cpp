#include <iostream>

struct IX {
  virtual ~IX() {}
  virtual void g() = 0;
};

class X : public IX {
 public:
 void g() {
   std::cout << "it is a test in x" << std::endl;
 }
};

class Y : public IX {
 public:
  Y(int a):m_a(a){}
  void g() {
    std::cout << "it is a test in y" << std::endl;
  }
  int m_a;
};

struct MyStructA {
  MyStructA(IX* x) : m_x(x) {}
  ~MyStructA(){
    if(m_x != nullptr) {
      delete m_x;
      m_x = nullptr;
    }
  }
  void Func() {m_x->g();}
 private:
  IX* m_x;
};

int main() {
  MyStructA* pa = new MyStructA(new X());
  pa->Func();
  delete pa;
}