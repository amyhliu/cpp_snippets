#include <iostream>


struct T {
  char &c;
};

int main(void)
{
  int val1 = 1;
  int val2 = 5;
  int &ref = val1;

  std::cout << ref << std::endl;

  ref = val2;
  std::cout << ref << std::endl;
  std::cout << val1 << std::endl;
  
  val2++;
  std::cout << val2 << std::endl;
  std::cout << ref << std::endl;
  std::cout << val1 << std::endl;


  const int x = 5;
  //int &ref1 = x; // invalid
  const int &ref1 = x;

  int val3 = 1;
  const int &ref3 = val3;

  //ref3 = 6; // invalid, assignment of read-only
  val3 = 7;
  std::cout << "ref3: " << ref3 << std::endl;

  char c = 'a';
  char &refc = c;
  std::cout << "refc memory space: " << sizeof(struct T) << std::endl;
  return 0;
}
