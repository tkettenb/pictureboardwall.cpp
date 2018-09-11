#include <stdexcept>
#include <string>
#include <iostream>

int main(int argc, const char** argv) {
    using std::cerr;
    using std::cout;
    using std::endl;
    using std::stoi;
	using std::string;

    for (int i=1; i<argc; ++i) {
	    int number = 0;
	    try {
		    number = stoi(string(argv[i]));
		} catch(const std::out_of_range& e) {
		    cerr << "caught std::out_of_range: " << e.what() << endl;
		} catch(const std::runtime_error& e) {
		    cerr << "caught std::runtime_error: " << e.what() << endl;
		} catch(const std::exception& e) {
		    cerr << "caught std::exception: " << e.what() << endl;
		} catch(...) {
		    // ... it burns in my hands :-)
		    cerr << "no idea what i've just caught, but it's not a problem, we're using the default." << endl;
		}
        cout << "base10 number: " << number << " for arg: " << argv[i] << endl;
    }

    cout << "bye." << endl;
    return 0;
}

// compile with:
//    ✗ g++ -o str_to_int_example str_to_int_example.cpp
// or ✗ g++ -fexceptions -o str_to_int_example str_to_int_example.cpp
// TODO: `-fexceptions` does not seem to add anything, std::exceptions seem to
//    work out of the box here.

