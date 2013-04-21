#include "construct/slist.h"

typedef struct {
    char* name;
    char* version;
} pkg;

void e_print_pkg(pkg val) {
    printf("%s %s", val.name, val.version);
}

typedef elist(int) intlist;
typedef elist(pkg) pkglist;
typedef elist(str) strlist;

int main() {
    intlist one = el_init(int)();
    pkglist two = el_init(pkg)();
    strlist six = el_init(str)();

    pkg foo = {.name = "Foo", .version = "0.1"};
    pkg bar = {.name = "Bar", .version = "1.2"};

    el_push(int)(one, 1);
    el_push(int)(one, 2);
    el_push(int)(one, 3);
    el_push(int)(one, 4);
    el_push(int)(one, 5);

    el_push(pkg)(two, foo);
    el_push(pkg)(two, bar);

    el_push(str)(six, "Spam");

    printf("Integers:\t");
    el_println(int)(one);

    printf("Structures:\t");
    el_println(pkg)(two);

    printf("Strings:\t");
    el_println(str)(six);

    printf("---\n");
    printf("int list: Get of fifth element: %d\n", el_get(int)(one, 4));

    el_free(int)(one);
    el_free(pkg)(two);
    el_free(str)(six);

    return 0;
}
