CC      :=  gcc
CFLAGS  :=  -Wall -Wextra -Werror
LDFLAGS :=

UNITY	:= unity.c

SRCS_1    := software_under_test_add.c Unity_Tests_add.c
N1		  := addition_tests.out

SRCS_2	  := software_under_test_sort_and_states.c Unity_Tests_sort_and_states.c
N2		  := sorting_and_states.out

SRCS_3	  := software_under_test_laufzeitfehler.c Unity_Tests_Laufzeitfehler.c
N3		  := laufzeitfehler.out

NAME := Unity_Tests

$(NAME):
	$(CC) $(UNITY) $(SRCS_1) -o $(N1)
	$(CC) $(UNITY) $(SRCS_2) -o $(N2)
	$(CC) $(UNITY) $(SRCS_3) -o $(N3)
	@echo "Erstellte executables: $(N1) $(N2) $(N3)"
	@echo "---------------TEST 1 -------------------\n"
	./$(N1)
	@echo "---------------TEST END-------------------\n\n"

	@echo "---------------TEST 2 -------------------\n"
	./$(N2)
	@echo "---------------TEST END-------------------\n\n"

	@echo "---------------TEST 3 -------------------\n"
	./$(N3)
	@echo "---------------TEST END-------------------\n\n"


clean:
	@rm -f $(N1) $(N2) $(N3)

fclean: clean


re: fclean all
