#include "cpu.h"

namespace an72
{
    Cpu6502::RegisterState::RegisterState()
    : num_cycles( 0ull ), PC( 0x0000 ), P( 0x00 ), A( 0x00 ), X( 0x00 ), Y( 0x00 ), S( 0xFF )
    {

    }

    Cpu6502::Cpu6502()
    : regs()
    {
        Reset();
    }

    Cpu6502::~Cpu6502()
    {
        // nothing needed here yet, i think
    }

    void
    Cpu6502::Reset()
    {
        //PC = 0xFFFC; // vector for ROM start
        regs.PC = 0x0000; // temporary value - for testing purposes
        regs.P  =   0x34;
        regs.A  =   0x00;
        regs.X  =   0x00;
        regs.Y  =   0x00;
        regs.S  =   0xFF;
        regs.num_cycles = 0;
    }

    void
    Cpu6502::Step( ReadOnlyMemory* rom )
    {
        std::cout << std::hex << "PC: " << int(regs.PC) << " - ";
        uint8_t opcode = rom->GetByte( regs.PC++ );
        std::cout << std::hex << "opcode " << int(opcode) << " read by cpu" << std::endl;
        //TODO: get instruction and addressing mode from opcode and execute
    }

    void
    Cpu6502::Start( ReadOnlyMemory* rom )
    {
        for ( ;; )
        {
            Step( rom );
            if (regs.PC == 0xFFFF)
                break;
        } //TODO: add a system for pausing/halting execution
    }

    void
    Cpu6502::Pause()
    {
        //TODO: implement
    }

    void
    Cpu6502::PrintRegs( const std::ostream& out )
    {
        // TODO: implement
    }

    Cpu6502::RegisterState
    Cpu6502::GetRegisters() const
    {
        return regs;
    }
}
