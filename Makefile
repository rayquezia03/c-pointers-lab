# Compilador C a ser usado
CC = gcc

# Flags de compilação:
# -Wall: Ativa a maioria dos avisos (warnings)
# -Wextra: Ativa avisos extras
# -g: Gera informações de depuração (para usar com gdb)
# -Iinclude: Adiciona o diretório 'include' à lista de diretórios a serem pesquisados por arquivos de cabeçalho
# -std=c11: Especifica o padrão da linguagem C
CFLAGS = -Wall -Wextra -g -Iinclude -std=c11

# Diretório dos arquivos de código-fonte
SRC_DIR = src

# Diretório dos arquivos de objeto (compilados)
OBJ_DIR = obj

# Nome do executável final
TARGET = pointers_demo

# Lista todos os arquivos de código-fonte (.c)
# A função wildcard busca todos os arquivos que correspondem ao padrão
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Gera a lista de arquivos de objeto (.o) a partir da lista de fontes (.c)
# A função patsubst substitui a extensão .c por .o e o diretório src por obj
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# --- Regras do Makefile ---

# A regra 'all' é a regra padrão, que será executada se você apenas digitar 'make'
all: $(TARGET)

# Regra para linkar os arquivos de objeto e criar o executável final
# O executável depende de todos os arquivos de objeto
$(TARGET): $(OBJS)
	@echo "Linkando para criar o executável..."
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	@echo "Executável '$(TARGET)' criado com sucesso!"
	@echo "Para executar, use: ./$(TARGET)"

# Regra para compilar os arquivos de código-fonte (.c) em arquivos de objeto (.o)
# Esta é uma regra de padrão que diz como transformar um .c em um .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) # Cria o diretório de objetos se ele não existir
	@echo "Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Regra 'clean' para limpar os arquivos gerados (executável e objetos)
clean:
	@echo "Limpando arquivos gerados..."
	rm -f $(TARGET) $(OBJ_DIR)/*.o
	@rmdir $(OBJ_DIR) 2>/dev/null || true

# Phony targets são regras que não representam arquivos reais
.PHONY: all clean
