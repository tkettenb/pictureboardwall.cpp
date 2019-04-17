int main() {
  register int a = 0;
  ++a;
  return a;
}

/* 'register' is removed in c++17:

➜  test.cpp git:(master) ✗ g++ -o c++17_register_deprecated c++17_register_deprecated.cpp 
➜  test.cpp git:(master) ✗ ./c++17_register_deprecated 
➜  test.cpp git:(master) ✗ echo $?
1
➜  test.cpp git:(master) ✗ g++ -std=c++17 -o c++17_register_deprecated c++17_register_deprecated.cpp
c++17_register_deprecated.cpp:2:3: error: ISO C++17 does not allow 'register' storage class specifier [-Wregister]
  register int a = 0;
  ^~~~~~~~~
1 error generated.
 */

