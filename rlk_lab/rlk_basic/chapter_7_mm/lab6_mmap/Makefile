
BASEINCLUDE ?= /home/buildsystem/work/code/proj_test/runninglinuxkernel_4.0
#BASEINCLUDE ?= /lib/modules/`uname -r`/build

mydevdemo_mmap-objs := mydev_mmap.o 

obj-m	:=   mydevdemo_mmap.o
all : 
	$(MAKE) -C $(BASEINCLUDE) M=$(PWD) modules;

clean:
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) clean;
	rm -f *.ko;


