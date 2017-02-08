#ifndef OPCODE_VALUES_H_INCLUDED
#define OPCODE_VALUES_H_INCLUDED

/* put the defines for the values of opcodes here */
/* prefix the code with op_ */

#define op_BRK              0x00    // http://www.6502.org/tutorials/6502opcodes.html#BRK
#define op_ORA_indirect_x   0x01    // http://www.6502.org/tutorials/6502opcodes.html#ORA
#define op_ORA_zero_page    0x05    // http://www.6502.org/tutorials/6502opcodes.html#ORA
#define op_ASL_zero_page    0x06    // http://www.6502.org/tutorials/6502opcodes.html#ASL
#define op_PHP              0x08    // http://www.6502.org/tutorials/6502opcodes.html#PHP
#define op_ORA_immediate    0x09    // http://www.6502.org/tutorials/6502opcodes.html#ORA
#define op_ASL_accumulator  0x0A    // http://www.6502.org/tutorials/6502opcodes.html#ASL
#define op_ORA_absolute     0x0D    // http://www.6502.org/tutorials/6502opcodes.html#ORA
#define op_ASL_absolute     0x0E    // http://www.6502.org/tutorials/6502opcodes.html#ASL
#define op_BPL              0x10    // http://www.6502.org/tutorials/6502opcodes.html#BPL
#define op_ORA_indirect_y   0x11    // http://www.6502.org/tutorials/6502opcodes.html#ORA
#define op_ORA_zero_page_x  0x15    // http://www.6502.org/tutorials/6502opcodes.html#ORA
#define op_ASL_zero_page_x  0x16    // http://www.6502.org/tutorials/6502opcodes.html#ASL
#define op_CLC              0x18    // http://www.6502.org/tutorials/6502opcodes.html#CLC
#define op_ORA_absolute_y   0x19    // http://www.6502.org/tutorials/6502opcodes.html#ORA
#define op_ORA_absolute_x   0x1D    // http://www.6502.org/tutorials/6502opcodes.html#ORA
#define op_ASL_absolute_x   0x1E    // http://www.6502.org/tutorials/6502opcodes.html#ASL
#define op_JSR_absolute     0x20    // http://www.6502.org/tutorials/6502opcodes.html#JSR
#define op_AND_indirect_x   0x21    // http://www.6502.org/tutorials/6502opcodes.html#AND
#define op_BIT_zero_page    0x24    // http://www.6502.org/tutorials/6502opcodes.html#BIT
#define op_AND_zero_page    0x25    // http://www.6502.org/tutorials/6502opcodes.html#AND
#define op_ROL_zero_page    0x26    // http://www.6502.org/tutorials/6502opcodes.html#ROL
#define op_PLP              0x28    // http://www.6502.org/tutorials/6502opcodes.html#PLP
#define op_AND_immediate    0x29    // http://www.6502.org/tutorials/6502opcodes.html#AND
#define op_ROL_accumulator  0x2A    // http://www.6502.org/tutorials/6502opcodes.html#ROL
#define op_BIT_absolute     0x2C    // http://www.6502.org/tutorials/6502opcodes.html#BIT
#define op_AND_absolute     0x2D    // http://www.6502.org/tutorials/6502opcodes.html#AND
#define op_ROL_absolute     0x2E    // http://www.6502.org/tutorials/6502opcodes.html#ROL
#define op_BMI              0x30    // http://www.6502.org/tutorials/6502opcodes.html#BMI
#define op_AND_indirect_y   0x31    // http://www.6502.org/tutorials/6502opcodes.html#AND
#define op_AND_zero_page_x  0x35    // http://www.6502.org/tutorials/6502opcodes.html#AND
#define op_ROL_zero_page_x  0x36    // http://www.6502.org/tutorials/6502opcodes.html#ROL
#define op_SEC              0x38    // http://www.6502.org/tutorials/6502opcodes.html#SEC
#define op_AND_absolute_y   0x39    // http://www.6502.org/tutorials/6502opcodes.html#AND
#define op_AND_absolute_x   0x3D    // http://www.6502.org/tutorials/6502opcodes.html#AND
#define op_ROL_absolute_x   0x3E    // http://www.6502.org/tutorials/6502opcodes.html#ROL
#define op_RTI              0x40    // http://www.6502.org/tutorials/6502opcodes.html#RTI
#define op_EOR_indirect_x   0x41    // http://www.6502.org/tutorials/6502opcodes.html#EOR
#define op_EOR_zero_page    0x45    // http://www.6502.org/tutorials/6502opcodes.html#EOR
#define op_LSR_zero_page    0x46    // http://www.6502.org/tutorials/6502opcodes.html#LSR
#define op_PHA              0x48    // http://www.6502.org/tutorials/6502opcodes.html#PHA
#define op_EOR_immediate    0x49    // http://www.6502.org/tutorials/6502opcodes.html#EOR
#define op_LSR_accumulator  0x4A    // http://www.6502.org/tutorials/6502opcodes.html#LSR
#define op_JMP_absolute     0x4C    // http://www.6502.org/tutorials/6502opcodes.html#JMP
#define op_EOR_absolute     0x4D    // http://www.6502.org/tutorials/6502opcodes.html#EOR
#define op_LSR_absolute     0x4E    // http://www.6502.org/tutorials/6502opcodes.html#LSR
#define op_BVC              0x50    // http://www.6502.org/tutorials/6502opcodes.html#BVC
#define op_EOR_indirect_y   0x51    // http://www.6502.org/tutorials/6502opcodes.html#EOR
#define op_EOR_zero_page_x  0x55    // http://www.6502.org/tutorials/6502opcodes.html#EOR
#define op_LSR_zero_page_x  0x56    // http://www.6502.org/tutorials/6502opcodes.html#LSR
#define op_CLI              0x58    // http://www.6502.org/tutorials/6502opcodes.html#CLI
#define op_EOR_absolute_y   0x59    // http://www.6502.org/tutorials/6502opcodes.html#EOR
#define op_EOR_absolute_x   0x5D    // http://www.6502.org/tutorials/6502opcodes.html#EOR
#define op_LSR_absolute_x   0x5E    // http://www.6502.org/tutorials/6502opcodes.html#LSR
#define op_RTS              0x60    // http://www.6502.org/tutorials/6502opcodes.html#RTS
#define op_ADC_indirect_x   0x61    // http://www.6502.org/tutorials/6502opcodes.html#ADC
#define op_ADC_zero_page    0x65    // http://www.6502.org/tutorials/6502opcodes.html#ADC
#define op_ROR_zero_page    0x66    // http://www.6502.org/tutorials/6502opcodes.html#ROR
#define op_PLA              0x68    // http://www.6502.org/tutorials/6502opcodes.html#PLA
#define op_ADC_immediate    0x69    // http://www.6502.org/tutorials/6502opcodes.html#ADC
#define op_ROR_accumulator  0x6A    // http://www.6502.org/tutorials/6502opcodes.html#ROR
#define op_JMP_indirect     0x6C    // http://www.6502.org/tutorials/6502opcodes.html#JMP
#define op_ADC_absolute     0x6D    // http://www.6502.org/tutorials/6502opcodes.html#ADC
#define op_ROR_absolute     0x6E    // http://www.6502.org/tutorials/6502opcodes.html#ROR
#define op_BVS              0x70    // http://www.6502.org/tutorials/6502opcodes.html#BVS
#define op_ADC_indirect_y   0x71    // http://www.6502.org/tutorials/6502opcodes.html#ADC
#define op_ADC_zero_page_x  0x75    // http://www.6502.org/tutorials/6502opcodes.html#ADC
#define op_ROR_zero_page_x  0x76    // http://www.6502.org/tutorials/6502opcodes.html#ROR
#define op_SEI              0x78    // http://www.6502.org/tutorials/6502opcodes.html#SEI
#define op_ADC_absolute_y   0x79    // http://www.6502.org/tutorials/6502opcodes.html#ADC
#define op_ADC_absolute_x   0x7D    // http://www.6502.org/tutorials/6502opcodes.html#ADC
#define op_ROR_absolute_x   0x7E    // http://www.6502.org/tutorials/6502opcodes.html#ROR
#define op_STA_indirect_x   0x81    // http://www.6502.org/tutorials/6502opcodes.html#STA
#define op_STY_zero_page    0x84    // http://www.6502.org/tutorials/6502opcodes.html#STY
#define op_STA_zero_page    0x85    // http://www.6502.org/tutorials/6502opcodes.html#STA
#define op_STX_zero_page    0x86    // http://www.6502.org/tutorials/6502opcodes.html#STX
#define op_DEY              0x88    // http://www.6502.org/tutorials/6502opcodes.html#DEY
#define op_TXA              0x8A    // http://www.6502.org/tutorials/6502opcodes.html#TXA
#define op_STY_absolute     0x8C    // http://www.6502.org/tutorials/6502opcodes.html#STY
#define op_STA_absolute     0x8D    // http://www.6502.org/tutorials/6502opcodes.html#STA
#define op_STX_absolute     0x8E    // http://www.6502.org/tutorials/6502opcodes.html#STX
#define op_BCC              0x90    // http://www.6502.org/tutorials/6502opcodes.html#BCC
#define op_STA_indirect_y   0x91    // http://www.6502.org/tutorials/6502opcodes.html#STA
#define op_STY_zero_page_x  0x94    // http://www.6502.org/tutorials/6502opcodes.html#STY
#define op_STA_zero_page_x  0x95    // http://www.6502.org/tutorials/6502opcodes.html#STA
#define op_STX_zero_page_y  0x96    // http://www.6502.org/tutorials/6502opcodes.html#STX
#define op_TYA              0x98    // http://www.6502.org/tutorials/6502opcodes.html#TYA
#define op_STA_absolute_y   0x99    // http://www.6502.org/tutorials/6502opcodes.html#STA
#define op_TXS              0x9A    // http://www.6502.org/tutorials/6502opcodes.html#TXS
#define op_STA_absolute_x   0x9D    // http://www.6502.org/tutorials/6502opcodes.html#STA
#define op_LDY_immediate    0xA0    // http://www.6502.org/tutorials/6502opcodes.html#LDY
#define op_LDA_indirect_x   0xA1    // http://www.6502.org/tutorials/6502opcodes.html#LDA
#define op_LDX_immediate    0xA2    // http://www.6502.org/tutorials/6502opcodes.html#LDX
#define op_LDY_zero_page    0xA4    // http://www.6502.org/tutorials/6502opcodes.html#LDY
#define op_LDA_zero_page    0xA5    // http://www.6502.org/tutorials/6502opcodes.html#LDA
#define op_LDX_zero_page    0xA6    // http://www.6502.org/tutorials/6502opcodes.html#LDX
#define op_TAY              0xA8    // http://www.6502.org/tutorials/6502opcodes.html#TAY
#define op_LDA_immediate    0xA9    // http://www.6502.org/tutorials/6502opcodes.html#LDA
#define op_TAX              0xAA    // http://www.6502.org/tutorials/6502opcodes.html#TAX
#define op_LDY_absolute     0xAC    // http://www.6502.org/tutorials/6502opcodes.html#LDY
#define op_LDA_absolute     0xAD    // http://www.6502.org/tutorials/6502opcodes.html#LDA
#define op_LDX_absolute     0xAE    // http://www.6502.org/tutorials/6502opcodes.html#LDX
#define op_BCS              0xB0    // http://www.6502.org/tutorials/6502opcodes.html#BCS
#define op_LDA_indirect_y   0xB1    // http://www.6502.org/tutorials/6502opcodes.html#LDA
#define op_LDY_zero_page_x  0xB4    // http://www.6502.org/tutorials/6502opcodes.html#LDY
#define op_LDA_zero_page_x  0xB5    // http://www.6502.org/tutorials/6502opcodes.html#LDA
#define op_LDX_zero_page_y  0xB6    // http://www.6502.org/tutorials/6502opcodes.html#LDX
#define op_CLV              0xB8    // http://www.6502.org/tutorials/6502opcodes.html#CLV
#define op_LDA_absolute_y   0xB9    // http://www.6502.org/tutorials/6502opcodes.html#LDA
#define op_TSX              0xBA    // http://www.6502.org/tutorials/6502opcodes.html#TSX
#define op_LDY_absolute_x   0xBC    // http://www.6502.org/tutorials/6502opcodes.html#LDY
#define op_LDA_absolute_x   0xBD    // http://www.6502.org/tutorials/6502opcodes.html#LDA
#define op_LDX_absolute_y   0xBE    // http://www.6502.org/tutorials/6502opcodes.html#LDX
#define op_CPY_immediate    0xC0    // http://www.6502.org/tutorials/6502opcodes.html#CPY
#define op_CMP_indirect_x   0xC1    // http://www.6502.org/tutorials/6502opcodes.html#CMP
#define op_CPY_zero_page    0xC4    // http://www.6502.org/tutorials/6502opcodes.html#CPY
#define op_CMP_zero_page    0xC5    // http://www.6502.org/tutorials/6502opcodes.html#CMP
#define op_DEC_zero_page    0xC6    // http://www.6502.org/tutorials/6502opcodes.html#DEC
#define op_INY              0xC8    // http://www.6502.org/tutorials/6502opcodes.html#INY
#define op_CMP_immediate    0xC9    // http://www.6502.org/tutorials/6502opcodes.html#CMP
#define op_DEX              0xCA    // http://www.6502.org/tutorials/6502opcodes.html#DEX
#define op_CPY_absolute     0xCC    // http://www.6502.org/tutorials/6502opcodes.html#CPY
#define op_CMP_absolute     0xCD    // http://www.6502.org/tutorials/6502opcodes.html#CMP
#define op_DEC_absolute     0xCE    // http://www.6502.org/tutorials/6502opcodes.html#DEC
#define op_BNE              0xD0    // http://www.6502.org/tutorials/6502opcodes.html#BNE
#define op_CMP_indirect_y   0xD1    // http://www.6502.org/tutorials/6502opcodes.html#CMP
#define op_CMP_zero_page_x  0xD5    // http://www.6502.org/tutorials/6502opcodes.html#CMP
#define op_DEC_zero_page_x  0xD6    // http://www.6502.org/tutorials/6502opcodes.html#DEC
#define op_CLD              0xD8    // http://www.6502.org/tutorials/6502opcodes.html#CLD
#define op_CMP_absolute_y   0xD9    // http://www.6502.org/tutorials/6502opcodes.html#CMP
#define op_CMP_absolute_x   0xDD    // http://www.6502.org/tutorials/6502opcodes.html#CMP
#define op_DEC_absolute_x   0xDE    // http://www.6502.org/tutorials/6502opcodes.html#DEC
#define op_CPX_immediate    0xE0    // http://www.6502.org/tutorials/6502opcodes.html#CPX
#define op_SBC_indirect_x   0xE1    // http://www.6502.org/tutorials/6502opcodes.html#SBC
#define op_CPX_zero_page    0xE4    // http://www.6502.org/tutorials/6502opcodes.html#CPX
#define op_SBC_zero_page    0xE5    // http://www.6502.org/tutorials/6502opcodes.html#SBC
#define op_INC_zero_page    0xE6    // http://www.6502.org/tutorials/6502opcodes.html#INC
#define op_INX              0xE8    // http://www.6502.org/tutorials/6502opcodes.html#INX
#define op_SBC_immediate    0xE9    // http://www.6502.org/tutorials/6502opcodes.html#SBC
#define op_NOP              0xEA    // http://www.6502.org/tutorials/6502opcodes.html#NOP
#define op_CPX_absolute     0xEC    // http://www.6502.org/tutorials/6502opcodes.html#CPX
#define op_SBC_absolute     0xED    // http://www.6502.org/tutorials/6502opcodes.html#SBC
#define op_INC_absolute     0xEE    // http://www.6502.org/tutorials/6502opcodes.html#INC
#define op_BEQ              0xF0    // http://www.6502.org/tutorials/6502opcodes.html#BEQ
#define op_SBC_indirect_y   0xF1    // http://www.6502.org/tutorials/6502opcodes.html#SBC
#define op_SBC_zero_page_x  0xF5    // http://www.6502.org/tutorials/6502opcodes.html#SBC
#define op_INC_zero_page_x  0xF6    // http://www.6502.org/tutorials/6502opcodes.html#INC
#define op_SED              0xF8    // http://www.6502.org/tutorials/6502opcodes.html#SED
#define op_SBC_absolute_y   0xF9    // http://www.6502.org/tutorials/6502opcodes.html#SBC
#define op_SBC_absolute_x   0xFD    // http://www.6502.org/tutorials/6502opcodes.html#SBC
#define op_INC_absolute_x   0xFE    // http://www.6502.org/tutorials/6502opcodes.html#INC

#endif // OPCODE_VALUES_H_INCLUDED
