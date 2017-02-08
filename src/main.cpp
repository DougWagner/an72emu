#include "an72.h"

int main()
{
    std::ios_base::sync_with_stdio( false );

    /*std::ifstream file( "", std::ios_base::in | std::ios_base::binary );

    file.seekg( 0, file.end );
    int length = file.tellg();
    file.seekg( 0, file.beg );
    uint8_t * rawData = new uint8_t[ length ];
    file.read( (char*)rawData, length );
    file.close();
    std::cout << length << std::endl;

    an72::Cart::ROM_4k rom( rawData );*/

    an72::ReadOnlyMemory rom( an72::CartSize::rom4k );

    an72::RandomAccessMemmory ram;

    an72::Cpu6502 cpu;
    //cpu.Start( &rom );
    for( std::size_t i = 0; i < rom.GetSize(); ++i )
    {
        cpu.Step( &rom, &ram );
    }

    std::cout << "Hello world!" << std::endl;
    return 0;
}
