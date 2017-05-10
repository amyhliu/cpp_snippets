#include <iostream>


// Base1 does not have virtual destructor.
class Base1 {
public:
  ~Base1() {std::cout << "Base1 destructor\n";}
};


class D1 : public Base1 {
public:
  D1(int length) {
    m_array = new int[length];
  }

  ~D1() {
    std::cout << "D1 destructor\n";
    delete[] m_array;
  }

private:
  int *m_array;
};


// Base2 has virtual destructor.
class Base2 {
public:
  // Virtual destructors are useful when you can delete an instance of
  // a derived class through a pointer to base class.
  virtual ~Base2() {std::cout << "Base2 destructor\n";}
};


class D2 : public Base2 {
public:
  D2(int length) {
    m_array = new int[length];
  }
  
  ~D2() {
    std::cout << "D2 destructor\n";
    delete[] m_array;
  }

private:
  int *m_array;
};


int main(void)
{
#if 0
  Base1 *bPtr1 = new D1(1);
  // Only base destructor is called because base destructor is not virtual.
  // Memory leak occurred.
  delete bPtr1; // Display Base1 destructor
#endif
  
  Base2 *bPtr2 = new D2(5);

  // D2 destructor called first, then base destructor.
  // It's important if the class D2 needs to deallocate memory.
  delete bPtr2; // Display "D2 destructor" and then "Base2 destructor".
  
  // Always calls D1 destructor and then Base1 destructor even if Base1
  // destructor is not virtual. because object is deleted not through
  // pointers.
  D1 d3(1);

  return 0;
}
