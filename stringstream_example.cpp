#include <sstream>
#include <string>
#include <iostream>

int main(int argc, const char** argv) {
    // This works with C++ 17 extension
    using std::string, std::stringstream, std::ostringstream, std::cerr, std::cout, std::endl;

    string s("The quick brown fox jumps over the lazy dog.");
    ostringstream oss;

    // Following two lines work, so calling '.c_str()' does not seem
    // to be necessary:

    // oss << s.c_str();
    oss << s;

    cout << s << endl;

	for (int i=1; i<argc; ++i) {
	  stringstream sstr(argv[i]);
	  int num = 0;
	  if (sstr >> num) {
		cout << "Number: " << num << " for arg: " << argv[i] << endl;
	  } else {
		cerr << "Cannot convert arg: " << argv[i] << " to number." << endl;
	  }
	}
    return 0;
}

// compile:
//    g++ --std=c++17 -o stringstream_example stringstream_example.cpp

