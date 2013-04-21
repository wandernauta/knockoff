test: test.c knockoff/common.h knockoff/dlist.h knockoff/hmap.h knockoff/hset.h knockoff/slist.h
	$(CC) $< -o $@ -Wall -Wextra -pedantic -std=c99 -g -Os -ftrapv
