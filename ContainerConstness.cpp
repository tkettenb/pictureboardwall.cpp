#include <iostream>
#include <vector>

using std::vector;

void print_list(const vector<int>& list) {
  using std::cout, std::endl; // need -std=c++17 for using this

  vector<int>::const_iterator it = list.begin();
  while (it < list.end()) {
	cout << (*it++) << endl;
  }
}

int main(int argc, const char** argv) {
  vector<int> list;
  const vector<int>* const_list =  &list;
  const vector<int>* const const_ptr_to_const_list = &list;

  list.push_back(1);
  // can't do those: both are on a const obj/ref/ptr
  // const_list->push_back(2);
  // const_ptr_to_const_list->push_back(3);
  list.push_back(2);
  list.push_back(3);

  print_list(list);

  // same here, cant do those:
  // (*const_list)[1] = 9;
  // (*const_ptr_to_const_list)[1] = 7;
  list[1] = 9;
  list[1] = 7;

  print_list(list);
  return 0;
}
