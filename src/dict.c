#include "index.h"

dict_t *
dict_create(size_t size) {
    dict_t *self = (dict_t *) calloc(1, sizeof(dict_t));
    assert(self);
    self->size = size;
    self->words = (word_t **) calloc(size, sizeof(word_t *));
    assert(self->words);
    return self;
}

void
dict_destroy(dict_t **self_p) {
    assert (self_p);
    if (*self_p) {
        dict_t *self = *self_p;
        dict_purge(self);
        free(self);
        *self_p = NULL;
    }
}

void
dict_purge(dict_t *self) {
    for (size_t index = 0; index < self->size; index++) {
        if (self->words[index]) {
            word_destroy(&self->words[index]);
         }
    }
}
