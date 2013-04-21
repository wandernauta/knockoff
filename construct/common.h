#pragma once
#include <stdio.h>

typedef char* str;

static inline void e_print_int(int val) { printf("%d", val); }
static inline void e_print_float(float val) { printf("%f", val); }
static inline void e_print_str(str val) { printf("%s", val); }
