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

const A* init() {
  using std::cout, std::endl;

  vector<string> someWords;
  someWords.push_back(string("hey"));
  someWords.push_back(string("you"));

  cout << "*** initial size of list is: " << someWords.size() << endl;
  return new A(someWords);
}

void doSome(const A* a) {
  a->rockNRoll();
}

int main(int argc, const char** argv) {
  using std::cerr, std::endl;

  try {
	const A* ptrA = init();
	doSome(ptrA);
  } catch(...) {
	cerr << "You gotta be kidding, right?" << endl;
  }
  return 0;
}
