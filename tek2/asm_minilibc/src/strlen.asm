[BITS 64]
	global	strlen
	section	.text
strlen:
	enter	0, 0
	cmp	rdi, 0
	je	bug
	mov	r8, rdi		; mem address str
loop:
	cmp	byte [rdi], 0	; if char str != 0
	je	end		; end
	inc	rdi		; advance str
	loop	loop		; loop
end:
	sub	rdi, r8		; adresse fin - adresse depart
	mov	rax, rdi	; set return value
	leave
	ret
bug:
	mov	rax, rdi
	leave
	ret
