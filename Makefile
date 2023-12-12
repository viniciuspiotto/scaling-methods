# Diretórios principais
SRC_DIR := src
OBJ_DIR = obj
INCLUDE_DIR := include

# Nome do binário
TARGET := scaling_methods

# Compilador e flags do compilador
CC := gcc
CFLAGS := -Wall -Wextra -I$(INCLUDE_DIR)

# Arquivos fonte
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)

# Lista de objetos
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Regra para gerar o binário
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para gerar os arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Regra para limpar objetos e o binário
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Rodar o programa principal
run:
	./$(TARGET)

# Garante que o diretório de objetos exista
$(shell mkdir -p $(OBJ_DIR))

.PHONY: clean
