#include "RandomAccessMemory.h"

namespace an72
{
    RandomAccessMemmory::RandomAccessMemmory()
    {
        _clear_all_data();
    }

    RandomAccessMemmory::RandomAccessMemmory( const RandomAccessMemmory& other )
    {
        std::memcpy( &_rawData, &other._rawData, AN72_RAM_SIZE );
    }

    RandomAccessMemmory::~RandomAccessMemmory()
    {
        _clear_all_data();
    }

    RandomAccessMemmory&
    RandomAccessMemmory::RandomAccessMemmory::operator=( const RandomAccessMemmory& other )
    {
        std::memcpy( &_rawData, &other._rawData, AN72_RAM_SIZE );
    }

    void
    RandomAccessMemmory::SetByte( uint16_t addressu16, uint8_t valueu8 )
    {
        assert( addressu16 <= AN72_RAM_LASTADDR && "RandomAccessMemmory::SetByte address out of bounds." );
        _rawData[ addressu16 ] = valueu8;
    }

    uint8_t
    RandomAccessMemmory::GetByte( uint16_t addressu16 ) const
    {
        assert( addressu16 <= AN72_RAM_LASTADDR && "RandomAccessMemmory::GetByte address out of bounds." );
        return _rawData[ addressu16 ];
    }

    uint8_t
    RandomAccessMemmory::operator[]( uint16_t addressu16 ) const
    {
        assert( addressu16 <= AN72_RAM_LASTADDR && "RandomAccessMemmory::operator[] const address out of bounds." );
        return _rawData[ addressu16 ];
    }

    uint8_t&
    RandomAccessMemmory::operator[]( uint16_t addressu16 )
    {
        assert( addressu16 <= AN72_RAM_LASTADDR && "RandomAccessMemmory::operator[] address out of bounds." );
        return _rawData[ addressu16 ];
    }

    void
    RandomAccessMemmory::_set_all_data( uint8_t valueu8 )
    {
        std::memset( &_rawData, valueu8, AN72_RAM_SIZE );
    }

    void
    RandomAccessMemmory::_clear_all_data()
    {
        _set_all_data( 0x00 );
    }
}
