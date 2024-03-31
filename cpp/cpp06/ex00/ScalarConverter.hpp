
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include<iostream>
#include <cstdlib>

enum e_type{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    LITERAL,
    X,
};

class ScalarConverter{
    private:
        static char    _c;
        static int     _n;
        static float   _f;
        static double  _d;

        static std::string _str;
        static e_type   _type;

        static void    setType();

        static bool    isChar();
        static bool    isInt();
        static bool    isFloat();
        static bool    isDouble();
        static bool    isLiteral();

        static void    printChar();
        static void    printInt();
        static void    printFloat();
        static void    printDouble();

        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter& src);

    public:
        static void     convert( std::string );

        ScalarConverter& operator=(const ScalarConverter& src);
};

#endif