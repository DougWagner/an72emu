#include "Opcode.h"

namespace an72
{
    Opcode::Opcode( RegisterState* REG, ReadOnlyMemory* ROM, RandomAccessMemmory* RAM, uint8_t opcode )
    {
        reg = REG;
        rom = ROM;
        ram = RAM;
        op = opcode;
        //a_mode = addrm_map[op];
        //instruction = instr_map[op];
    }

    Opcode::Opcode( const Opcode& other )
    {

    }

    Opcode::~Opcode()
    {
        //TODO: implement if necessary
    }

    Opcode& Opcode::operator=( const Opcode& other )
    {
        //TODO: implement if necessary
    }

    uint64_t Opcode::exec() // this function hurts...
    {
        std::cout << std::hex << "opcode " << int(op) << " - addr mode: ";
        switch (addrm_map[op])
        {
            case addrm::acc:
                accumulator();
                break;
            case addrm::imm:
                immediate();
                break;
            case addrm::z_page:
                zero_page();
                break;
            case addrm::z_p_x:
                zero_page_x();
                break;
            case addrm::z_p_y:
                zero_page_y();
                break;
            case addrm::abs:
                absolute();
                break;
            case addrm::abs_x:
                absolute_x();
                break;
            case addrm::abs_y:
                absolute_y();
                break;
            case addrm::imp:
                implied();
                break;
            case addrm::rel:
                relative();
                break;
            case addrm::ind:
                indirect();
                break;
            case addrm::ind_x:
                indirect_x();
                break;
            case addrm::ind_y:
                indirect_y();
                break;
            case addrm::none:
            default:
                std::cout << "none";
                break;
        }
        std::cout << " - instruction: ";
        switch (instr_map[op]) 
        {
            case instr::adc_i: 
                adc_exec();
                break;
            case instr::and_i:
                and_exec();
                break;
            case instr::asl_i:
                asl_exec();
                break;
            case instr::bcc_i: 
                bcc_exec();
                break;
            case instr::bcs_i:
                bcs_exec();
                break;
            case instr::beq_i:
                beq_exec();
                break;
            case instr::bit_i:
                bit_exec();
                break;
            case instr::bmi_i:
                bmi_exec();
                break;
            case instr::bne_i:
                bne_exec();
                break;
            case instr::bpl_i:
                bpl_exec();
                break;
            case instr::brk_i:
                brk_exec();
                break;
            case instr::bvc_i:
                bvc_exec();
                break;
            case instr::bvs_i:
                bvs_exec();
                break;
            case instr::clc_i:
                clc_exec();
                break;
            case instr::cld_i:
                cld_exec();
                break;
            case instr::cli_i:
                cli_exec();
                break;
            case instr::clv_i:
                clv_exec();
                break;
            case instr::cmp_i:
                cmp_exec();
                break;
            case instr::cpx_i:
                cpx_exec();
                break;
            case instr::cpy_i:
                cpy_exec();
                break;
            case instr::dec_i:
                dec_exec();
                break;
            case instr::dex_i:
                dex_exec();
                break;
            case instr::dey_i:
                dey_exec();
                break;
            case instr::eor_i:
                eor_exec();
                break;
            case instr::inc_i:
                inc_exec();
                break;
            case instr::inx_i:
                inx_exec();
                break;
            case instr::iny_i:
                iny_exec();
                break;
            case instr::jmp_i:
                jmp_exec();
                break;
            case instr::jsr_i:
                jsr_exec();
                break;
            case instr::lda_i:
                lda_exec();
                break;
            case instr::ldx_i:
                ldx_exec();
                break;
            case instr::ldy_i:
                ldy_exec();
                break;
            case instr::lsr_i:
                lsr_exec();
                break;
            case instr::nop_i:
                nop_exec();
                break;
            case instr::ora_i:
                ora_exec();
                break;
            case instr::pha_i:
                pha_exec();
                break;
            case instr::php_i:
                php_exec();
                break;
            case instr::pla_i:
                pla_exec();
                break;
            case instr::plp_i:
                plp_exec();
                break;
            case instr::rol_i:
                rol_exec();
                break;
            case instr::ror_i:
                ror_exec();
                break;
            case instr::rti_i:
                rti_exec();
                break;
            case instr::rts_i:
                rts_exec();
                break;
            case instr::sbc_i:
                sbc_exec();
                break;
            case instr::sec_i:
                sec_exec();
                break;
            case instr::sed_i:
                sed_exec();
                break;
            case instr::sei_i:
                sei_exec();
                break;
            case instr::sta_i:
                sta_exec();
                break;
            case instr::stx_i:
                stx_exec();
                break;
            case instr::sty_i:
                sty_exec();
                break;
            case instr::tax_i:
                tax_exec();
                break;
            case instr::tay_i:
                tay_exec();
                break;
            case instr::tsx_i:
                tsx_exec();
                break;
            case instr::txa_i:
                txa_exec();
                break;
            case instr::txs_i:
                txs_exec();
                break;
            case instr::tya_i:
                tya_exec();
                break;
            case instr::illeg:
            default:
                std::cout << "illeg";
                break;
        }
        std::cout << " - ";
    }

    /* Begin Addressing Mode Function Implementations */
    // currently using temporary implementations
    void Opcode::accumulator()
    {
        std::cout << "accumulator";
    }

    void Opcode::immediate()
    {
        std::cout << "immediate";
    }

    void Opcode::Opcode::zero_page()
    {
        std::cout << "zero page";
    }

    void Opcode::zero_page_x()
    {
        std::cout << "zero page x";
    }

    void Opcode::zero_page_y()
    {
        std::cout << "zero page y";
    }

    void Opcode::absolute()
    {
        std::cout << "absolute";
    }

    void Opcode::absolute_x()
    {
        std::cout << "absolute x";
    }

    void Opcode::absolute_y()
    {
        std::cout << "absolute y";
    }

    void Opcode::implied()
    {
        std::cout << "implied";
    }

    void Opcode::relative()
    {
        std::cout << "relative";
    }

    void Opcode::indirect()
    {
        std::cout << "indirect";
    }

    void Opcode::indirect_x()
    {
        std::cout << "indirect x";
    }

    void Opcode::indirect_y()
    {
        std::cout << "indirect y";
    }

    /* Begin Instruction Function Implementations */
    void Opcode::adc_exec()
    {
        std::cout << "adc";
    }

    void Opcode::and_exec()
    {
        std::cout << "and";
    }
    
    void Opcode::asl_exec()
    {
        std::cout << "asl";
    }
    
    void Opcode::bcc_exec()
    {
        std::cout << "bcc";
    }
    
    void Opcode::bcs_exec()
    {
        std::cout << "bcs";
    }
    
    void Opcode::beq_exec()
    {
        std::cout << "beq";
    }
    
    void Opcode::bit_exec()
    {
        std::cout << "bit";
    }
    
    void Opcode::bmi_exec()
    {
        std::cout << "bmi";
    }
    
    void Opcode::bne_exec()
    {
        std::cout << "bne";
    }
    
    void Opcode::bpl_exec()
    {
        std::cout << "bpl";
    }
    
    void Opcode::brk_exec()
    {
        std::cout << "brk";
    }
    
    void Opcode::bvc_exec()
    {
        std::cout << "bvc";
    }
    
    void Opcode::bvs_exec()
    {
        std::cout << "bvs";
    }
    
    void Opcode::clc_exec()
    {
        std::cout << "clc";
    }
    
    void Opcode::cld_exec()
    {
        std::cout << "cld";
    }
    
    void Opcode::cli_exec()
    {
        std::cout << "cli";
    }
    
    void Opcode::clv_exec()
    {
        std::cout << "clv";
    }
    
    void Opcode::cmp_exec()
    {
        std::cout << "cmp";
    }
    
    void Opcode::cpx_exec()
    {
        std::cout << "cpx";
    }
    
    void Opcode::cpy_exec()
    {
        std::cout << "cpy";
    }
    
    void Opcode::dec_exec()
    {
        std::cout << "dec";
    }
    
    void Opcode::dex_exec()
    {
        std::cout << "dex";
    }
    
    void Opcode::dey_exec()
    {
        std::cout << "dey";
    }
    
    void Opcode::eor_exec()
    {
        std::cout << "eor";
    }
    
    void Opcode::inc_exec()
    {
        std::cout << "inc";
    }
    
    void Opcode::inx_exec()
    {
        std::cout << "inx";
    }
    
    void Opcode::iny_exec()
    {
        std::cout << "iny";
    }
    
    void Opcode::jmp_exec()
    {
        std::cout << "jmp";
    }
    
    void Opcode::jsr_exec()
    {
        std::cout << "jsr";
    }
    
    void Opcode::lda_exec()
    {
        std::cout << "lda";
    }
    
    void Opcode::ldx_exec()
    {
        std::cout << "ldx";
    }
    
    void Opcode::ldy_exec()
    {
        std::cout << "ldy";
    }
    
    void Opcode::lsr_exec()
    {
        std::cout << "lsr";
    }
    
    void Opcode::nop_exec()
    {
        std::cout << "nop";
    }
    
    void Opcode::ora_exec()
    {
        std::cout << "ora";
    }
    
    void Opcode::pha_exec()
    {
        std::cout << "pha";
    }
    
    void Opcode::php_exec()
    {
        std::cout << "php";
    }
    
    void Opcode::pla_exec()
    {
        std::cout << "pla";
    }
    
    void Opcode::plp_exec()
    {
        std::cout << "plp";
    }
    
    void Opcode::rol_exec()
    {
        std::cout << "rol";
    }
    
    void Opcode::ror_exec()
    {
        std::cout << "ror";
    }
    
    void Opcode::rti_exec()
    {
        std::cout << "rti";
    }
    
    void Opcode::rts_exec()
    {
        std::cout << "rts";
    }
    
    void Opcode::sbc_exec()
    {
        std::cout << "sbc";
    }
    
    void Opcode::sec_exec()
    {
        std::cout << "sec";
    }
    
    void Opcode::sed_exec()
    {
        std::cout << "sed";
    }
    
    void Opcode::sei_exec()
    {
        std::cout << "sei";
    }
    
    void Opcode::sta_exec()
    {
        std::cout << "sta";
    }
    
    void Opcode::stx_exec()
    {
        std::cout << "stx";
    }
    
    void Opcode::sty_exec()
    {
        std::cout << "sty";
    }
    
    void Opcode::tax_exec()
    {
        std::cout << "tax";
    }
    
    void Opcode::tay_exec()
    {
        std::cout << "tay";
    }
    
    void Opcode::tsx_exec()
    {
        std::cout << "tsx";
    }
    
    void Opcode::txa_exec()
    {
        std::cout << "txa";
    }
    
    void Opcode::txs_exec()
    {
        std::cout << "txs";
    }
    
    void Opcode::tya_exec()
    {
        std::cout << "tya";
    }
}