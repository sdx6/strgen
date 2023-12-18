compiler = clang
options  = 
linker   = -lm
output   = strgen
sources  = main.c

$(output): $(sources)
	$(compiler) $(options) -o $(output) $(sources) $(linker)
.PHONY: clean
clean:
	rm -f $(output) *.o
