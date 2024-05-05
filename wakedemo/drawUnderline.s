
	.arch msp430g2553
	.p2align 1,0
	
	.text
	.align 2
	.global drawUnderlineAssembly
	.extern drawPixel

drawUnderlineAssembly:
	sub #6,r1
	mov.b r12, 0(r1)
	mov.b r13, 1(r1)
	mov.b r14, 2(r1)	
	mov.b r15, 3(r1)
	mov.b #0, 4(r1)
Top:
	cmp.b 0(r1), 4(r1)
	jc End
	add.b #1, 0(r1)
	mov.b 0(r1), r12
	mov.b 1(r1), r13
	mov r15, r14
	call #drawPixel
	add.b #1, 4(r1)
	jmp Top
End:
	add #6, r1
	pop r0
