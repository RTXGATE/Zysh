section .text
global prt_str

prt_str:
	PUSH RBP
	MOV RBP, RSP
	PUSH RDI
	PUSH RBX

	MOV RDI, [RBP-8]
	MOV RCX, -1
	XOR AL, AL
	CLD
	REPNE SCASB 
	
	MOV RAX , -2
	SUB RAX , RCX

	MOV RBX, RAX
	TEST RBX, RBX
	JZ .done
	
	MOV RAX , 1
	MOV RDI , 1
	MOV RSI , [RBP-8]
	MOV RDX , RBX
	SYSCALL

	TEST RAX , RAX
	JS .error
	
	JMP .done

.error:
	MOV RAX , -1
	JMP .done

.done:
	POP RBX
	POP RDI
	POP RBP
	RET
