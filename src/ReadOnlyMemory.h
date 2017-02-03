#ifndef READONLYMEMORY_H_INCLUDED
#define READONLYMEMORY_H_INCLUDED

#include "an72.h"

#define AN72_ROM_SIZE       0x10000
#define AN72_ROM_LASTADDR   0x0ffff

namespace an72
{
    class ReadOnlyMemory
    {
        private:

            uint8_t _rawData[0x10000]; // [0x0000,0xffff]

        public:
            ReadOnlyMemory();
            ReadOnlyMemory( const ReadOnlyMemory& );
            ~ReadOnlyMemory();

            ReadOnlyMemory& operator=( const ReadOnlyMemory& );

            uint8_t GetByte( uint16_t addressu16 ) const;
            uint8_t operator[]( uint16_t addressu16 ) const;

            // we don't want the operator[] for anything other than uint8_t and uint16_t
            template < typename GeneralType1, typename GeneralType2 >
            GeneralType1 operator[]( GeneralType2 ) const = delete;

            template < typename GeneralType1, typename GeneralType2 >
            GeneralType1& operator[]( GeneralType2 ) = delete;

        protected:

            void _set_all_data( uint8_t valueu8 );
            void _clear_all_data();
            void _set_byte( uint16_t addressu16, uint8_t valueu8 );
    };
}

#endif // READONLYMEMORY_H_INCLUDED
