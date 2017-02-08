#ifndef OPCODE_H_INCLUDED
#define OPCODE_H_INCLUDED

#include "an72.h"

namespace an72
{
    enum op_addr_mode : uint8_t
    {
        none,
        immediate,
        zero_page,
        zero_page_x,
        absolute,
        absolute_x,
        absolute_y,
        indirect_x,
        indirect_y
    }

    enum op_instr : uint8_t
    {
        adc, and, asl, bcc, bcs, beq, bit, bmi, bne, bpl, brk, bvc, bvs, clc,
        cld, cli, clv, cmp, cpx, cpy, dec, dex, dey, eor, inc, inx, iny, jmp, 
        jsr, lda, ldx, ldy, lsr, nop, ora, pha, php, pla, plp, rol, ror, rti, 
        rts, sbc, sec, sed, sei, sta, stx, sty, tax, tay, tsx, txa, txs, tya
    }

    class Opcode
    {
        private:
            Cpu6502::RegisterState reg;
            ReadOnlyMemory rom;
            RandomAccessMemmory ram;
            uint8_t op, addr, instr; // opcode, addressing mode, instruction

        public:
            Opcode() = delete; // i dont know if this is correct, but we dont want a default constructor
            Opcode( Cpu6502::RegisterState REG, ReadOnlyMemory ROM, RandomAccessMemory RAM, uint8_t opcode );
            Opcode( const Opcode& );
            ~Opcode();

            Opcode& operator=( const Opcode& );

            uint64_t exec(); // returns number of cycles needed for execution

    }
}

#endif