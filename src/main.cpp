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

    an72::ReadOnlyMemory rom( an72::CartSize::rom4k, rawData );*/

    an72::ReadOnlyMemory rom( an72::CartSize::rom4k );

    std::cout << "0001  ";

    for( std::size_t i = 0; i < rom.GetSize(); ++i )
    {
        std::cout << std::hex << std::setfill('0') << std::setw(2) << int(rom[ i ]) << " ";
        std::size_t n = i + 1;
        if( n % 4 == 0 )
        {
            std::cout << " ";
        }
        if( n % 32 == 0 && n < rom.GetSize() )
        {
            std::cout << std::endl << std::setfill('0') << std::setw(4) << n << "  ";
        }
    }

    an72::Cpu6502 cpu;
    //cpu.Start( &rom );
    for( std::size_t i = 0; i < rom.GetSize(); ++i )
    {
        cpu.Step( &rom );
    }

    std::cout << "Hello world!" << std::endl;
    return 0;
}
