section .text
global read_string

read_string:
	PUSH RBP
	MOV RBP , RSP
	PUSH RBX

	TEST RDI , RDI
	JZ .error
	CMP RSI , 2
	JB .error
	MOV RBX , RDI
	MOV RCX , RSI
	DEC RCX

	MOV RAX , 0
	MOV RDI , 0
	MOV RSI , RBX
	MOV RDX , RCX
	SYSCALL

	TEST RAX , RAX
	JS .error
	JZ .eof

	MOV BYTE [RBX+RAX] , 0
	MOV RCX , RAX
	DEC RCX
	JS .done
	CMP BYTE [RBX+RCX] , 10
	JNE .done
	
	MOV BYTE [RBX+RCX] , 0
	DEC RAX

.done:
	POP RBX
	POP RBP
	RET

.eof:
	MOV BYTE [RBX] , 0
	XOR RAX , RAX
	POP RBX
	POP RBP
	RET

.error:
	MOV RAX , -1
	POP RBX
	POP RBP
	RET
