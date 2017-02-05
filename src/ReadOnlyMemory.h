#ifndef READONLYMEMORY_H_INCLUDED
#define READONLYMEMORY_H_INCLUDED

#include "an72.h"

#define AN72_ROM_SIZE       0x10000
#define AN72_ROM_LASTADDR   0x0ffff

namespace an72
{
    // note enum class means the enums can only be accessed like CartSize::rom2k, requires c++11
    enum class CartSize : uint16_t // 16bits, directly used as a size, do not mix them together >:(
    {
        rom2k  =  2048,
        rom4k  =  4096,
        rom8k  =  8192,
        rom16k = 16384,
        rom32k = 32768
        //rom64k = 65536
    };

    // TODO(dean): rework to support the correct memory sizes of atari2600 carts and nes carts.
    class ReadOnlyMemory
    {
        private:

            uint8_t _rawData[ AN72_ROM_SIZE ]; // [0x0000,0xffff]

            CartSize _cartSize;

        public:

            ReadOnlyMemory( CartSize cartSize );
            ReadOnlyMemory( CartSize cartSize, uint8_t * data );
            ReadOnlyMemory( const ReadOnlyMemory& );
            ~ReadOnlyMemory();

            ReadOnlyMemory& operator=( const ReadOnlyMemory& );

            uint8_t GetByte( uint16_t addressu16 ) const;
            uint8_t operator[]( uint16_t addressu16 ) const;

            uint16_t GetSize() const;

        protected:

            void _set_all_data( uint8_t valueu8 );
            void _clear_all_data();
            void _set_byte( uint16_t addressu16, uint8_t valueu8 );
            void _set_data( CartSize size, uint8_t * data );
    };
}

#endif // READONLYMEMORY_H_INCLUDED
