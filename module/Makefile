
# Target object name
obj-m := rootkit_lkm.o

# Kernel build directory path
KDIR := /lib/modules/$(shell uname -r)/build

# Default compilation rule
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

# Cleanup rule
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean