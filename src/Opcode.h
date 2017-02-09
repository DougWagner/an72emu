#ifndef OPCODE_H_INCLUDED
#define OPCODE_H_INCLUDED

class Opcode;

#include "general_includes.h"
#include "cpu.h"
#include "ReadOnlyMemory.h"
#include "RandomAccessMemory.h"

namespace an72
{
    enum class addrm : uint8_t
    {
        acc,    // accumulator
        imm,    // immediate
        z_page, // zero page
        z_p_x,  // zero page x
        z_p_y,  // zero page y
        abs,    // absolute
        abs_x,  // absolute x
        abs_y,  // absolute y
        imp,    // implied
        rel,    // relative
        ind,    // indirect (only used for JMP instruction)
        ind_x,  // indirect x
        ind_y,  // indirect y
        none
    };

    enum class instr : uint8_t
    {
        adc_i, and_i, asl_i, bcc_i, bcs_i, beq_i, bit_i, bmi_i, bne_i, bpl_i, brk_i, bvc_i, bvs_i, clc_i,
        cld_i, cli_i, clv_i, cmp_i, cpx_i, cpy_i, dec_i, dex_i, dey_i, eor_i, inc_i, inx_i, iny_i, jmp_i,
        jsr_i, lda_i, ldx_i, ldy_i, lsr_i, nop_i, ora_i, pha_i, php_i, pla_i, plp_i, rol_i, ror_i, rti_i,
        rts_i, sbc_i, sec_i, sed_i, sei_i, sta_i, stx_i, sty_i, tax_i, tay_i, tsx_i, txa_i, txs_i, tya_i,
        illeg
    };

    class Opcode
    {
        private:
            RegisterState* reg;
            ReadOnlyMemory* rom;
            RandomAccessMemmory* ram;
            uint8_t op; // opcode number
            //instr instruction;
            //addrm a_mode;
            static addrm addrm_map[256];
            static instr instr_map[256];
            static uint8_t cycle_map[256];

        public:
            Opcode() = delete;
            Opcode( RegisterState* REG, ReadOnlyMemory* ROM, RandomAccessMemmory* RAM, uint8_t opcode );
            Opcode( const Opcode& other );
            ~Opcode();

            Opcode& operator=( const Opcode& );

            uint64_t exec(); // returns number of cycles needed for execution

        protected:
        /* Addressing Mode Functions */
            void accumulator();
            void immediate();
            void zero_page();
            void zero_page_x();
            void zero_page_y();
            void absolute();
            void absolute_x();
            void absolute_y();
            void implied();
            void relative();
            void indirect();
            void indirect_x();
            void indirect_y();

        /* Instruction Functions */
            void adc_exec();
            void and_exec();
            void asl_exec();
            void bcc_exec();
            void bcs_exec();
            void beq_exec();
            void bit_exec();
            void bmi_exec();
            void bne_exec();
            void bpl_exec();
            void brk_exec();
            void bvc_exec();
            void bvs_exec();
            void clc_exec();
            void cld_exec();
            void cli_exec();
            void clv_exec();
            void cmp_exec();
            void cpx_exec();
            void cpy_exec();
            void dec_exec();
            void dex_exec();
            void dey_exec();
            void eor_exec();
            void inc_exec();
            void inx_exec();
            void iny_exec();
            void jmp_exec();
            void jsr_exec();
            void lda_exec();
            void ldx_exec();
            void ldy_exec();
            void lsr_exec();
            void nop_exec();
            void ora_exec();
            void pha_exec();
            void php_exec();
            void pla_exec();
            void plp_exec();
            void rol_exec();
            void ror_exec();
            void rti_exec();
            void rts_exec();
            void sbc_exec();
            void sec_exec();
            void sed_exec();
            void sei_exec();
            void sta_exec();
            void stx_exec();
            void sty_exec();
            void tax_exec();
            void tay_exec();
            void tsx_exec();
            void txa_exec();
            void txs_exec();
            void tya_exec();
    };
}

#endif
