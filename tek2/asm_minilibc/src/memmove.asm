[BITS 64]
	global	memmove
	section	.text
memmove:
	mov	r8, r8
	cmp	rdi, rsi
	jb	inc
	add	rdi, rdx
	dec	rdi
	add	rsi, rdx
	dec	rsi
dec:
	mov	al, [rsi]
	mov	byte [rdi], al
	dec	rdi
	dec	rsi
	dec	rdx
	cmp	rdx, 0
	jne 	dec
	mov	rax, rdi
	ret
inc:
	mov	al, [rsi]
	mov	byte [rdi], al
	inc	rdi
	inc	rsi
	dec	rdx
	cmp	rdx, 0
	jne 	inc
	mov	rax, r8
	ret
