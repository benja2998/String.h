#!/bin/bash
clang -pedantic -Wall -Werror -Wextra -fsanitize=address -O3 example.c -o example -g -fno-omit-frame-pointer
