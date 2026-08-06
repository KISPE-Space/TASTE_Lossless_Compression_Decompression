VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/testdatacompressor.h \
                  src/testdatacompressor.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
