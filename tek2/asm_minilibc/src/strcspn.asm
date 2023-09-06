[BITS 64]
	global	strcspn
	section	.text
strcspn:
	xor	rax, rax
	mov	r8, rsi
loop:
	mov	bl, byte [rdi]
	cmp	bl, 0
	je	end
list:
	cmp	byte [rsi], 0
	je	next
	cmp	bl, byte [rsi]
	je	end
	inc	rsi
	loop	list
next:
	inc	rax
	mov	rsi, r8
	inc	rdi
	loop	loop
end:
	ret
