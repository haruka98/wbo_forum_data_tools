CCFLAGS = -std=c++2a
ifneq ($(OS),Windows_NT)
	CCFLAGS += -lstdc++fs
endif
all:
	g++ -o name_search main.cpp $(CCFLAGS)
