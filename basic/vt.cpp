#include <iostream>


class Base1 {
public:
  void func() {}
  // Since Base has a virtual function, a hidden pointen is added by compiler
  // at compiler time. It is a real pointer so it occupies space.
  // It is also inherited by derived classes.
  // FunctionPointer *__vptr;
  virtual void func1() { std::cout << "Base1 func1\n"; }
  virtual void func2() { std::cout << "Base2 func2\n"; }
};

class D1 : public Base1 {
public:
  virtual void func1() { std::cout << "D1 func1\n"; }
};

class D2 : public Base1 {
public:
  virtual void func2() { std::cout << "D2 func2\n"; }
};

class D3 : public Base1 {
};

// Base2 is abstract base class as it has one or more pure virtual functions.
// It cannot be instantiated.
class Base2 {
public:
  virtual void func3() = 0; // pure virtual function, no body
};

class D4 : public Base2 {
public:
  virtual void func3() {std::cout << "D4 func3\n"; }
};


int main(void)
{
  D1 d1;
  d1.func1(); // show "D1 func1"

  D2 d2;
  Base1 *d2ptr = &d2;
  d2ptr->func1(); // display "Base1 func1"
  d2ptr->func2(); // display "D2 func2", func2 is the most-derived function
                  // accessible by class D2.

  D3 d3;
  d3.func1(); // show "Base func1"
  std::cout << "sizeof(D3) :" << sizeof(D3) << std::endl; // show 8

  D4 d4;
  d4.func3(); // show D3 func3

  
  return 0;
}
