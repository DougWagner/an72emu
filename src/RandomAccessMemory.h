#ifndef RANDOMACCESSMEMORY_H_INCLUDED
#define RANDOMACCESSMEMORY_H_INCLUDED

#include "general_includes.h"

#define AN72_RAM_SIZE       0x80
#define AN72_RAM_LASTADDR   0x7f

namespace an72
{
    class RandomAccessMemmory
    {
        private:

            uint8_t _rawData[ AN72_RAM_SIZE ];

        public:

            RandomAccessMemmory();
            RandomAccessMemmory( const RandomAccessMemmory& );
            ~RandomAccessMemmory();

            RandomAccessMemmory& operator=( const RandomAccessMemmory& );

            void SetByte( uint16_t addressu16, uint8_t valueu8 );
            uint8_t GetByte( uint16_t addressu16 ) const;

            uint8_t operator[]( uint16_t addressu16 ) const;
            uint8_t& operator[]( uint16_t addressu16 );

        protected:

            void _set_all_data( uint8_t valueu8 );
            void _clear_all_data();
    };
}

#endif // RANDOMACCESSMEMORY_H_INCLUDED
