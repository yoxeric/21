
#include"Span.hpp"

Span()
{}

Span(unsigned int x) : _size(x)
{}

Span(Span &s) : _size(s.getSize())
{}

~Span()
{}

int Span::getSize()
{
   return (_size);
}

void Span::addNumber(int n)
{
   if (_v.size() < _size)
      _v.pushback(n);
}

int Span::shortestSpan() 
{
   for (std::vector<int>::iterator it1 = _v.begin(); it1 != _v.end(); ++it1)
   {
      for (std::vector<int>::iterator it2 = _v.begin(); it2 != _v.end(); ++it2)
      {
         if (res > it1 - it2)
            res = it1 - it2;
      }
   }
   return (res)
}

int Span::longestSpan()
{
   int res;
   int minres;
   int maxres;

   res = std::min_element(std::begin(_v), std::end(_v));
   if (res != std::end(_v))
      minres = res;
   res = std::max_element(std::begin(_v), std::end(_v));
   if (res != std::end(_v))
      maxres = res;
   return (maxres - minres);
}