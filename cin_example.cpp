#include <iostream>
#include <string>

int main() {
    using std::cerr, std::cin, std::cout, std::endl, std::string;
      const string PROMPT("::> HAH > ");  // TODO: define some sane prompt string

    string arg;
    while (!cin.eof()) {
        cout << PROMPT;
        cin >> arg;
        cout << "Read arg: " << arg << endl;
    }

    cout << "... and reached the end of the input. eof is set. kinda..." << endl;
    return 0;
}

// compile: $ g++ -std=c++17 -o cin_example cin_example.cpp


