#include <iostream>

int last_function()
{
   std::cout << "In last function" << std::endl;
   return 0;
}
int function2()
{
   std::cout << "In function2" << std::endl;
   last_function();
   std::cout << "exit from function2" << std::endl;
   return 0;
}

int function1()
{
   std::cout << "In function1" << std::endl;
   function2();
   std::cout << "Exit from function1" << std::endl;
   return 0;
}

int main() {
   std::string textToPrint = "Hello, World!";
   for (size_t i = 0; i < 5; i++) {
       std::cout << i << std::endl;
   }
  
   function1();

   std::cout << textToPrint << std::endl;
   return 0;
}


