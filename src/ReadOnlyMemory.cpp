

#include "ReadOnlyMemory.h"

namespace an72
{
    ReadOnlyMemory::ReadOnlyMemory()
    {
        _clear_all_data();
    }

    ReadOnlyMemory::ReadOnlyMemory( const ReadOnlyMemory& other )
    {
        std::memcpy( &_rawData, &other._rawData, AN72_ROM_SIZE );
    }

    ReadOnlyMemory::~ReadOnlyMemory()
    {
        _clear_all_data(); // fill with NO OP's
    }

    uint8_t
    ReadOnlyMemory::GetByte( uint16_t addressu16 ) const
    {
        return _rawData[ addressu16 ];
    }

    uint8_t
    ReadOnlyMemory::operator[]( uint16_t addressu16 ) const
    {
        return _rawData[ addressu16 ];
    }

    void
    ReadOnlyMemory::_set_all_data( uint8_t valueu8 )
    {
        std::memset( &_rawData, valueu8, AN72_ROM_SIZE );
    }

    void
    ReadOnlyMemory::_clear_all_data()
    {
        _set_all_data( 0xff ); // TODO(dean): replace 0xff with a properly defined NO OP
    }

    void
    ReadOnlyMemory::_set_byte( uint16_t addressu16, uint8_t valueu8 )
    {
        _rawData[ addressu16 ] = valueu8;
    }
}
