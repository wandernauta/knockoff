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
    intlist one = el_init(int);
    pkglist two = el_init(pkg);
    strlist six = el_init(str);

    pkg foo = {.name = "Foo", .version = "0.1"};
    pkg bar = {.name = "Bar", .version = "1.2"};

    el_push(one, 1);
    el_push(one, 2);
    el_push(one, 3);
    el_push(one, 4);
    el_push(one, 5);

    el_push(two, foo);
    el_push(two, bar);

    el_push(six, "Spam");

    printf("Integers:\t");
    el_println(one);

    printf("Structures:\t");
    el_println(two);

    printf("Strings:\t");
    el_println(six);

    printf("---\n");
    printf("int list: Size: %zd\n", el_size(one));
    printf("int list: Get of fifth element: %d\n", el_get(one, 4));

    el_free(one);
    el_free(two);
    el_free(six);

    return 0;
}
