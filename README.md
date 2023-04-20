example generating basic blocks and controll flow graph command: 
"gcc -fdump-tree-cfg=example_c_code.cfg example_c_code.c -o example_c_code"

example generating RISCV 32-bit code from C code and mapping it to picorv32:
	note: must install a pure RV32I toolchain and the RISC-V processor, see instructions at: https://github.com/YosysHQ/picorv32#building-a-pure-rv32i-toolchain.
	Once done installing the toolchain make sure to run the command "sudo visudo" and add "/opt/riscv32i/bin" to end of the secure path
	note #2: copy /picorv32/firmware/makehex.py into /picorv32 
	1. cd into the main directory of picorv32
	2. take any c code and name it "firmware.c"
	3. sudo riscv32-unknown-elf-gcc -Os -ffreestanding -nostdlib -o firmware.elf firmware.S firmware.c --std=gnu99 -Wl,-Bstatic,-T,firmware.lds,-Map,firmware.map,--strip-debug -lgcc
	4. sudo riscv32-unknown-elf-objcopy -O binary firmware.elf firmware.bin
	5. python3 makehex.py firmware.bin 4096 > firmware.hex
	6. cp firmware.hex firmware/firmware.hex
	7. make test
	now the given c code will run on the picorv32 core and give you the extracted clock cycle count for each basic block

example generating MIPS machine code from C code using CLANG:
"clang -O3 -S -target mips -mcpu=mips32 example_c_code.c"

example generating MIPS machine code file from C code, this produces an object file with debugging info:
"mipsel-linux-gnu-gcc -g -c example_c_code.c"

example generating MIPS machine code file from C code, this can view the disassembly of the object file from above:
"mipsel-linux-gnu-objdump -d -S example_c_code.o"

installing new toolchain
1. rm -rf riscv-gnu-toolchain-rv32i/
2. cd into /opt
3. sudo rm -rf all riscv32 directories
4. cd into the directory where you would like to install the toolchain
5. sudo mkdir /opt/riscv32i
6. sudo chown $USER /opt/riscv32i`
7. git clone https://github.com/riscv/riscv-gnu-toolchain riscv-gnu-toolchain-rv32i
8. cd riscv-gnu-toolchain-rv32i
9. git checkout 411d134
10. git submodule update --init --recursive
11. mkdir build
12. cd build
13. ../configure --with-arch=rv32i --prefix=/opt/riscv32i
14. export PATH="/opt/riscv32i:$PATH"
15. make -j$(nproc) 
