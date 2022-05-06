#include "String.h"
TString::TString()
{
  str = 0;
  len = 0;
}

TString::~TString()
{
  if (str != 0)
  {
    delete[] str;
    str = 0;
  }
}

TString::TString(const char* s)
{
  if (s == 0)
    throw "s=0";
  else
    len = strlen(s);
  str = new char[len + 1];
  for (int i = 0; i < len; i++)
    str[i] = s[i];
  str[len] = 0;
}

TString::TString(const TString& p)
{
  len = p.len;
  str = new char[len + 1];
  for (int i = 0; i < len; i++)
    str[i] = p.str[i];
  str[len] = 0;
}

TString::TString(int n, char c)
{
  if (n > 0)
    len = n;
  else
    throw "l<0";
  str = new char[len + 1];
  for (int i = 0; i < len; i++)
    str[i] = c;
  str[len] = 0;
}

TString::TString(int l, const char* s)
{
  if (s == 0) throw "error";
  if (l > 0 && s != 0)
  {
    len = l;
    str = new char[len + 1];
    for (int i = 0; i < len; i++)
      str[i] = s[i];
    str[len] = 0;
  }
  else
    throw "TString error";
}

TString TString::operator+(const TString& p)
{
  TString rez;
  rez.len = len + p.len;
  rez.str = new char[rez.len + 1];
  for (int i = 0; i < len; i++)
    rez.str[i] = str[i];
  for (int j = len; j < len + p.len; j++)
    rez.str[j] = p.str[j - len];
  rez.str[rez.len] = 0;
  return rez;
}

TString& TString::operator=(const TString& p)
{
  if (this != &p)
    delete[]str;
  else
    return *this;
  str = new char[p.len + 1];
  for (int i = 0; i < p.len; i++)
    str[i] = p.str[i];
  len = p.len;
  str[len] = 0;
  return *this;
}

TString TString::operator+(const char* s)
{
  TString rez;
  int l = strlen(s);
  rez.len = len + l;
  rez.str = new char[rez.len + 1];
  for (int i = 0; i < len; i++)
    rez.str[i] = str[i];
  for (int j = len; j < len + l; j++)
    rez.str[j] = s[j - len];
  rez.str[rez.len] = 0;
  return rez;
}

TString& TString::operator=(const char* s)
{
  int l = strlen(s);
  str = new char[l + 1];
  for (int i = 0; i < l; i++)
    str[i] = s[i];
  len = l;
  str[len] = 0;
  return *this;
}

char& TString::operator[](int i)
{
  if (i<0 || i>len)
    throw "I not found";
  return str[i];
}



std::ostream& operator<<(std::ostream& ostr, TString& p)
{
  ostr << p.str;
  return ostr;
}

std::istream& operator>>(std::istream& ist, TString& p)
{
  std::cout << "Enter length of your string = " << std::endl;
  ist >> p.len;
  if (p.str != 0)
  {
    delete[] p.str;
    p.str = 0;
  }
  p.str = new char[p.len + 1];
  std::cout << "Enter your string = " << std::endl;
  for (int i = 0; i < p.len; i++)
    ist >> p.str[i];
  p.str[p.len] = 0;
  return ist;
}

bool TString::operator==(TString& p)
{
  if (len != p.len)
    return false;
  else
  {
    for (int i = 0; i < len; i++)
      if (str[i] == p.str[i])
        return true;
  }
  return false;
}

bool TString::operator<(TString& p)
{
  if (this == &p)
    throw "same";
  if (len < p.len)
    return true;
  else
  {
    if (len == p.len)
      for (int i = 0; i < len; i++)
        if (str[i] < p.str[i])
          return true;
  }
  return false;
}

bool TString::operator>(TString& p)
{
  if (this == &p)
    throw "same";
  if (len > p.len)
    return true;
  else
  {
    if (len == p.len)
      for (int i = 0; i < len; i++)
        if (str[i] > p.str[i])
          return true;
  }
  return false;
}

int TString::FindSymbol(char c)
{
  if (c == 0) throw "er";
  else
    if (len > 0 && str != nullptr)
      for (int i = 0; i < len; i++)
      {
        if (str[i] == c)
          return i;
      }
  return -1;
}

int TString::FindWords(const char* s)
{
  if (s == 0) throw "err";
  int find = 0;
  int l = strlen(s);
  if (len > l)
    for (int i = 0; i < len; i++)
    {
      if (str[i] == s[0])
      {
        find = i;
        for (int j = 0; str[find] == s[j]; j++, find++)
        {
          if (j == l - 1) return i;
        }
      }
    }
  return -1;
}

void TString::Split(char c)
{
  int count = 0; int k = 0; int start = 0;
  for (int i = 0; i < len; i++)
    if (str[i] == c) count++;
  if (count == 0) throw "No symbol";
  TString** res = new TString * [count + 1];
  for (int i = 0; i < len; i++)
  {
    if (str[i] == c)
    {
      res[k] = new TString(i - start, &str[start]);
      start = i + 1;
      k++;
    }
  }
  res[k] = new TString(len - start, &str[start]);
  std::cout << "Split string :" << std::endl;
  for (int h = 0; h < count + 1; h++)
    std::cout << *res[h] << std::endl;
  return;
}
