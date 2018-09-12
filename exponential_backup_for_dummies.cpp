#include <cerrno>
#include <cstdio>
#include <cstdlib>

int main(int argc, const char** argv) {
  using std::strtol;

  int sleepDuration = 1, xxy = 10;
  if (argc > 1) {
	int x = strtol(argv[1], NULL, 10);
	if (errno != 0) {
	  printf("You gotta be kidding, right? (going with the default.\n");
	} else {
	  xxy = x;
	}
  }

  for (int i=0; i<xxy; ++i) {
	printf("would wait for %d\n", sleepDuration);
	sleepDuration *= 2;
  }
  return 0;
}
