#include "ReadOnlyMemory.h"

#include "an72.h"

namespace an72
{
    ReadOnlyMemory::ReadOnlyMemory( CartSize cartSize )
    : _cartSize( cartSize )
    {
        _clear_all_data();
    }

    ReadOnlyMemory::ReadOnlyMemory( CartSize cartSize, uint8_t * data )
    : _cartSize( cartSize )
    {
        _clear_all_data();
        std::memcpy( &_rawData, data, (std::size_t)_cartSize );
    }

    ReadOnlyMemory::ReadOnlyMemory( const ReadOnlyMemory& other )
    : _cartSize( other._cartSize )
    {
        _clear_all_data();
        std::memcpy( &_rawData, &other._rawData, AN72_ROM_SIZE );
    }

    ReadOnlyMemory::~ReadOnlyMemory()
    {
        _clear_all_data(); // fill with NO OP's
    }

    ReadOnlyMemory&
    ReadOnlyMemory::operator=( const ReadOnlyMemory& other )
    {
        _clear_all_data();
        _cartSize = other._cartSize;
        std::memcpy( &_rawData, &other._rawData, AN72_ROM_SIZE );
    }

    uint8_t
    ReadOnlyMemory::GetByte( uint16_t addressu16 ) const
    {
        assert( addressu16 <= AN72_ROM_LASTADDR && "ReadOnlyMemory::GetByte address out of bounds." );
        return AccesMappedByte( addressu16 );
    }

    uint8_t
    ReadOnlyMemory::operator[]( uint16_t addressu16 ) const
    {
        assert( addressu16 <= AN72_ROM_LASTADDR && "ReadOnlyMemory::operator[] const address out of bounds." );
        return AccesMappedByte( addressu16 );
    }

    uint16_t
    ReadOnlyMemory::GetSize() const
    {
        return (uint16_t)_cartSize;
    }

    void
    ReadOnlyMemory::Print( std::ostream& out ) const
    {
        const bool addressPrepend = false;
        if( addressPrepend )
        {
            out << "0000  ";
        }

        for( std::size_t i = 0; i < (uint16_t)_cartSize; ++i )
        {
            out << std::hex << std::setfill('0') << std::setw(2) << int(_get_raw_byte( i )) << " ";
            std::size_t n = i + 1;
            if( n % 4 == 0 )
            {
                out << " ";
            }
            if( n % 32 == 0 && n < (uint16_t)_cartSize )
            {
                out << std::endl;
                if( addressPrepend )
                {
                    out << std::setfill('0') << std::setw(4) << i << "  ";
                }
            }
        }
    }

    uint8_t
    ReadOnlyMemory::AccesMappedByte( uint16_t addressu16 ) const
    {
        return _get_raw_byte( addressu16 );
    }

    void
    ReadOnlyMemory::_set_all_data( uint8_t valueu8 )
    {
        std::memset( &_rawData, valueu8, AN72_ROM_SIZE );
    }

    void
    ReadOnlyMemory::_clear_all_data()
    {
        _set_all_data( op_BRK ); // Break opcode
    }

    void
    ReadOnlyMemory::_set_byte( uint16_t addressu16, uint8_t valueu8 )
    {
        assert( addressu16 <= AN72_ROM_LASTADDR && "ReadOnlyMemory::_set_byte address out of bounds." );
        _rawData[ addressu16 ] = valueu8;
    }

    uint8_t
    ReadOnlyMemory::_get_raw_byte( uint16_t addressu16 ) const
    {
        return _rawData[ addressu16 ];
    }

    void
    ReadOnlyMemory::_set_data( CartSize size, uint8_t * data )
    {
        _cartSize = size;
        _clear_all_data();
        std::memcpy( &_rawData, data, (std::size_t)_cartSize );
    }
}
