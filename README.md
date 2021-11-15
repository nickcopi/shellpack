# Shell Script Packer 
Packs a shell script to an ELF using gcc, xxd, and make.


## Usage 
Make sure make, gcc, and a version of xxd that supports the -i flag are installed on the system. (Busybox xxd seems to unsurprisingly lack this.)
Run `make script=targetscript.sh`
You should now have an ELF binary wrapped version of your script built at `packed`.


## How it works 
1. Make is run and uses the default script if not passed a script variable.
2. Make triggers the build of binary.h which is build buy passing the target script to xxd -i to generate a C style header file of the bytes.
3. Make triggers the build of the packed binary which includes the generated header file.
4. A user executes the packed binary.
5. The binary runs, uses memfd_create to create a file descriptor of a memory only file containing the bytes of the shell script.
6. The binary calls fexecve to execute from the memory only file descriptor, invoking the shell script.
