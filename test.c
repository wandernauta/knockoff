#include "knockoff/slist.h"

// A custom type.
typedef struct {
    char* name;
    char* version;
} pkg;

// Print callback for our custom type.
void e_print_pkg(pkg val) {
    printf("%s %s", val.name, val.version);
}

typedef elist(int) intlist;
typedef elist(pkg) pkglist;
typedef elist(str) strlist;

void iterate_slow(intlist l) {
    for (size_t i = 0; i < el_size(l); i++) {
        printf("%d ", el_get(l, i));
    }
}

void iterate_fast(intlist l) {
    el_iter(int) iter = el_begin(l);

    while (iter != NULL) {
        printf("%d ", iter->val);
        iter = iter->next;
    }
}

int main() {
    // Construct three lists
    intlist one = el_init(int);
    pkglist two = el_init(pkg);
    strlist six = el_init(str);

    // Fill them up
    el_push(one, 1);
    el_push(one, 2);
    el_push(one, 3);
    el_push(one, 4);
    el_push(one, 5);

    pkg foo = {.name = "Foo", .version = "0.1"};
    pkg bar = {.name = "Bar", .version = "1.2"};

    el_push(two, foo);
    el_push(two, bar);

    el_push(six, "Spam");

    // Print them
    printf("Integers:\t");   el_println(one);
    printf("Structures:\t"); el_println(two);
    printf("Strings:\t");    el_println(six);

    // Misc functions
    printf("---\n");
    printf("int list: Size: %zd\n", el_size(one));
    printf("int list: Get of element at index 4: %d\n", el_get(one, 4));

    // Iteration
    printf("---\n");
    printf("int list: Iterate elements (slow): ");
    iterate_slow(one); printf("\n");
    printf("int list: Iterate elements (iterator): "); 
    iterate_fast(one); printf("\n");

    // Indexof
    printf("---\n");
    printf("int list: Indexof 3: ");
    printf("%zd", el_indexof(one, 3)); printf("\n");
    printf("pkg list: Indexof bar: ");
    printf("%zd", el_indexof(two, bar)); printf("\n");

    // Remove
    printf("---\n");
    printf("int list: Remove 3: ");
    el_remove(one, 3); el_println(one);

    // Clean up
    el_free(one);
    el_free(two);
    el_free(six);

    return 0;
}
