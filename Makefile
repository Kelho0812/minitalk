RED=\033[37;41m
GREEN=\033[37;1;42m
NC=\033[0m # No Color

NAME = $(SERVER) $(CLIENT)

SERVER = server

CLIENT = client

LIBFT = ./include/libft/libft.a

PRINTF = ./include/ft_printf/libftprintf.a

CC = cc

CFLAGS = -Werror -Wall -Wextra -g

RM = rm -rf

SDIR_CLIENT := src_client
ODIR_CLIENT := obj_client
SDIR_SERVER := src_server
ODIR_SERVER := obj_server
# Define color codes

SOURCES_CLIENT := $(wildcard $(SDIR_CLIENT)/*.c)
OBJECTS_CLIENT := $(patsubst $(SDIR_CLIENT)/%.c, $(ODIR_CLIENT)/%.o, $(SOURCES_CLIENT))

SOURCES_SERVER := $(wildcard $(SDIR_SERVER)/*.c)
OBJECTS_SERVER := $(patsubst $(SDIR_SERVER)/%.c, $(ODIR_SERVER)/%.o, $(SOURCES_SERVER))

all : ${NAME}

${SERVER} : ${OBJECTS_SERVER} $(LIBFT) $(PRINTF)
	@${CC} ${CFLAGS} ${OBJECTS_SERVER} -o ${SERVER} $(LIBFT) $(PRINTF)
	@echo "${GREEN}Server created${NC}"

${CLIENT} : ${OBJECTS_CLIENT} $(LIBFT) $(PRINTF)
	@${CC} ${CFLAGS} ${OBJECTS_CLIENT} -o ${CLIENT} $(LIBFT) $(PRINTF)
	@echo "${GREEN}Client created${NC}"

$(ODIR_CLIENT)/%.o: $(SDIR_CLIENT)/%.c | $(ODIR_CLIENT)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "${GREEN}Client Objects created${NC}"

$(ODIR_SERVER)/%.o: $(SDIR_SERVER)/%.c | $(ODIR_SERVER)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "${GREEN}Server Objects created${NC}"

$(ODIR_CLIENT):
	@mkdir -p $@

$(ODIR_SERVER):
	@mkdir -p $@	

$(LIBFT) :
	@cd ./include/libft/ && make bonus -s
	@echo "${GREEN}libft.a created${NC}"

$(PRINTF) :
	@cd ./include/ft_printf/ && make -s
	@echo "${GREEN}prinft.a created${NC}"

clean :
	@${RM} ${OBJECTS_CLIENT}
	@${RM} ${ODIR_CLIENT}
	@echo "${RED}Client Objects & Dir deleted${NC}"
	@${RM} ${OBJECTS_SERVER}
	@${RM} ${ODIR_SERVER}
	@echo "${RED}Server Objects & Dir deleted${NC}"
	@cd ./include/libft/ && make clean -s
	@echo "${RED}libft objects deleted${NC}"
	@cd ./include/ft_printf/ && make clean -s
	@echo "${RED}ft_printf objects deleted${NC}"

fclean : clean
	@${RM} ${SERVER}
	@echo "${RED}Server deleted${NC}"
	@${RM} ${CLIENT}
	@echo "${RED}Client deleted${NC}"
	@cd ./include/libft/ && make fclean -s
	@echo "${RED}libft.a deleted${NC}"
	@cd ./include/ft_printf/ && make fclean -s
	@echo "${RED}ft_printf.a deleted${NC}"

re : fclean all