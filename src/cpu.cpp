#include "cpu.h"

namespace an72
{
    Cpu6502::Cpu6502()
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
        PC = 0x0000; // temporary value - for testing purposes
        P = 0x34;
        A = 0;
        X = 0;
        Y = 0;
        S = 0xFF;
        num_cycles = 0;
    }

    void 
    Cpu6502::Step( ReadOnlyMemory* rom )
    {
        std::cout << std::hex << "PC: " << int(PC) << " - ";
        uint8_t opcode = rom->GetByte( PC++ );
        std::cout << std::hex << "opcode " << int(opcode) << " read by cpu" << std::endl;
        //TODO: get instruction and addressing mode from opcode and execute
    }

    void 
    Cpu6502::Start( ReadOnlyMemory* rom )
    {
        for ( ;; )
        {
            Step( rom );
            if (PC == 0xFFFF)
                break;
        } //TODO: add a system for pausing/halting execution
    }

    void 
    Cpu6502::Pause()
    {
        //TODO: implement
    }
}