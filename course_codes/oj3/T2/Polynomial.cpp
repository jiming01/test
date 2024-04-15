#include "Polynomial.h"
#include <assert.h>

Polynomial::Polynomial(const vector<int> &coefficients)
{
  coefficients_ = coefficients;
}

Polynomial::Polynomial(const Polynomial &other)
{
  this->coefficients_ = other.coefficients_;
}

Polynomial add(const Polynomial &p1, const Polynomial &p2)
{
  Polynomial result;
  int len1 = p1.coefficients_.size();
  int len2 = p2.coefficients_.size();
  int owe = (len1 > len2) ? (len1 - len2) : (len2 - len1);
  int max = (len1 > len2) ? len1 : len2;
  for (int i = 0; i < max; i++)
  {
    if (len1 > len2)
    {
      if (i < owe)
      {
        int n1 = p1.coefficients_[i];
        result.coefficients_.push_back(n1);
      }
      else
      {
        int n1 = p1.coefficients_[i];
        int n2 = p2.coefficients_[i - owe];
        result.coefficients_.push_back(n1 + n2);
      }
    }
    else
    {
      if (i < owe)
      {
        int n2 = p2.coefficients_[i];
        result.coefficients_.push_back(n2);
      }
      else
      {
        int n1 = p1.coefficients_[i - owe];
        int n2 = p2.coefficients_[i];
        result.coefficients_.push_back(n1 + n2);
      }
    }
  }
  return result;
}

Polynomial derivate(const Polynomial &p)
{
  Polynomial result;
  int len = p.coefficients_.size();
  for (int i = 0; i < len - 1; i++)
  {
    int a = len - i - 1;
    int n = p.coefficients_[i];
    result.coefficients_.push_back(a * n);
  }
  return result;
}

void Polynomial::output() const
{
  int len = coefficients_.size();
  for (int i = 0; i < len; i++)
  {
    int a = coefficients_[i];
    if (a != 0)
    {
      cout << a << "(" << (len - i - 1) << ")"
           << " ";
    }
  }
  cout << endl;
}

int main()
{
  Polynomial t({1, 1, 1}); // x^2 + x + 1
  derivate(t).output();    // 2x + 1
  return 0;
}