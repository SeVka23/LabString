#pragma once
#include <iostream>
class TString
{
public:
  TString();
  ~TString();
  TString(const char* s);
  TString(const TString& p);
  TString(int n, char c);
  TString(int l, const char* s);
  TString operator + (const TString &p);
  TString& operator = (const TString& p);
  TString operator + (const char* s);
  TString& operator = (const char* s);
  char& operator[](int i);
  bool operator == (TString& p);
  bool operator<(TString& p);
  bool operator>(TString& p);
  friend std::ostream& operator << (std::ostream& ostr, TString& p);
  friend std::istream& operator >> (std::istream& ist, TString& p);
  int FindSymbol(char c);
  int FindWords(const char* s);
  void Split(char c);
protected:
  char* str;
  int len;
};