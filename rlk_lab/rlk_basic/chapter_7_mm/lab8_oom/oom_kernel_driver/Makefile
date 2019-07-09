
# modify right kernel PATH for your system
BASEINCLUDE ?= /home/buildsystem/work/code/proj_test/runninglinuxkernel_4.0
#BASEINCLUDE ?= /lib/modules/`uname -r`/build

alloc-oom-objs := alloc_oom.o

obj-m	:=   alloc-oom.o
all :
	$(MAKE) -C $(BASEINCLUDE) M=$(PWD) modules;

clean:
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) clean;
	rm -f *.ko;


