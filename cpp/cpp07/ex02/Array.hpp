
#include <iostream>

template <typename T>
class Array
{
    private:
        T *_ar;
        unsigned int _size;
        
    public:
        // Array();
        // Array( unsigned int n);
        // Array( Array &a);
        // ~Array();

        // int size();
        // int operator[](int i);
        
        // Array()
        // {
        //     _size = 0;
        //     _ar = new[0] T;
        // }

        // Array( unsigned int n)
        // {
        //     _size = n;
        //     _ar = new[n] T; 
        // }

        // Array( Array &a)
        // {
        //     unsigned int n = a.size();

        //     _size = n;
        //     _ar = new[n] T; 
            
        //     for (unsigned int x = 0; x < n; x++)
        //         _ar[x] = a[x];
        // }

        // ~Array()
        // {
        //     delete[] _ar;
        // }

        Array() : _size(0) , _ar(new[0] T) 
        {}

        Array( unsigned int n) : _size(n) , _ar(new[n] T) 
        {}

        Array( Array &a) : _size(a.size()) , _ar(new[a.size()] T)
        {
            for (unsigned int x = 0; x < a.size(); x++)
                _ar[x] = a[x];
        }

        ~Array()
        {
            delete[] _ar;
        }

        unsigned int size()
        {
            return _size;
        }

        T operator[](unsigned int i)
        {
            if (i > _size)
                throw OutOfBoundException();
            return _ar[i];
        }

        Array& operator=(Array& a)
        {
            if (this != a)
            {
                ~Array();

                _size = a.size();
                _ar = new[a.size()] T;
                for (unsigned int x = 0; x < a.size(); x++)
                    _ar[x] = a[x];
            }
        }

        class OutOfBoundException : public std::exception
        {
            public:
            const char* what() const throw()
            {
                return ("Element is out of range");
            }
        }
};