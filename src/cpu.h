#ifndef CPU_H
#define CPU_H

#include "an72.h"

namespace an72
{
    class Cpu6502
    {
        public:

            struct RegisterState
            {
                uint64_t num_cycles; // larger types first for better packing
                uint16_t PC;
                uint8_t A, X, Y, S, P;

                RegisterState();
                RegisterState( const RegisterState& other ) = default;
                RegisterState& operator=( const RegisterState& other ) = default;
            };

        private:
            // processor registers
            RegisterState regs;

        public:
            Cpu6502();
            Cpu6502( const Cpu6502& ) = delete;
            ~Cpu6502();

            void Reset();
            void Step( ReadOnlyMemory * rom, RandomAccessMemmory * ram );
            void Start( ReadOnlyMemory * rom, RandomAccessMemmory * ram );
            void Pause();
            void PrintRegs( std::ostream& out = std::cout ) const;

            RegisterState GetRegisters() const;
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
