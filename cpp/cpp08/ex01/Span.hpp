
#include<iostream>
#include<vector>
#include <algorithm>

class Span{
    private:
        std::vector<int> _v;
        unsigned int    _size;

    public:
        Span();
        Span(unsigned int x);
        Span(const Span &s);
        ~Span();
        
        int getSize();

        void addNumber(int x);
        int shortestSpan();
        int longestSpan();
};
