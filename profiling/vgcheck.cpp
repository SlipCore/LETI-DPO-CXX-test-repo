#include <iostream>
#include <cstdlib>
#include <cstring>

void run_test(int i)
{
  int delta = 123;
  char* mem = (char*)std::malloc(1024);
  std::strcpy(mem, "i = ");
  std::cout << mem << " " << i + delta << std::endl;
  // free(mem); //
}

int main()
{
  for(int i = 0; i < 10; i++)
    run_test(i);
  return 0;
}
