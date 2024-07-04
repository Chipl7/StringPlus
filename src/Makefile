CC=gcc
FLAGS=-Wall -Wextra -Werror -std=c11
CHEAK=leaks -atExit --
TEST_FLAGS=-lcheck -lm -lpthread
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
FLAG_TEST=-lcheck 


ifeq ($(shell uname), Linux)
 FLAG_TEST +=-lsubunit -lm
endif
REPORT_DIR = ./report

all: test gcov_report

s21_string.a:
	$(CC) $(FLAGS) -c core/*c core/bonus/*c
	ar -rcs s21_string.a *.o
	ranlib s21_string.a
	@mkdir object
	@mv *.o object
	@mv *.a object

test: s21_string.a
	$(CC) $(FLAGS) main.c core/*.c core/bonus/*.c tests/*.c tests/tests_s21_sscanf/*.c tests/tests_s21_sprintf/*.c -o test.out $(GCOV_FLAGS) $(FLAG_TEST)
	./test.out
	@mkdir "report file"
	@mv *.*.gcno "report file"
	@mv *.*.gcda "report file"

gcov_report:
	lcov -t test --output-file report.info --capture --rc lcov_branch_coverage=1  -q --directory ./
	genhtml -o $(REPORT_DIR) report.info
	@open report/index.html

clean:
	rm -rf object
	rm -rf "report file"
	rm -rf report
	rm -f *.info
	rm -f *.out
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.gch
	rm -f *.a
	rm -f *.o

clang:
	@cp ../linters/.clang-format .
	@clang-format -i *.c
	@clang-format -i *.h
	@clang-format -i core/*.c
	@clang-format -i core/bonus/*c
	@clang-format -i tests/*.c
	@clang-format -i tests/tests_s21_sscanf/*.c
	@clang-format -i tests/tests_s21_sprintf/*.c
	@rm ./.clang-format

clang-test:
	@cp ../linters/.clang-format .
	@clang-format -n *.c
	@clang-format -n *.h
	@clang-format -n core/*.c
	@clang-format -n core/bonus/*c
	@clang-format -n tests/*.c
	@clang-format -n tests/tests_s21_sscanf/*.c
	@clang-format -n tests/tests_s21_sprintf/*.c
	@rm ./.clang-format

leaks:
	$(CHEAK) ./test.out

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./test.out
	@mv *.*.gcda "report file"