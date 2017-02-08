#ifndef ROM_4K_H_INCLUDED
#define ROM_4K_H_INCLUDED

#include "ReadOnlyMemory.h"

namespace an72
{
    namespace Cart
    {
        class ROM_4k : public ReadOnlyMemory
        {
            public:
                ROM_4k( uint8_t * data ) : ReadOnlyMemory( CartSize::rom4k, data ) {}

                inline uint8_t
                AccesMappedByte( uint16_t addressu16 ) const override
                {
                    return _get_raw_byte( addressu16 & 0x0FFF );
                }
        };
    }
}

#endif // ROM_4K_H_INCLUDED
