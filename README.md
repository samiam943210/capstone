example generating basic blocks and controll flow graph command: 
"gcc -fdump-tree-cfg=example_c_code.cfg example_c_code.c -o example_c_code"

example generating RISCV 32-bit code from C code:
"sudo riscv32-unknown-elf-gcc -march=rv32ii -mabi=ilp32 example_c_code.c -o example_c_code_risc.s"
note: must install a pure RV32I toolchain and the RISC-V processor, see instructions at: https://github.com/YosysHQ/picorv32#building-a-pure-rv32i-toolchain.
	  Once done installing the toolchain make sure to run the command "sudo visudo" and add "/opt/riscv32i/bin" to end of the secure path

example generating MIPS machine code from C code using CLANG:
"clang -O3 -S -target mips -mcpu=mips32 example_c_code.c"

example generating MIPS machine code file from C code, this produces an object file with debugging info:
"mipsel-linux-gnu-gcc -g -c example_c_code.c"

example generating MIPS machine code file from C code, this can view the disassembly of the object file from above:
"mipsel-linux-gnu-objdump -d -S example_c_code.o"

to build picorv32 in vivado:
	1. open vivado and the tcl terminal (Window > Tcl console)
	2. cd into "/capstone//xilinx-risc-v/vivado/generic/"
		for me: "c:/Users/Sam/AppData/Local/Packages/CanonicalGroupLimited.UbuntuonWindows_79rhkp1fndgsc/LocalState/rootfs/home/samiam943/capstone//xilinx-risc-v/vivado		/generic/"\
	3. "source build_project.tcl"

to clean picorv32 in vivado:
	1. in linux terminal:
	2. cd into "/capstone//xilinx-risc-v/vivado/generic/"
	3. type "sudo rm -rf RISC-V.cache/ RISC-V.hw/ RISC-V.sim RISC-V.ip_user_files/ RISC-V.xpr RISC-V.runs/"
	
