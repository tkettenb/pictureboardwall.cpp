#include <iostream>
#include <string>
#include <vector>

using std::vector, std::string;

class A {
  public:
	explicit A(vector<string>& list)
	  : refList(list) {}

	void rockNRoll() const;

  private:
	A(const A&);
	A& operator=(const A&);

	vector<string>& refList;
};

void A::rockNRoll() const {
  using std::cout, std::endl;

  cout << "*** size of list is: " << refList.size() << endl;
  vector<string>::const_iterator it = refList.begin();
  while (it != refList.end()) {
	cout << "*** " << (*it) << endl;
	++it;
  }
}

void init_and_do_some() {
  using std::cout, std::endl;

  vector<string> someWords;
  someWords.push_back(string("hey"));
  someWords.push_back(string("you"));

  cout << "*** initial size of list is: " << someWords.size() << endl;
  const A* ptrA = new A(someWords);
  ptrA->rockNRoll();
}

int main(int argc, const char** argv) {
  using std::cerr, std::endl;

  try {
	init_and_do_some();
  } catch(...) {
	cerr << "You gotta be kidding, right?" << endl;
  }
  return 0;
}
