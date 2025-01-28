SHELL=/bin/bash

build/calculadora: $(wildcard *.c)
	@if [ ! -d build ]; then mkdir build; fi
	clang-19 --output=build/calculadora -g *.c