OBJECTS = conversions.o mapping.o split.o conversionsCore.o ArgParser.o \
          ArgParseException.o convert.o ArgParserCore.o
CXXFLAGS = -g -Wall -Wextra -Wshadow -pedantic

convert: $(OBJECTS)
	$(CXX) -o convert $(OBJECTS)

conversions.o: conversions.cpp conversions.h conversionsCore.h split.h
conversionsCore.o: conversionsCore.cpp mapping.h
mapping.o: mapping.cpp mapping.h
split.o: split.cpp split.h
ArgParser.o: ArgParser.cpp ArgParser.h split.h
ArgParserCore.o: ArgParserCore.cpp ArgParser.h ArgParseException.h
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
	$(CXX) -o convert $(OBJECTS)

.PHONY: binary
binary: convert
	rm -rf $(OBJECTS)