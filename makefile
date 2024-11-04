# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Source files
SRCS = proj1.cpp variable.cpp

# Header files
HEADERS = variable.h

# Output executable name
TARGET = proj1.x

# Build rules
all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean rule
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean