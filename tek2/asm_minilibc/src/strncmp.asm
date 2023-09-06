[BITS 64]
	SECTION	.text
	GLOBAL	strncmp

strncmp:
	xor	r10, r10
	xor	r11, r11
	mov	r10b, byte [rdi]
	mov	r11b, byte [rsi]
	cmp	byte [rdi], 0
	je	ret
	cmp	byte [rsi], 0
	je	ret
	cmp	r10b, r11b
	jne	ret
	dec	dl
	cmp	dl, 0
	je	ret
	inc	rdi
	inc	rsi
	loop	strncmp
ret:
	sub	r10, r11
	mov	rax, r10
	ret
