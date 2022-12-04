PROJECT := example
SRC_DIR := .
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS := -lwiringPi
CPPFLAGS := -g
CXXFLAGS := -Wall
 
$(PROJECT): $(OBJ_FILES)
	g++ -o $@ $^ $(LDFLAGS)
 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<
 
clean:
	rm obj/*.o $(PROJECT)
