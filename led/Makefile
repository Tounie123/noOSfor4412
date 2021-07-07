led.bin: start.o led.o
	arm-unknown-linux-gnueabi-ld -Ttext 0x0 -o led.elf $^
	arm-unknown-linux-gnueabi-objcopy -O binary led.elf led.bin
	arm-unknown-linux-gnueabi-objdump -D led.elf > led_elf.dis


%.o : %.S
	arm-unknown-linux-gnueabi-gcc -o $@ $< -c -nostdlib

%.o : %.c
	arm-unknown-linux-gnueabi-gcc -o $@ $< -c -nostdlib

.PHONY:clean flash
clean:
	rm *.o *.elf *.bin *.dis  -f

flash:
	./mk4412 led.bin
	@if [ -b /dev/sdb ]; then \
	sudo dd if=/dev/zero of=/dev/sdb bs=512 seek=1 iflag=dsync oflag=dsync count=2048; \
	sudo dd if=./led.bin of=/dev/sdb bs=512 seek=1 iflag=dsync oflag=dsync; \
	fi
