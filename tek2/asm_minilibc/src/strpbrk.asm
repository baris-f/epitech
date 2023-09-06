[BITS 64]
	global	strpbrk
	section	.text
strpbrk:
	mov	r8, rsi
loop:
	mov	al, byte [rdi]
	cmp	al, 0
	je	end
list:
	cmp	byte [rsi], 0
	je	next
	cmp	al, byte [rsi]
	je	found
	inc	rsi
	loop	list
next:
	mov	rsi, r8
	inc	rdi
	loop	loop
end:
	mov	rax, 0
	ret
found:
	mov	rax, rdi
	ret
