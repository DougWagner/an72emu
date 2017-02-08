#include "cpu.h"

namespace an72
{
    RegisterState::RegisterState()
    : num_cycles( 0ull ), PC( 0x0000 ), A( 0x00 ), X( 0x00 ), Y( 0x00 ), S( 0xFF ), P( 0x00 )
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
    Cpu6502::Step( ReadOnlyMemory * rom, RandomAccessMemmory * ram )
    {
        std::cout << std::hex << "PC: " << int(regs.PC) << " - ";
        uint8_t opcode_num = rom->GetByte( regs.PC++ );
        Opcode opcode(&regs, rom, ram, opcode_num);
        opcode.exec();
        //std::cout << std::hex << "opcode " << int(opcode) << " read by cpu";
        PrintRegs( std::cout );
        std::cout << std::endl;
        //TODO: get instruction and addressing mode from opcode and execute
    }

    void
    Cpu6502::Start( ReadOnlyMemory * rom, RandomAccessMemmory * ram )
    {
        for ( ;; )
        {
            Step( rom, ram );
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
    Cpu6502::PrintRegs( std::ostream& out ) const
    {
        out << "[ PC:[0x" << std::hex << std::setfill('0') << std::setw(4) << int(regs.PC) << "]";
        out << " P:[0x" << std::hex << std::setfill('0') << std::setw(2) << int(regs.P) << "]";
        out << " A:[0x" << std::hex << std::setfill('0') << std::setw(2) << int(regs.A) << "]";
        out << " X:[0x" << std::hex << std::setfill('0') << std::setw(2) << int(regs.X) << "]";
        out << " Y:[0x" << std::hex << std::setfill('0') << std::setw(2) << int(regs.Y) << "]";
        out << " S:[0x" << std::hex <<  std::setfill('0') <<std::setw(2) << int(regs.S) << "]";
        out << " S:[" << std::dec << std::setfill(' ') << std::setw(0) << regs.num_cycles << "] ]";

    }

    RegisterState
    Cpu6502::GetRegisters() const
    {
        return regs;
    }
}
