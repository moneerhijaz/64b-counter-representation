CXX := clang++
CXXFLAGS := -Wall -Wextra -pedantic -std=c++17
TARGET := main
SRC := main.cc

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) a.out
