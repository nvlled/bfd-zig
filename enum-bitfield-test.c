#include <stdio.h>
#include "bfd-wrapper.h"

enum SomeEnum {
    enum_a = 0,
    enum_b,
    enum_c,
    enum_d,
    enum_e,
    enum_f,
};

struct Blah {
    enum SomeEnum flags : 3;
};

int main() {
    struct bfd x;
    x.filename = "";

    struct Blah e;
    e.flags = enum_f;
    printf("eee size: %lu\n", sizeof(enum SomeEnum));
    printf("blah size: %lu\n", sizeof(struct Blah));
    printf("huh: %u\n", e.flags);
    return 0;
}