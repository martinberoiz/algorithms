OBJ_DIR := obj
LIBS = -lm

ALG_DIR = Algorithms
UF_DIR = UnionFind
PRC_DIR = Percolation

PRC_OBJS := obj/UnionFind/QuickFind.o obj/UnionFind/QuickUnion.o obj/UnionFind/WeightedQuickUnion.o
UFT_OBJS := obj/UnionFind/QuickFind.o obj/UnionFind/QuickUnion.o obj/UnionFind/WeightedQuickUnion.o
ALG_DEPS := $(wildcard $(ALG_DIR)/*.cpp) $(wildcard $(ALG_DIR)/*.h)

all: algo percolate uftest

$(OBJ_DIR)/%.o: %.cpp %.h
	mkdir -p $(@D)
	$(CXX) -c $< -o $@ $(CFLAGS)

algo: $(ALG_DEPS)
	$(CXX) $(ALG_DIR)/main.cpp -o algo

percolate: $(PRC_OBJS)
	$(CXX) $(PRC_OBJS) $(PRC_DIR)/percolation.cpp -I$(UF_DIR) -o percolate

uftest: $(UFT_OBJS)
	$(CXX) $(UFT_OBJS) $(UF_DIR)/uftest.cpp -I$(UF_DIR) -o uftest

.PHONY: clean all

clean:
	-rm -f algo percolate uftest
	-rm -rf $(OBJ_DIR)

