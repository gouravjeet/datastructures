// istream::peek example
#include <iostream>     // std::cin, std::cout
#include <string>       // std::string

int main () {

  std::cout << "Please, enter a number or a word: ";
  char c = std::cin.peek();

  if ( (c >= '0') && (c <= '9') )
  {
    int n;
    std::cin >> n;
    std::cout << "You entered the number: " << n << '\n';
  }
  else
  {
    std::string str;
    std::getline (std::cin, str);
    std::cout << "You entered the word: " << str << '\n';
  }

  return 0;
}