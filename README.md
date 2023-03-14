example generating basic blocks and controll flow graph command: 
"gcc -fdump-tree-cfg=example_c_code.cfg example_c_code.c -o example_c_code"

example generating RISCV 32-bit code from C code:
"sudo riscv32-unknown-elf-gcc example_c_code.c -o example_c_code_risc"
note: must install a pure RV32I toolchain, see instructions at: https://github.com/YosysHQ/picorv32#building-a-pure-rv32i-toolchain.
	  Once done installing the toolchain make sure to run the command "sudo visudo" and add "/opt/riscv32i/bin" to end of the secure path

example generating MIPS machine code from C code using CLANG:
"clang -O3 -S -target mips -mcpu=mips32 example_c_code.c"

example generating MIPS machine code file from C code, this produces an object file with debugging info:
"mipsel-linux-gnu-gcc -g -c example_c_code.c"

example generating MIPS machine code file from C code, this can view the disassembly of the object file from above:
"mipsel-linux-gnu-objdump -d -S example_c_code.o"
