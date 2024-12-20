#include "index.h"

name_entry_t *
name_entry_new(char *name) {
    name_entry_t *self = new(name_entry_t);
    self->name = name;
    self->name_table = name_table_new();
    return self;
}

void
name_entry_destroy(name_entry_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        name_entry_t *self = *self_pointer;
        free(self->name);
        name_table_destroy(&self->name_table);
        free(self);
        *self_pointer = NULL;
    }
}
