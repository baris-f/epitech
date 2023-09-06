[BITS 64]
	global	rindex
	section	.text
rindex:
	enter	0, 0
	cmp	rdi, 0
	je	found
	mov	r8, rdi
	xor	rax, rax
end_loop:
	cmp	byte [rdi], 0
	je	loop
	inc	rdi
	loop	end_loop
loop:
	dec	rdi		; reverse advance str
	mov	al, [rdi]
	cmp	eax, esi	; if tmp = char recherche
	je	found		; break found
	cmp	rdi, r8
	je	end
	loop	loop		; loop
end:
	mov	rax, 0
	leave
	ret
found:
	mov	rax, rdi	; ret address found
	leave
	ret
bug:
	mov	rax, 0
	leave
	ret
