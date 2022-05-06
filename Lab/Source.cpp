#include <iostream>
#include "String.h"
int main()
{
  TString str1("helloworld");
  TString str2("23232");
  TString str3(6,'s');
  TString str4(str3);
  TString str5(5, "fdd76768");
  std::cout << str5 << std::endl;
  str2 = str2.operator+(str2);
  str1.Split('o');
  std::cout << str2 << std::endl;
  TString str9;
  std::cin >> str9;
  std::cout << str9 << std::endl;
  return 0;
}