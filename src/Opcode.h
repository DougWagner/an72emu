#ifndef OPCODE_H_INCLUDED
#define OPCODE_H_INCLUDED

class Opcode;

#include "an72.h"

namespace an72
{
    enum class op_addr_mode : uint8_t
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
    };

    enum class op_instr : uint8_t
    {
        adc_i, and_i, asl_i, bcc_i, bcs_i, beq_i, bit_i, bmi_i, bne_i, bpl_i, brk_i, bvc_i, bvs_i, clc_i,
        cld_i, cli_i, clv_i, cmp_i, cpx_i, cpy_i, dec_i, dex_i, dey_i, eor_i, inc_i, inx_i, iny_i, jmp_i,
        jsr_i, lda_i, ldx_i, ldy_i, lsr_i, nop_i, ora_i, pha_i, php_i, pla_i, plp_i, rol_i, ror_i, rti_i,
        rts_i, sbc_i, sec_i, sed_i, sei_i, sta_i, stx_i, sty_i, tax_i, tay_i, tsx_i, txa_i, txs_i, tya_i,
        illegal_instr
    };

    class Opcode
    {
        private:
            Cpu6502::RegisterState* reg;
            ReadOnlyMemory* rom;
            RandomAccessMemmory* ram;
            uint8_t op, addr, instr; // opcode, addressing mode, instruction

        public:
            Opcode() = delete; // i dont know if this is correct, but we dont want a default constructor
            Opcode( Cpu6502::RegisterState* REG, ReadOnlyMemory* ROM, RandomAccessMemmory* RAM, uint8_t opcode );
            Opcode( const Opcode& other );
            ~Opcode();

            Opcode& operator=( const Opcode& );

            uint64_t exec(); // returns number of cycles needed for execution

    };
}

#endif
