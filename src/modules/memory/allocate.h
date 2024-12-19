#pragma once

bool address_is_8_bytes_aligned(void *address);

void *allocate(size_t size);
void *allocate_many(size_t size, size_t unit_size);
void *allocate_pointers(size_t size);
