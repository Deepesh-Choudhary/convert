OBJECTS = conversions.o mapping.o split.o

convert: $(OBJECTS)
	g++ -o convert $(OBJECTS)

conversions.o: conversions.cpp mapping.h split.h
	g++ -c conversions.cpp

mapping.o: mapping.cpp mapping.h
	g++ -c mapping.cpp

split.o: split.cpp split.h
	g++ -c split.cpp

.PHONY: clean
clean:
	rm -rf $(OBJECTS) convert