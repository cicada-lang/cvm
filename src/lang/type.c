#include "index.h"

enum type_tag_t {
    TYPE_VAR,
    TYPE_TERM,
};

typedef struct _type_var_t type_var_t;
typedef struct _type_term_t type_term_t;

struct _type_var_t {
    char *name;
};

struct _type_term_t {
    char *name;
    size_t arity;
    type_t **arg_types;
};

struct _type_t {
    enum type_tag_t tag;
    union {
        type_var_t *type_var;
        type_term_t *type_term;
    };
};

type_t *
type_var_create(const char *name) {
    type_t *self = allocate(sizeof(type_t));
    self->tag = TYPE_VAR;
    self->type_var = allocate(sizeof(type_var_t));
    self->type_var->name = string_dup(name);
    return self;
}

type_t *
type_term_create(const char *name, size_t arity) {
    type_t *self = allocate(sizeof(type_t));
    self->tag = TYPE_VAR;
    self->type_term = allocate(sizeof(type_term_t));
    self->type_term->name = string_dup(name);
    self->type_term->arity = arity;
    self->type_term->arg_types = allocate_array(arity, sizeof(type_t));
    return self;
}

void
type_destroy(type_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        type_t *self = *self_pointer;
        if (self->tag == TYPE_VAR) {
            free(self->type_var->name);
            free(self->type_var);
        } else if ((self->tag == TYPE_TERM)) {
            free(self->type_term->name);
            for (size_t i = 0; i < self->type_term->arity; i++) {
                type_destroy(&self->type_term->arg_types[i]);
            }

            free(self->type_term->arg_types);
        }

        free(self);
        *self_pointer = NULL;
    }
}
