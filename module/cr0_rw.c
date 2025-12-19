#include <linux/module.h>
#include <asm/special_insns.h>
#include "cr0_rw.h"

void disable_write_protection(void) {
    unsigned long cr0 = read_cr0();
    clear_bit(16, &cr0);
    write_cr0(cr0);
}

void enable_write_protection(void) {
    unsigned long cr0 = read_cr0();
    set_bit(16, &cr0);
    write_cr0(cr0);
}