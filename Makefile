include Makefile.config

all:
	make -C kernel
	mv kernel/main.bin main.bin
	mv kernel/sos.img sos.img
	mv kernel/main.elf main.elf

clean:
	$(RM) main.bin sos.img main.elf
	make -C bootloader clean
	make -C kernel clean

run: clean all
	qemu-system-i386 sos.img

debug: clean all
	qemu-system-i386 sos.img -s -S