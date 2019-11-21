boot.bin: boot.asm
	nasm -f bin $^ -o $@

.PHONY: clean
clean:
	$(RM) boot.bin