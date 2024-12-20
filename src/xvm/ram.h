#pragma once

struct ram_t {
    size_t size;
    uint8_t *bytes;
};

ram_t *ram_new(size_t size);
void ram_destroy(ram_t **self_pointer);

void ram_expand(ram_t *self, size_t size);

uint8_t ram_load_byte(ram_t *self, size_t address);
value_t ram_load_value(ram_t *self, size_t address);
opcode_t ram_load_opcode(ram_t *self, size_t address);

void ram_store_byte(ram_t *self, size_t address, uint8_t byte);
void ram_store_value(ram_t *self, size_t address, value_t value);
void ram_store_opcode(ram_t *self, size_t address, opcode_t opcode);
