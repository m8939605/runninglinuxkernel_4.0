#ARCH = arm
#CROSS_COMPILE = arm-linux-gnueabi-

BASEINCLUDE ?= /home/buildsystem/work/code/proj_test/runninglinuxkernel_4.0
#BASEINCLUDE ?= /lib/modules/`uname -r`/build

export_symbol_test-objs := mymodule1.o  mymodule2.o

obj-m +=  mymodule1.o
obj-m +=  mymodule2.o
all : 
	$(MAKE) -C $(BASEINCLUDE) M=$(PWD) modules;

clean:
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) clean;
	rm -f *.ko;


