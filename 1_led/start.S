.global _start
.global main
_start:
    // 设置栈起始地址
    ldr sp, =0x02060000

    // 关闭看门狗
    ldr r0, =0x10060000
    mov r1, #0x0
    str r1, [r0]
    
    // 将CPU设置为SVC模式，并且关闭中断
#if 0
    mrs r0, cpsr
    bic r0, r0, #0x1f
    orr r0, r0, #0xd3
    msr cpsr, r0
#endif

	bl		main
	.end
