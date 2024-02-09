#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include "struct.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &s);
        Serializer &operator=(const Serializer &s);
        ~Serializer();
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif