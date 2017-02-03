#include <iostream>

#include "an72.h"

// simple ROM test class to expose _set_byte() as it is protected in an72::ReadOnlyMemory
class ROMTest : public an72::ReadOnlyMemory
{
    public:
        ROMTest() = default;
        using ReadOnlyMemory::_set_byte; // force to public
};

int main()
{
    ROMTest rom;

    rom._set_byte( 0x0000, 0x00 );

    std::cout << int(rom[ 0x0000 ]) << std::endl;
    std::cout << int(rom[ 0x0001 ]) << std::endl;

    std::cout << "Hello world!" << std::endl;
    return 0;
}
