int main() {
  bool f = false;
  return ++f;
}

/*
➜  test.cpp git:(master) ✗ g++ -o c++17_bool_increment_deprecated c++17_bool_increment_deprecated.cpp 
c++17_bool_increment_deprecated.cpp:3:10: warning: incrementing expression of type bool is deprecated and incompatible with C++17 [-Wdeprecated-increment-bool]
  return ++f;
         ^ ~
1 warning generated.
➜  test.cpp git:(master) ✗ ./c++17_bool_increment_deprecated 
➜  test.cpp git:(master) ✗ echo $? 
1
➜  test.cpp git:(master) ✗ g++ -std=c++17 -o c++17_bool_increment_deprecated c++17_bool_increment_deprecated.cpp
c++17_bool_increment_deprecated.cpp:3:10: error: ISO C++17 does not allow incrementing expression of type bool [-Wincrement-bool]
  return ++f;
         ^ ~
1 error generated.
 */

