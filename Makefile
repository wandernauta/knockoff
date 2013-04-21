test: test.c construct/common.h construct/dlist.h construct/hmap.h construct/hset.h construct/slist.h
	$(CC) $< -o $@ -Wall -Wextra -pedantic -std=c99 -g -Os -ftrapv
