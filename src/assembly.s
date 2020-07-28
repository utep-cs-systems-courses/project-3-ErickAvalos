	.arch msp430g2553

	.data
states:	.byte 0

	.text
switch:	.word case0
	.word case1

	.global toggle_red
toggle_red:
	cmp.b #2, &states
	jc out
	mov.b &states, r12
	add r12, r12
	mov switch(r12), r0
case0:	mov.b #1, &red_on
	mov.b #1, &green_on
	mov.b #1, &states
	jmp out
case1:	mov.b #0, &red_on
	mov.b #0, &green_on
	mov.b #0, &states
out:	mov #1, r12
	pop r0
