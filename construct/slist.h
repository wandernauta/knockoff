#pragma once
#include "common.h"
#include <stdio.h>
#include <stdlib.h>

/* Shortcuts used in the list definition. */
#define el_ptr void*
#define el_s(TYPE, NAME) e_list_ ## TYPE ## _ops. NAME

/* Public shortcuts/API. */
#define el_init(T) e_list_ ## T ## _ops.init();
#define el_free(l) l->ops->free(l)
#define el_push(l, val) l->ops->push(l, val)
#define el_print(l) l->ops->print(l)
#define el_println(l) l->ops->println(l)
#define el_size(l) l->ops->size(l)
#define el_get(l, idx) l->ops->get(l, idx)

#define elist(T) \
    char T ## _dummy_char; \
    struct e_list_ ## T; \
    struct e_list_elem ## T; \
    typedef struct e_list_ ## T el_ ## T; \
    typedef struct e_list_elem_ ## T ele_ ## T; \
    \
    struct e_list_elem_ ## T { \
        T val; \
        ele_ ## T * next; \
    }; \
    \
    struct e_list_ ## T ## _ops_t { \
        el_## T* (*init)(); \
        void (*free)(el_##T* l); \
        void (*push)(el_##T* l, T val); \
        T (*get)(el_##T* l, size_t idx); \
        void (*print)(el_##T* l); \
        void (*println)(el_##T* l); \
        size_t (*size)(el_##T* l); \
    };\
    struct e_list_ ## T { \
        size_t size; \
        struct e_list_elem_ ## T * head; \
        struct e_list_elem_ ## T * tail; \
        struct e_list_ ## T ## _ops_t * ops; \
    }; \
    \
    el_##T* e_list_ ## T ## _init (); \
    void e_list_ ## T ## _free (el_##T* l); \
    void e_list_ ## T ## _push (el_##T* l, T val); \
    void e_list_ ## T ## _print (el_##T* l); \
    void e_list_ ## T ## _println (el_##T* l); \
    size_t e_list_ ## T ## _size (el_##T* l); \
    T e_list_ ## T ## _get (el_##T* l, size_t idx); \
    \
    struct e_list_ ## T ## _ops_t e_list_ ## T ## _ops = { \
        .init = e_list_ ## T ## _init, \
        .free = e_list_ ## T ## _free, \
        .push = e_list_ ## T ## _push, \
        .print = e_list_ ## T ## _print, \
        .println = e_list_ ## T ## _println, \
        .size = e_list_ ## T ## _size, \
        .get = e_list_ ## T ## _get, \
    }; \
    \
    \
    el_##T* e_list_ ## T ## _init () { \
        el_##T * l = calloc(1, sizeof(struct e_list_ ## T)); \
        l->ops = &e_list_ ## T ## _ops; \
        return l; \
    } \
    \
    void e_list_ ## T ## _free (el_##T* l) { \
        ele_ ## T* elem = l->head; \
        \
        while (elem != NULL) { \
            ele_ ## T* next = elem->next;\
            free(elem);\
            elem = next;\
        }\
        \
        free(l); \
    } \
    \
    void e_list_ ## T ## _push(el_##T* l, T val) { \
        ele_ ## T* elem = calloc(1, sizeof(ele_ ## T)); \
        elem->val = val; \
        \
        if (l->size == 0) { \
            l->head = elem; \
            l->tail = elem; \
        } else { \
            l->tail->next = elem; \
            l->tail = elem; \
        } \
        \
        l->size += 1; \
        \
    } \
    T e_list_ ## T ## _get(el_##T* l, size_t idx) { \
        ele_ ## T* elem = l->head; \
        \
        for (size_t i = 0; i < idx; i++) { \
            elem = elem->next; \
        } \
        \
        return elem->val; \
    } \
    \
    void e_list_ ## T ## _print(el_##T* l) { \
        ele_ ## T* elem = l->head; \
        \
        printf("["); \
        while (elem != NULL) { \
            e_print_ ## T (elem->val); \
            elem = elem->next;\
            if (elem != NULL) printf(", "); \
        }\
        printf("]"); \
        \
    } \
    \
    void e_list_ ## T ## _println(el_##T* l) { \
        e_list_ ## T ## _print(l); \
        printf("\n"); \
    } \
    \
    size_t e_list_ ## T ## _size(el_##T* l) { \
        return l->size; \
    } \
    \
    typedef struct e_list_ ## T* \

