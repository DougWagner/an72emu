#ifndef CPU_H
#define CPU_H

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
            void Reset();
            void Start();
            void Pause();
            void Step();
            void PrintRegs();
    };
}

#endif
