TARGET = test
REPORT = gcov_report
CLEAN = clean
TESTS = TESTS
LIBRARY = s21_math.a
CC = gcc
UNAME := $(shell uname)
FLAGS = -Wall -Werror -Wextra #-fsanitize=address -g 
TEST_FLAGS =  -lm
GCOV_FLAGS = -fprofile-arcs -ftest-coverage -lgcov 
SRC = $(wildcard *.c)
SRC_TEST = $(wildcard ./TESTS/*.c)
OBJ =  $(SRC:%.c=%.o)

all : $(CLEAN) $(LIBRARY) $(TARGET) $(REPORT) 

ifeq ($(UNAME), Linux)
 TEST_FLAGS += -lcheck -lsubunit -lrt -lpthread
else
 TEST_FLAGS += -lcheck
endif


$(TARGET) : $(LIBRARY) $(SRC_TEST)
	$(CC) $(FLAGS)  $(SRC_TEST) -L. $(LIBRARY) $(TEST_FLAGS)  -o test 
	./test
$(REPORT) : $(SRC) | build_file
	$(CC) $(FLAGS) $(SRC) $(SRC_TEST) $(TEST_FLAGS) $(GCOV_FLAGS) -o Build/$(REPORT)
	Build/./$(REPORT)
	lcov -o $(REPORT).info -c -d .
	genhtml $(REPORT).info -o html_report
	open html_report/index.html

$(LIBRARY): $(SRC)
	$(CC) $(FLAGS) -c $(SRC) $(TEST_FLAGS)
	ar rc $(LIBRARY) *.o
	ranlib $(LIBRARY)

%.o : %.c
	$(CC) -c $< -o $@

f : $(SRC)
	$(CC)  $(SRC) $(TEST_FLAGS)  -o test 
	./test
build_file: 
	mkdir Build
$(CLEAN) :
	rm -rf Build $(TARGET) ./TESTS/*.o *.o *.a ./html_report/ gcov_report *.gcno *.gcda *.info *.out