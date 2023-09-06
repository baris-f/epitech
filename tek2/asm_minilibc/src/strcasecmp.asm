[BITS 64]
	SECTION	.text
	GLOBAL	strcasecmp

strcasecmp:
	xor	r10, r10
	xor	r11, r11
	cmp	byte [rdi], 0
	je	ret
	cmp	byte [rsi], 0
	je	ret
	mov	r10b, byte [rdi]
	mov	r11b, byte [rsi]
	cmp	r10b, 97
	jae	pass10
	add	r10b, 32
pass10:
	cmp	r11b, 97
	jae	pass11
	add	r11b, 32
pass11:
	cmp	r10b, r11b
	jne	ret
	inc	rdi
	inc	rsi
	loop	strcasecmp
ret:
	sub	r10, r11
	mov	rax, r10
	ret
