#include "an72.h"

int main()
{
    std::ios_base::sync_with_stdio( false );

    std::cout << "Hello World!" << std::endl;

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

    /* to test all opcodes, make ReadOnlyMemory::_set_byte public and uncomment the loop.

       the loop will store all opcodes 0-255 (including illegal opcodes)
       into ROM addresses 0xf00 - 0xfff so cpu step can test the opcode class
    for (std::size_t i = 0; i <= 0xff; ++i) 
    {
        rom._set_byte(0xf00 + (uint16_t)i, (uint8_t)i);
    }
    */

    an72::Cpu6502 cpu;
    //cpu.Start( &rom );
    for( std::size_t i = 0; i < rom.GetSize(); ++i )
    {
        cpu.Step( &rom, &ram );
    }

    std::cout << "Goodbye world!" << std::endl;
    return 0;
}
