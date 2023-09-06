[BITS 64]
	global	strcmp
	section	.text
strcmp:
	enter	0, 0
	cmp	rdi, 0
	je	bug
loop:
	xor	r10, r10
	xor	r11, r11
	mov	r10b, byte [rdi]	; copy char in tmp
	mov	r11b, byte [rsi]	; if char str1 != tmp
	cmp	byte [rdi], 0		; if end str1
	je	end			; break
	cmp	byte [rsi], 0		; if end str2
	je	end			; break
	cmp	r10b, r11b
	jne	end
	inc	rdi			; advance str1
	inc	rsi			; advance str2
	loop	loop			; loop
end:
	sub	r10, r11		; ret = char str1 - char str2
	mov	rax, r10
	leave
	ret
bug:
	mov	rax, rdi
	leave
	ret
