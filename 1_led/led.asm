
led:     file format elf32-littlearm


Disassembly of section .text:

00000000 <_start>:
   0:	eb000004 	bl	18 <main>
   4:	00001141 	.word	0x00001141
   8:	61656100 	.word	0x61656100
   c:	01006962 	.word	0x01006962
  10:	00000007 	.word	0x00000007
  14:	00000108 	.word	0x00000108

00000018 <main>:
  18:	e92d4800 	push	{fp, lr}
  1c:	e28db004 	add	fp, sp, #4
  20:	e24dd008 	sub	sp, sp, #8
  24:	e50b0008 	str	r0, [fp, #-8]
  28:	e50b100c 	str	r1, [fp, #-12]
  2c:	eb000013 	bl	80 <led>
  30:	e3a03000 	mov	r3, #0
  34:	e1a00003 	mov	r0, r3
  38:	e24bd004 	sub	sp, fp, #4
  3c:	e8bd4800 	pop	{fp, lr}
  40:	e12fff1e 	bx	lr

00000044 <desplay>:
  44:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
  48:	e28db000 	add	fp, sp, #0
  4c:	e24dd00c 	sub	sp, sp, #12
  50:	e59f3024 	ldr	r3, [pc, #36]	; 7c <desplay+0x38>
  54:	e50b3008 	str	r3, [fp, #-8]
  58:	e1a00000 	nop			; (mov r0, r0)
  5c:	e51b3008 	ldr	r3, [fp, #-8]
  60:	e2432001 	sub	r2, r3, #1
  64:	e50b2008 	str	r2, [fp, #-8]
  68:	e3530000 	cmp	r3, #0
  6c:	1afffffa 	bne	5c <desplay+0x18>
  70:	e24bd000 	sub	sp, fp, #0
  74:	e49db004 	pop	{fp}		; (ldr fp, [sp], #4)
  78:	e12fff1e 	bx	lr
  7c:	0000ffff 	.word	0x0000ffff

00000080 <led>:
  80:	e92d4800 	push	{fp, lr}
  84:	e28db004 	add	fp, sp, #4
  88:	e59f304c 	ldr	r3, [pc, #76]	; dc <led+0x5c>
  8c:	e3a02001 	mov	r2, #1
  90:	e5832000 	str	r2, [r3]
  94:	e59f3044 	ldr	r3, [pc, #68]	; e0 <led+0x60>
  98:	e3a02010 	mov	r2, #16
  9c:	e5832000 	str	r2, [r3]
  a0:	e59f303c 	ldr	r3, [pc, #60]	; e4 <led+0x64>
  a4:	e3a02001 	mov	r2, #1
  a8:	e5832000 	str	r2, [r3]
  ac:	e59f3034 	ldr	r3, [pc, #52]	; e8 <led+0x68>
  b0:	e3a02002 	mov	r2, #2
  b4:	e5832000 	str	r2, [r3]
  b8:	ebffffe1 	bl	44 <desplay>
  bc:	e59f3020 	ldr	r3, [pc, #32]	; e4 <led+0x64>
  c0:	e3a02000 	mov	r2, #0
  c4:	e5832000 	str	r2, [r3]
  c8:	e59f3018 	ldr	r3, [pc, #24]	; e8 <led+0x68>
  cc:	e3a02000 	mov	r2, #0
  d0:	e5832000 	str	r2, [r3]
  d4:	ebffffda 	bl	44 <desplay>
  d8:	eafffff0 	b	a0 <led+0x20>
  dc:	11000100 	.word	0x11000100
  e0:	11000060 	.word	0x11000060
  e4:	11000104 	.word	0x11000104
  e8:	11000064 	.word	0x11000064
