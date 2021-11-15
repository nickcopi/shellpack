ifndef script
	script := script_to_pack.sh
endif
packedscript: binary.h pack.c
	gcc -s -Wall pack.c -o packed
binary.h: $(script) .FORCE
.FORCE:
	cp $(script) temp_script.sh
	xxd -i temp_script.sh binary.h 
	rm temp_script.sh
clean:
	rm binary.h packed
