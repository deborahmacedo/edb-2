# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -O2

# Nome do executável final
TARGET = programa

# Arquivos fonte
SRCS = main.cpp \
       bubblesort.cpp \
       busca_binaria.cpp \
       busca_sequencial.cpp \
       insertionsort.cpp

# Objetos correspondentes
OBJS = $(SRCS:.cpp=.o)

# Regra principal
all: $(TARGET)

# Linka todos os objetos em um único executável e remove os .o
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	rm -f $(OBJS)

# Compilação de cada .cpp para .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar executável e .o (precaução extra)
clean:
	rm -f $(OBJS) $(TARGET)

# Rodar o programa
run: $(TARGET)
	./$(TARGET)
