include ../../Makefile.config

LDFLAGS = --Ttext 0x0 		\
 		  --oformat binary 	\
 		  -m elf_i386

programs = shell IdleProcess prog1 error input

header_files = $(programs:=.bin.h)
bin_files = $(programs:=.bin)

all: $(header_files)

.PHONY: clean
clean:
	$(RM) $(header_files) $(bin_files)

%.bin.h: %.bin
	xxd -i $< $@

%.bin: %.o systemFunc.o ../stdlib/stdlib.o
	$(LD) $(LDFLAGS) $^ -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@
