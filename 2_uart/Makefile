#######################################################################
# File Name: Makefile
# 作者:YJK 
# mail: 745506980@qq.comc
# Created Time: 2020年09月17日 星期四 14时23分10秒
#########################################################################
#    $^ 当前规则中的所有依赖
#    $< 当前规则中的第一个依赖
#    $@ 当前规则中触发命令生成的目标
#    @ 不把执行的信息打印到显示屏上
#工程Makefile  



#define var 定义变量 
#.c ---- .o ------ build(elf文件)------build.bin 
TARGET := uart.bin
BUILD  := uart
ENV_ 	?= SD#?=如果不指定 则按默认方式  
COBJS	+= main.o#+=    累加 
COBJS	+= uart.o led.o
COBJS	+= start.o 
CROSS_COMPILE := arm-unknown-linux-gnueabi-
#工具集 
CC	:= $(CROSS_COMPILE)gcc
LD	:= $(CROSS_COMPILE)ld#链接器
OBJCOPY	:= $(CROSS_COMPILE)objcopy#文件格式的转换工具  
SDTOOLS := ./mk4412 
#编译选项 

CFLAGS 	+= -Wall  #编译时的选项 
#CFLAGS	+= -I/usr/local/arm/opt/FriendlyARM/toolschain/4.4.3/include/     #寻找include 头文件的选项  -I/include路径 

#查看启动方式  
LDFLAGS += -Tmap.lds
#LDFLAGS += $(call lmZ-option, --no-dynamic-linker)
ifeq ($(ENV_),SD)
LDFLAGS += -Ttext=0x02021400
else 
LDFLAGS += -Ttext=0x20000000
endif 

#链接脚本 
#1、概念   告诉链接器如何工作的一个文本文档  
#1.o 2.o 3.o ---->build  
#2 、要素
 	# 1、哪一个.o放到代码段的起始位置
	#连接器没有指定的方式   需要使用连接脚本

	# 2、所有的.o放到哪个基地址上 
	#方式  ld -Ttext=xxxx   简单链接指定了代码段的基地址 代码段 数据段等是连续的
	#代码段、数据段不连续的方式   使用 .lds文件

#  	

#Way  方法  

all:$(TARGET)
ifeq ($(ENV_), RAM)
$(TARGET):$(BUILD)
	$(OBJCOPY) -O binary $^ $@
else 
$(TARGET):$(BUILD)
	$(OBJCOPY) -O binary $^ $@
#生成一个临时文件  因为以SD卡启动需要在头部增加一个四字节的检测位  i
	$(SDTOOLS) $@ 
endif 
$(BUILD):$(COBJS)
	$(LD) $(LDFLAGS) $^ -o $@ 

%.o:%.c   #任意的.c 想生成任意的.o  使用的是下面的规则   其中.o 文件名是相应的.c文件名 
	$(CC) -c $< -o $@ $(CFLAGS)
%.o:%.S
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm $(BUILD) *.o $(TARGET)

flash:
	dd if=/dev/zero of=/dev/sdb bs=512 seek=1 iflag=dsync oflag=dsync count=2048
#	dd if=./E4412_N.bl1.SCP2G.bin of=/dev/sdb bs=512 seek=1 iflag=dsync oflag=dsync
	dd if=./$(TARGET) of=/dev/sdb bs=512 seek=1 iflag=dsync oflag=dsync



install:
