CC=gcc

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = src
BIN_DIR = bin

CFLAGS=-W -Wall -ansi -pedantic -g
LDFLAGS=-lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
EXEC=run debug
SRC= $(wildcard $(SRC_DIR)/*.c)
INC= $(wildcard *.h)
OBJ= $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all: $(EXEC)
	 
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

run: $(OBJ) $(INC) $(BIN_DIR)
	@$(CC) -o $(BIN_DIR)/$@ $(OBJ) $(LDFLAGS)

debug: $(OBJ) $(INC) $(BIN_DIR)
	@$(CC) -o $(BIN_DIR)/$@ $(OBJ) $(LDFLAGS) -g

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) $(OBJ_DIR)
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf $(OBJ_DIR)/*.o

mrproper: clean
	@rm -rf $(addprefix $(BIN_DIR)/, $(EXEC))
