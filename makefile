CXX = g++
CXXFLAGS = -Wall -Wextra -O3 -std=c++11

SRC_DIR = src
BIN_DIR = bin
GNUPLOT_DIR = gnuplot
DATA_DIR = data

FUENTES = $(wildcard $(SRC_DIR)/*.cpp)

EJECUTABLES = $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%, $(FUENTES))

.PHONY: all clean graficas

all: $(EJECUTABLES)

$(BIN_DIR)/%: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@
	@echo "Compilado: $@"

graficas:
	@echo "Generando gráficas con gnuplot..."
	cd $(GNUPLOT_DIR) && gnuplot umbral.gp

clean:
	@echo "Limpiando binarios..."
	rm -f $(BIN_DIR)/*