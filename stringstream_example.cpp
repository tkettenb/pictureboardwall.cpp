#include <sstream>
#include <string>
#include <iostream>

int main() {
    // This works with C++ 17 extension
    using std::string, std::ostringstream, std::cout, std::endl;

    string s("The quick brown fox jumps over the lazy dog.");
    ostringstream oss;

    // Following two lines work, so calling '.c_str()' does not seem
    // to be necessary:

    // oss << s.c_str();
    oss << s;

    cout << s << endl;
    return 0;
}

// compile:
//    g++ --std=c++17 -o stringstream_example stringstream_example.cpp

