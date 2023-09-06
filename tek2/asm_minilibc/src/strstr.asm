[BITS 64]
	global	strstr
	section	.text
strstr:
	mov	r8, rsi
	xor	r9, r9
hay:
	cmp	byte [rsi], 0
	je	found
	mov	al, [rdi]
	cmp	al, 0
	je 	notfound
	cmp	byte [rsi], al
	je	occu
reset:
	cmp	rsi, r8
	mov	rsi, r8
	mov	r9, 0
	jne 	hay
	loop	next
occu:
	inc	rsi
	inc	r9
next:
	inc	rdi
	loop	hay

notfound:
	mov	rax, 0
	ret
found:
	sub	rdi, r9
	mov	rax, rdi
	ret
