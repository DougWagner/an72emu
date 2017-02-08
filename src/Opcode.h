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

    const addrm addrm_map[256] = {
        /*     |   0        |   1         |   2        |   3        |   4          |   5          |   6           |   7       |   8       |   9         |   A        |   B        |   C         |   D         |   E         |   F        |*/
        /*  0 */addrm::imp,  addrm::ind_x, addrm::none, addrm::none, addrm::none,   addrm::z_page, addrm::z_page, addrm::none, addrm::imp, addrm::imm,   addrm::acc,  addrm::none, addrm::none,  addrm::abs,   addrm::abs,   addrm::none,
        /*  1 */addrm::rel,  addrm::ind_y, addrm::none, addrm::none, addrm::none,   addrm::z_p_x,  addrm::z_p_x,  addrm::none, addrm::imp, addrm::abs_y, addrm::none, addrm::none, addrm::none,  addrm::abs_x, addrm::abs_x, addrm::none,
        /*  2 */addrm::abs,  addrm::ind_x, addrm::none, addrm::none, addrm::z_page, addrm::z_page, addrm::z_page, addrm::none, addrm::imp, addrm::imm,   addrm::acc,  addrm::none, addrm::abs,   addrm::abs,   addrm::abs,   addrm::none,
        /*  3 */addrm::rel,  addrm::ind_y, addrm::none, addrm::none, addrm::none,   addrm::z_p_x,  addrm::z_p_x,  addrm::none, addrm::imp, addrm::abs_y, addrm::none, addrm::none, addrm::none,  addrm::abs_x, addrm::abs_x, addrm::none,
        /*  4 */addrm::imp,  addrm::ind_x, addrm::none, addrm::none, addrm::none,   addrm::z_page, addrm::z_page, addrm::none, addrm::imp, addrm::imm,   addrm::acc,  addrm::none, addrm::abs,   addrm::abs,   addrm::abs,   addrm::none,
        /*  5 */addrm::rel,  addrm::ind_y, addrm::none, addrm::none, addrm::none,   addrm::z_p_x,  addrm::z_p_x,  addrm::none, addrm::imp, addrm::abs_y, addrm::none, addrm::none, addrm::none,  addrm::abs_x, addrm::abs_x, addrm::none,
        /*  6 */addrm::imp,  addrm::ind_x, addrm::none, addrm::none, addrm::none,   addrm::z_page, addrm::z_page, addrm::none, addrm::imp, addrm::imm,   addrm::acc,  addrm::none, addrm::ind,   addrm::abs,   addrm::abs,   addrm::none,
        /*  7 */addrm::rel,  addrm::ind_y, addrm::none, addrm::none, addrm::none,   addrm::z_p_x,  addrm::z_p_x,  addrm::none, addrm::imp, addrm::abs_y, addrm::none, addrm::none, addrm::none,  addrm::abs_x, addrm::abs_x, addrm::none,
        /*  8 */addrm::none, addrm::ind_x, addrm::none, addrm::none, addrm::z_page, addrm::z_page, addrm::z_page, addrm::none, addrm::imp, addrm::none,  addrm::imp,  addrm::none, addrm::abs,   addrm::abs,   addrm::abs,   addrm::none,
        /*  9 */addrm::rel,  addrm::ind_y, addrm::none, addrm::none, addrm::z_p_x,  addrm::z_p_x,  addrm::z_p_y,  addrm::none, addrm::imp, addrm::abs_y, addrm::imp,  addrm::none, addrm::none,  addrm::abs_x, addrm::none,  addrm::none,
        /*  A */addrm::imm,  addrm::ind_x, addrm::imm,  addrm::none, addrm::z_page, addrm::z_page, addrm::z_page, addrm::none, addrm::imp, addrm::imm,   addrm::imp,  addrm::none, addrm::abs,   addrm::abs,   addrm::abs,   addrm::none,
        /*  B */addrm::rel,  addrm::ind_y, addrm::none, addrm::none, addrm::z_p_x,  addrm::z_p_x,  addrm::z_p_y,  addrm::none, addrm::imp, addrm::abs_y, addrm::imp,  addrm::none, addrm::abs_x, addrm::abs_x, addrm::abs_y, addrm::none,
        /*  C */addrm::imm,  addrm::ind_x, addrm::none, addrm::none, addrm::z_page, addrm::z_page, addrm::z_page, addrm::none, addrm::imp, addrm::imm,   addrm::imp,  addrm::none, addrm::abs,   addrm::abs,   addrm::abs,   addrm::none,
        /*  D */addrm::rel,  addrm::ind_y, addrm::none, addrm::none, addrm::none,   addrm::z_p_x,  addrm::z_p_x,  addrm::none, addrm::imp, addrm::abs_y, addrm::none, addrm::none, addrm::none,  addrm::abs_x, addrm::abs_x, addrm::none,
        /*  E */addrm::imm,  addrm::ind_x, addrm::none, addrm::none, addrm::z_page, addrm::z_page, addrm::z_page, addrm::none, addrm::imp, addrm::imm,   addrm::imp,  addrm::none, addrm::abs,   addrm::abs,   addrm::abs,   addrm::none,
        /*  F */addrm::rel,  addrm::ind_y, addrm::none, addrm::none, addrm::none,   addrm::z_p_x,  addrm::z_p_x,  addrm::none, addrm::imp, addrm::abs_y, addrm::none, addrm::none, addrm::none,  addrm::abs_x, addrm::abs_x, addrm::none
    };

    const instr instr_map[256] = {
        /*     |   0         |   1         |   2         |   3         |   4         |   5         |   6         |   7         |   8         |   9         |   A         |   B         |   C         |   D         |   E         |   F         |*/
        /*  0 */instr::brk_i, instr::ora_i, instr::illeg, instr::illeg, instr::illeg, instr::ora_i, instr::asl_i, instr::illeg, instr::php_i, instr::ora_i, instr::asl_i, instr::illeg, instr::illeg, instr::ora_i, instr::asl_i, instr::illeg,
        /*  1 */instr::bpl_i, instr::ora_i, instr::illeg, instr::illeg, instr::illeg, instr::ora_i, instr::asl_i, instr::illeg, instr::clc_i, instr::ora_i, instr::illeg, instr::illeg, instr::illeg, instr::ora_i, instr::asl_i, instr::illeg,
        /*  2 */instr::jsr_i, instr::and_i, instr::illeg, instr::illeg, instr::bit_i, instr::and_i, instr::rol_i, instr::illeg, instr::plp_i, instr::and_i, instr::rol_i, instr::illeg, instr::bit_i, instr::and_i, instr::rol_i, instr::illeg,
        /*  3 */instr::bmi_i, instr::and_i, instr::illeg, instr::illeg, instr::illeg, instr::and_i, instr::rol_i, instr::illeg, instr::sec_i, instr::and_i, instr::illeg, instr::illeg, instr::illeg, instr::and_i, instr::rol_i, instr::illeg,
        /*  4 */instr::rti_i, instr::eor_i, instr::illeg, instr::illeg, instr::illeg, instr::eor_i, instr::lsr_i, instr::illeg, instr::pha_i, instr::eor_i, instr::lsr_i, instr::illeg, instr::jmp_i, instr::eor_i, instr::lsr_i, instr::illeg,
        /*  5 */instr::bvc_i, instr::eor_i, instr::illeg, instr::illeg, instr::illeg, instr::eor_i, instr::lsr_i, instr::illeg, instr::cli_i, instr::eor_i, instr::illeg, instr::illeg, instr::illeg, instr::eor_i, instr::lsr_i, instr::illeg,
        /*  6 */instr::rts_i, instr::adc_i, instr::illeg, instr::illeg, instr::illeg, instr::adc_i, instr::ror_i, instr::illeg, instr::pla_i, instr::adc_i, instr::ror_i, instr::illeg, instr::jmp_i, instr::adc_i, instr::ror_i, instr::illeg,
        /*  7 */instr::bvs_i, instr::adc_i, instr::illeg, instr::illeg, instr::illeg, instr::adc_i, instr::ror_i, instr::illeg, instr::sei_i, instr::adc_i, instr::illeg, instr::illeg, instr::illeg, instr::adc_i, instr::ror_i, instr::illeg,
        /*  8 */instr::illeg, instr::sta_i, instr::illeg, instr::illeg, instr::sty_i, instr::sta_i, instr::stx_i, instr::illeg, instr::dey_i, instr::illeg, instr::txa_i, instr::illeg, instr::sty_i, instr::sta_i, instr::stx_i, instr::illeg,
        /*  9 */instr::bcc_i, instr::sta_i, instr::illeg, instr::illeg, instr::sty_i, instr::sta_i, instr::stx_i, instr::illeg, instr::tya_i, instr::sta_i, instr::txs_i, instr::illeg, instr::illeg, instr::sta_i, instr::illeg, instr::illeg,
        /*  A */instr::ldy_i, instr::lda_i, instr::ldx_i, instr::illeg, instr::ldy_i, instr::lda_i, instr::ldx_i, instr::illeg, instr::tay_i, instr::lda_i, instr::tax_i, instr::illeg, instr::ldy_i, instr::lda_i, instr::ldx_i, instr::illeg,
        /*  B */instr::bcs_i, instr::lda_i, instr::illeg, instr::illeg, instr::ldy_i, instr::lda_i, instr::ldx_i, instr::illeg, instr::clv_i, instr::lda_i, instr::tsx_i, instr::illeg, instr::ldy_i, instr::lda_i, instr::ldx_i, instr::illeg,
        /*  C */instr::cpy_i, instr::cmp_i, instr::illeg, instr::illeg, instr::cpy_i, instr::cmp_i, instr::dec_i, instr::illeg, instr::iny_i, instr::cmp_i, instr::dex_i, instr::illeg, instr::cpy_i, instr::cmp_i, instr::dec_i, instr::illeg,
        /*  D */instr::bne_i, instr::cmp_i, instr::illeg, instr::illeg, instr::illeg, instr::cmp_i, instr::dec_i, instr::illeg, instr::cld_i, instr::cmp_i, instr::illeg, instr::illeg, instr::illeg, instr::cmp_i, instr::dec_i, instr::illeg,
        /*  E */instr::cpx_i, instr::sbc_i, instr::illeg, instr::illeg, instr::cpx_i, instr::sbc_i, instr::inc_i, instr::illeg, instr::inx_i, instr::sbc_i, instr::nop_i, instr::illeg, instr::cpx_i, instr::sbc_i, instr::inc_i, instr::illeg,
        /*  F */instr::beq_i, instr::sbc_i, instr::illeg, instr::illeg, instr::illeg, instr::sbc_i, instr::inc_i, instr::illeg, instr::sed_i, instr::sbc_i, instr::illeg, instr::illeg, instr::illeg, instr::sbc_i, instr::inc_i, instr::illeg
    };

    class Opcode
    {
        private:
            RegisterState* reg;
            ReadOnlyMemory* rom;
            RandomAccessMemmory* ram;
            uint8_t op; // opcode
            instr instruction;
            addrm a_mode;

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
