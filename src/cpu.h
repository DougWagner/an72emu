#ifndef CPU_H
#define CPU_H

#include "an72.h"

namespace an72
{
    class Cpu6502
    {
        private:
            // processor registers
            uint8_t A, X, Y, S, P; // A: accumulator, X and Y: general purpose, S: stack pointer, P: processor status flags
            uint16_t PC; // Program counter

            // misc variables
            uint64_t num_cycles; // number of cycles is 64 bit so emulator can run for 300 years before overflow

        public:
            Cpu6502();
            Cpu6502( const Cpu6502& ) = delete;
            ~Cpu6502();

            void Reset();
            void Step( ReadOnlyMemory* rom );
            void Start( ReadOnlyMemory* rom );
            void Pause();
            void PrintRegs( const std::ostream& out = std::cout );
    };

    /*
    class CpuRewinder : public Cpu6502
    {
        private:
            std::vector<RegisterState> _registerStates;
            std::vector<RandomAccessMemmory> _ramStates;
        public:
            // ...

            void
            Step() override
            {
                _registerStates.push_back( currentRegister_object );
                _registerStates.push_back( currentRAM_object );
                Cpu6502::Step();
            }
    };
    */
}

#endif
