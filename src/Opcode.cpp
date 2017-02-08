#include "Opcode.h"

namespace an72
{
    Opcode::Opcode( Cpu6502::RegisterState REG, ReadOnlyMemory ROM, RandomAccessMemory RAM, uint8_t opcode )
    {
        reg = REG;
        rom = ROM;
        ram = RAM;
        op = opcode;
        // TODO: get addressing mode and instruction from opcode
    }

    Opcode::Opcode( const Opcode& other )
    {

    }

    Opcode::~Opcode()
    {
        //TODO: implement if necessary
    }

    Opcode& Opcode::operator=( const Opcode& other )
    {
        //TODO: implement if necessary
    }

    uint64_t Opcode::exec()
    {
        //TODO: write huge switch statement for instruction execution
    }
}