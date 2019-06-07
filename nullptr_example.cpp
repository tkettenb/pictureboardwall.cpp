#include <cstdlib>

bool cmp(void* a, void* b) {
	return a != b;
}

bool cmp(const char* a, const char* b) {
	return a != b;
}

template<typename ptrt>
bool comp_templ(ptrt a, ptrt b) {
	return a != b;
}

int main() {
	int* pa = nullptr;
	int b = NULL;
	int c = 0;

	// cmp(pa, b);
	// cmp(pa, c);
	cmp(pa, &b);
	cmp(pa, &c);

	// comp_templ(pa, b);
	comp_templ(pa, &b);
	return 0;
}


// compile:  g++ -std=c++11 -o nullptr_example nullptr_example.cpp

