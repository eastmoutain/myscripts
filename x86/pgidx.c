#include <stdio.h>
#include <stdlib.h>

#define PT_SHIFT 20
#define MASK ((1<<9) - 1)

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage pgidx 0xab123\r\n");
        return 0;
    }

    unsigned long long addr = strtol(argv[1], NULL, 16);
    printf("input addr: 0x%llx\r\n", addr);

    int ptidx, pmdidx, pudidx, pgdidx;

    ptidx = (addr >> 12) & MASK;
    pmdidx = (addr >> 21) & MASK;
    pudidx = (addr >> 30) & MASK;
    pgdidx = (addr >> 39) & MASK;

    printf("addr:              pgdidx     gudidx    pmdidx    ptidx\r\n");
    printf("0x%016llx 0x%03x      0x%03x     0x%03x     0x%03x", addr, pgdidx, pudidx, pmdidx, ptidx);

    return 0;
}

