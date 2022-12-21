build_path	:=	build
source_path	:=	.

var :=

coverage: var += -DCMAKE_CXX_FLAGS="-fprofile-arcs -ftest-coverage"
coverage: all test
	geninfo $(shell find $(build_path) -path "*_test.dir*.gcno" -or -path "*_test.dir*.gcda") -o $(build_path)/lcov.info
	genhtml $(build_path)/lcov.info -o $(build_path)/coverage
	open $(build_path)/coverage/index.html
.PHONY: coverage

style: clear
	clang-format -n $(shell find . -name "*.cpp" -or -name "*.cc" -or -name "*.h" -or -name "*.h") --verbose -Werror
.PHONY: style

clear: clean
clean:
	rm -rf $(build_path)
.PHONY: clear clean

%:
	@cmake $(var) -S $(source_path) -B $(build_path) -G "Unix Makefiles"
	@make -C $(build_path) $@ -j 16
.PHONY: %

z:
	g++ -c -Werror -Wextra -Wall -fanalyzer $(shell find . -name "*.cpp" -or -name "*.cc" -or -name "*.h" -or -name "*.h")
