# Linux-Kernel-Loadable-Module-LKM-Rootkit/module/Makefile
obj-m := rootkit_lkm_mod.o
rootkit_lkm_mod-objs := rootkit_lkm.o cr0_rw.o

KDIR := /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean