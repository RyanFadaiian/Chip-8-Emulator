#include <cstdint>
#include <iostream>

class Chip8 {
public:
    uint8_t memory[4096];

    // Registers
    uint8_t V[16];

    // Program Counter
    uint16_t pc = 512;

    uint16_t stack[16];
    uint8_t sp = 0;

    uint8_t delay_timer = 0;
    uint8_t sound_timer = 0;

    uint8_t gfx[64*32];
 
    bool draw_flag = false;

private:
    uint16_t fetch();
    void decode_and_execute(uint16_t opcode);
};