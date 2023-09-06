[BITS 64]
	global	memset
	section	.text
memset:
	mov	r8, rdi
loop:
	cmp	rdx, 0
	je	end
	mov	byte [rdi], sil
	inc	rdi
	dec	rdx
	loop	loop
end:
	mov	rax, r8
	ret
