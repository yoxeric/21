
#include <iostream>

class Base
{
    public:
        virtual ~Base() {};
};

class A : public Base{};
class B : public Base{};
class C : public Base{};
class D : public Base{};

Base * generate(void)
{
    srand(time(NULL));
    if ( std::rand() % 3 == 0)
        return ( new A );
    else if ( std::rand() % 3 == 1)
        return ( new B );
    else if ( std::rand() % 3 == 2)
        return ( new C );
    else
        return ( new D );
}

void identify(Base *p)
{
    if ( dynamic_cast< A* >( p ))
        std::cout << "A" << std::endl;
    else if ( dynamic_cast< B* >( p ))
        std::cout << "B" << std::endl;
    else if ( dynamic_cast< C* >( p ))
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown" << std::endl;
}

void identify(Base &p)
{
    int x = 0;

    try
    {
        A& a = dynamic_cast< A& >( p );
        std::cout << "A" <<std::endl;
        (void)(a);
    }
    catch (const std::exception& e) {
        x++;
    }
    try
    {
        B& b = dynamic_cast< B& >( p );
        std::cout << "B" <<std::endl;
        (void)(b);
    }
    catch (const std::exception& e) {
        x++;
    }
    try
    {
        C& c = dynamic_cast< C& >( p );
        std::cout << "C" <<std::endl;
        (void)(c);
    }
    catch (const std::exception& e) {
        x++;
    }

    if (x == 3)
        std::cout << "unknown" << std::endl;
};

int main()
{
    Base* cls = generate();

    std::cout << "class* = ";
    identify( cls );
    std::cout << "class& = ";
    identify( *cls );
    std::cout << std::endl;

    delete cls;

    return (0);
}