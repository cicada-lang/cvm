#pragma once

struct frame_t {
    size_t program_counter;
};

frame_t *frame_new(size_t program_counter);
void frame_destroy(frame_t **self_pointer);

value_t frame_fetch_value(frame_t *self, ram_t *ram);
uint8_t frame_fetch_byte(frame_t *self, ram_t *ram);
opcode_t frame_fetch_opcode(frame_t *self, ram_t *ram);

bool frame_is_end(const frame_t *self, ram_t *ram);
