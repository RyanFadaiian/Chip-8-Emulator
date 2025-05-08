#include <cstdint>
#include <iostream>
#include "chip8.hpp"

uint16_t Chip8::fetch() {
    uint16_t combination = (memory[pc] << 8) | memory[pc + 1];
    pc += 2;
}


void Chip8::decode_and_execute(uint16_t opcode) {
    if (opcode == 0x00E0) {
        for (int i = 0; i < 64 * 32; ++i)
            gfx[i] = 0;
        draw_flag = true;
    }
    else if (opcode == 0x00EE) {
        if (sp > 0) 
            sp--;
        else
            sp = 16;
        pc = stack[sp];
    }
}