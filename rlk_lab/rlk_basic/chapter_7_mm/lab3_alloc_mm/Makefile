
# modify right kernel PATH for your system
BASEINCLUDE ?= /home/buildsystem/work/code/proj_test/runninglinuxkernel_4.0
#BASEINCLUDE ?= /lib/modules/`uname -r`/build

allocmm-objs := alloc_mm.o

obj-m	:=   allocmm.o
all :
	$(MAKE) -C $(BASEINCLUDE) M=$(PWD) modules;

clean:
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) clean;
	rm -f *.ko;


