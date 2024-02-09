#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer default constructor" << std::endl;
}

Serializer::Serializer(const Serializer &s)
{
    *this = s;
}

Serializer &Serializer::operator=(const Serializer &s)
{
    (void)s;
    return (*this);
}

Serializer::~Serializer()
{
    std::cout << "Serializer destructor" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
