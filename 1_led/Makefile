######################################################################
# File Name: Makefile
# 作者:YJK 
# mail: 745506980@qq.comc
# Created Time: 2020年09月17日 星期四 14时23分10秒
#########################################################################

#define var 定义变量 
#.c ---- .o ------ build(elf文件)------build.bin 
TARGET := led.bin
BUILD  := led
ENV_ 	?= SD#?=如果不指定 则按默认方式  
COBJS	+= main.o#+=    累加 
COBJS	+= led.o
COBJS	+= start.o
CROSS_COMPILE := arm-unknown-linux-gnueabi-
#工具集 
CC	:= $(CROSS_COMPILE)gcc
LD	:= $(CROSS_COMPILE)ld#链接器
OBJCOPY	:= $(CROSS_COMPILE)objcopy#文件格式的转换工具  
SDTOOLS := ./mk4412 
#编译选项 

CFLAGS 	+= -Wall  #编译时的选项 
#CFLAGS	+= -I/usr/local/arm/opt/FriendlyARM/toolschain/4.4.3/include/  

#查看启动方式  
LDFLAGS += -Tmap.lds
#LDFLAGS += $(call lmZ-option, --no-dynamic-linker)
ifeq ($(ENV_),SD)
LDFLAGS += -Ttext=0x0
else 
LDFLAGS += -Ttext=0x20000000
endif 


#Way  方法  

all:$(TARGET)
ifeq ($(ENV_), RAM)
$(TARGET):$(BUILD)
	$(OBJCOPY) -O binary $^ $@
else 
$(TARGET):$(BUILD)
	$(OBJCOPY) -O binary $^ $@
	$(SDTOOLS) $@ 
endif 
$(BUILD):$(COBJS)
	$(LD) $(LDFLAGS) $^ -o $@ 
ifeq ($(ENV_), RAM) 
%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)
%.o:%.S
	$(CC) -c $< -o $@ $(CFLAGS)
else 
%.o:%.c	
	$(CC) -c $< -o $@ $(CFLAGS) 
%.o:%.S
	$(CC) -c $< -o $@ $(CFLAGS) 
endif 

clean:
	rm $(BUILD) $(COBJS) $(TARGET)  

flash:
	dd if=/dev/zero of=/dev/sdb bs=512 seek=1 iflag=dsync oflag=dsync count=2048
	dd if=./led.bin of=/dev/sdb bs=512 seek=1 iflag=dsync oflag=dsync

install:
