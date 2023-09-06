[BITS 64]
	global	strchr
	section	.text
strchr:
	enter	0, 0
	cmp	rdi, 0
	je	bug
	mov	r8, rdi
	xor	rax, rax
end_loop:
	cmp	byte [rdi], 0
	je	loop
	inc	rdi
	loop	end_loop
loop:
	dec	rdi
	mov	al, [rdi]
	cmp	eax, esi	; if tmp = char recherche
	je	found		; break found
	cmp	rdi, r8
	je	end
	loop	loop		; loop
end:
	mov	rax, 0
	ret
found:
	mov	rax, rdi
	ret
bug:
	mov	rax, rdi
	leave
	ret
