
#include <iostream>

class Data
{
    private:
        std::string Name;
        int X;

    public:
        Data()
        {
            Name = "yes";
            X = 1;
        }

        Data(std::string name, int nb) : Name(name) , X(nb)
        {}

        void prt()
        {
            std::cout << "Name:" << Name << std::endl;
            std::cout << "id:" << X << std::endl;
        }
};

uintptr_t   serialize(Data *data)
{
    return ( reinterpret_cast< uintptr_t >( data ));
}

Data*     deserialze(uintptr_t raw)
{
    return ( reinterpret_cast< Data* >( raw ));
}

int main()
{
    Data *data = new Data("No", 0);
    uintptr_t p;
    
    // data->Name = "yes";
    // data->X = 1;
    
    p = serialize ( data );

    deserialze( p )->prt();

    // std::cout << "Name:" << deserialze( p )->Name << std::endl;
    // std::cout << "id:" << deserialze( p )->X << std::endl;

    delete data;
    return 0;
}