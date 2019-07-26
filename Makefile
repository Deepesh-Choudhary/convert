OBJECTS = conversions.o mapping.o split.o conversionsCore.o test.o
CC = g++

convert: $(OBJECTS)
	$(CC) -o convert $(OBJECTS)

conversions.o: conversions.cpp conversions.h conversionsCore.h split.h
	$(CC) -c conversions.cpp

conversionsCore.o: conversionsCore.cpp mapping.h
	$(CC) -c conversionsCore.cpp

mapping.o: mapping.cpp mapping.h
	$(CC) -c mapping.cpp

split.o: split.cpp split.h
	$(CC) -c split.cpp

test.o: test.cpp *.h
	$(CC) -c test.cpp

.PHONY: clean
clean:
	rm -rf $(OBJECTS) convert

.PHONY: compile
compile: $(OBJECTS)

.PHONY: run
run: convert
	./convert