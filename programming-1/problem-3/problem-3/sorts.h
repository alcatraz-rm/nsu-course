#pragma once
#include<stdlib.h>

void *bubble_sort(void *base, size_t num, size_t size, int(*compare)(void*, void*));

void *make_heap(void *base, size_t num, size_t size, int(*compare)(void*, void*));
void *fix_heap(void *base, size_t num, size_t size, int(*compare)(void*, void*));
void *heap_sort(void *base, size_t num, size_t size, int(*compare)(void*, void*));