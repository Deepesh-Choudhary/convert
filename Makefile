OBJECTS = conversions.o mapping.o split.o conversionsCore.o test.o ArgParser.o \
          ArgParseException.o convert.o
CC = g++

convert: $(OBJECTS)
	$(CC) -o convert $(OBJECTS)

conversions.o: conversions.cpp conversions.h conversionsCore.h split.h
conversionsCore.o: conversionsCore.cpp mapping.h
mapping.o: mapping.cpp mapping.h
split.o: split.cpp split.h
test.o: test.cpp *.h
ArgParser.o: ArgParser.cpp ArgParser.h split.h
ArgParseException.o: ArgParseException.h
convert.o: convert.cpp

.PHONY: clean
clean:
	rm -rf $(OBJECTS) convert

.PHONY: compile
compile: $(OBJECTS)

.PHONY: run
run: convert
	./convert

.PHONY: test
test: test.o
	$(CC) -o convert $(OBJECTS)

.PHONY: binary
binary: convert
	rm -rf $(OBJECTS)