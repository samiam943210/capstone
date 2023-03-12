example generating basic blocks and controll flow graph command: 
"gcc -fdump-tree-cfg=example_c_code.cfg example_c_code.c -o example_c_code"

example generating MIPS machine code file from C code, this produces an object file with debugging info:
"mipsel-linux-gnu-gcc -g -c example_c_code.c"

example generating MIPS machine code file from C code, this can view the disassembly of the object file from above:
"mipsel-linux-gnu-objdump -d -S example_c_code.o"
