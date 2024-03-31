
#include "ScalarConverter.hpp"

std::string ScalarConverter::_str = "0";
e_type      ScalarConverter::_type = X;
char        ScalarConverter::_c = '\0';
int         ScalarConverter::_n = 0;
float       ScalarConverter::_f = 0.0f;
double      ScalarConverter::_d = 0.0;

ScalarConverter::ScalarConverter()
{
    _str = "0";
    _type = X;
    _c = '\0';
    _n = 0;
    _f = 0.0f;
    _d = 0.0;
}

ScalarConverter::ScalarConverter(ScalarConverter& src)
{
    *this = src;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src)
{
    (void)(src);
    return *this;
}

void    ScalarConverter::convert( std::string s )
{
    ScalarConverter::_str = s;
    
    ScalarConverter::setType();

    switch (_type){
        case CHAR:
            _c = static_cast< char >( _str[0] );
            _n = static_cast< int >( _c );
            _f = static_cast< float >( _c );
            _d = static_cast< double >( _c );
            break;
        case INT:
            _n = static_cast< int >( std::strtol(_str.c_str(), NULL, 10) );
            _c = static_cast< char >( _n );
            _f = static_cast< float >( _n );
            _d = static_cast< double >( _n );
            break;
        case FLOAT:
            _f = static_cast< float >( std::atof(_str.c_str()) );
            _c = static_cast< char >( _f );
            _n = static_cast< int >( _f );
            _d = static_cast< double >( _f );
            break;
        case DOUBLE:
            _d = static_cast< double >( std::strtold(_str.c_str(), NULL) );
            _c = static_cast< char >( _d );
            _f = static_cast< float >( _d );
            _n = static_cast< int >( _d );
            break;
        default:
            break;
    }

    std::cout << "char :";
    ScalarConverter::printChar();
    std::cout << "int :";
    ScalarConverter::printInt();
    std::cout << "float :";
    ScalarConverter::printFloat();
    std::cout << "double :";
    ScalarConverter::printDouble();
}

void     ScalarConverter::setType()
{
    // std::cout << "is int: " << isInt() << std::endl;
    // std::cout << "is flt: " << isFloat() << std::endl;
    // std::cout << "is dbl: " << isDouble() << std::endl;
    // std::cout << "is lit: " << isLiteral() << std::endl;

    if (ScalarConverter::isInt())
        _type = INT;
    else if (ScalarConverter::isChar())
        _type = CHAR;
    else if (ScalarConverter::isFloat())
        _type = FLOAT;
    else if (ScalarConverter::isDouble())
        _type = DOUBLE;
    else if (ScalarConverter::isLiteral())
        _type = LITERAL;
    else
        _type = X;

}

bool    ScalarConverter::isChar()
{
    return (_str.length() == 1 && std::isprint( _str[0] ));
}

bool    ScalarConverter::isInt()
{
    int x;

    x = 0;
    if (_str[x] == '-' || _str[x] == '+')
        x++;
    for (; x < (int) _str.length() ; x++)
    {
        if (!std::isdigit(_str[x]))
            return (false);
    }
    if (std::strtold(_str.c_str(), NULL) <= 2147483647 
        || std::strtold(_str.c_str(), NULL) >= -2147483647)
        return (false);
    return (true);
}

bool    ScalarConverter::isFloat()
{
    if (_str.find('.') == std::string::npos || _str.back() != 'f')
        return false;
    
    int dot = 0;
    int x = 0;

    if (_str[x] == '-' || _str[x] == '+')
        x++;
    for (; x < (int) _str.length() - 1; x++)
    {
        if (_str[x] == '.')
            dot++;
        if ( (!std::isdigit(_str[x]) && _str[x] != '.') || dot > 1)
            return false;
    }
    return true;
}

bool    ScalarConverter::isDouble()
{
    if ( _str.find('.') == std::string::npos && 
        (std::strtold(_str.c_str(), NULL) <= 2147483647 
            && std::strtold(_str.c_str(), NULL) >= -2147483647))
        return false;

    int dot = 0;
    int x = 0;

    if (_str[x] == '-' || _str[x] == '+')
        x++;
    for (; x < (int) _str.length(); x++)
    {
        if (_str[x] == '.')
            dot++;
        if ( (!std::isdigit(_str[x]) && _str[x] != '.') || dot > 1)
            return false;
    }
    return true;
}

bool    ScalarConverter::isLiteral()
{
    if (_str.compare("inf") == 0
        || _str.compare("inff") == 0
        || _str.compare("+inff") == 0
        || _str.compare("-inff") == 0
        || _str.compare("nanf") == 0
        || _str.compare("+inf") == 0
        || _str.compare("-inf") == 0
        || _str.compare("nan") == 0)
    {
        return true;
    }
    return false;
}

void    ScalarConverter::printChar()
{
    if (_type == X || _type == LITERAL
        || _d > 255 || _d < 0)
        std::cout << "imposible" << std::endl;
    else if (!std::isprint(_c))
        std::cout << "Non display" << std::endl;
    else
        std::cout << _c << std::endl;
}

void    ScalarConverter::printInt()
{
    if (_type == X || _type == LITERAL)
        std::cout << "imposible" << std::endl;
    else if (_d >= 2147483647 || _d <= -2147483647)
        std::cout << _str.substr(0, _str.find('.')) << std::endl;
    else
        std::cout << _n << std::endl;
}

void    ScalarConverter::printFloat()
{
    if (_type == X)
        std::cout << "imposible" << std::endl;
    else if (_str.compare("nan") == 0 || _str.compare("nanf") == 0)
        std::cout << "nanf" << std::endl;
    else if (_str.compare("inf") == 0 || _str.compare("inff") == 0
        || _str.compare("+inf") == 0 || _str.compare("+inff") == 0)
        std::cout << "+inff" << std::endl;
    else if (_str.compare("-inf") == 0 || _str.compare("-inff") == 0)
        std::cout << "-inff" << std::endl;
    else
        std::cout << _f << "f" << std::endl;
}

void    ScalarConverter::printDouble()
{
    if (_type == X)
        std::cout << "imposible" << std::endl;
    else if (_str.compare("nan") == 0 || _str.compare("nanf") == 0)
        std::cout << "nan" << std::endl;
    else if (_str.compare("inf") == 0 || _str.compare("inff") == 0
        || _str.compare("+inf") == 0 || _str.compare("+inff") == 0)
        std::cout << "+inf" << std::endl;
    else if (_str.compare("-inf") == 0 || _str.compare("-inff") == 0)
        std::cout << "-inf" << std::endl;
    else
        std::cout << _d << std::endl;
}

