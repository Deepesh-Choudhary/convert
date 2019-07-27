OBJECTS = conversions.o mapping.o split.o conversionsCore.o test.o

convert: $(OBJECTS)
	g++ -o convert $(OBJECTS)

conversions.o: conversions.cpp conversions.h conversionsCore.h split.h
	g++ -c conversions.cpp

conversionsCore.o: conversionsCore.cpp mapping.h
	g++ -c conversionsCore.cpp

mapping.o: mapping.cpp mapping.h
	g++ -c mapping.cpp

split.o: split.cpp split.h
	g++ -c split.cpp

test.o: test.cpp *.h
	g++ -c test.cpp

.PHONY: clean
clean:
	rm -rf $(OBJECTS) convert

.PHONY: compile
compile: $(OBJECTS)

.PHONY: run
run: convert
	./convert