include ../Makefile.config

stdlib_srcs := $(shell find stdlib -name '*.cc')
src_files := $(shell find src -name '*.cc')
src_files := $(filter-out src/main.cc,$(src_files))
all_src_files = src/main.cc $(stdlib_srcs) $(pmode_srcs) $(kernel_srcs) $(src_files)
obj_files = $(all_src_files:.cc=.o)

all: user_programs $(obj_files) src/interrupts.o
	$(LD) $(LDFLAGS) $(obj_files) src/interrupts.o -o main.elf
	$(OBJCOPY) -O binary main.elf main.bin
	cd ../bootloader && make
	cat ../bootloader/boot.bin main.bin /dev/zero | head -c 1474560 > sos.img

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.PHONY: user_programs
user_programs:
	make -C user-programs

src/interrupts.o: src/interrupts.asm
	nasm -f elf $^

.PHONY: clean
clean:
	make -C user-programs clean
	find . -name '*.o' | xargs $(RM)
	$(RM) main.bin sos.img main.elf