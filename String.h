/*
  https://github.com/benja2998/String.h - free library for real strings in C
  Version 1.0.1

  License:

  Zero-Clause BSD
  =============

  Permission to use, copy, modify, and/or distribute this software for
  any purpose with or without fee is hereby granted.

  THE SOFTWARE IS PROVIDED “AS IS” AND THE AUTHOR DISCLAIMS ALL
  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES
  OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE
  FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY
  DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
  AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
  OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWAR
*/

#ifndef REALSTRINGS
#define REALSTRINGS

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *data;
  size_t start;
  size_t end;
} String;

String String__Cat(String first, String second) {
  String dest = {0};

  dest.data = malloc(first.end + second.end + 1);
  strcpy(dest.data, first.data);
  strcat(dest.data, second.data);

  dest.start = 0;
  dest.end = strlen(dest.data);

  return dest;
}

void String__Println(String str) {
  for (size_t i = str.start; i < str.end; i++) {
    putchar(str.data[i]);
  }
  putchar('\n');
}

void String__ErrorPrintln(String str) {
  for (size_t i = str.start; i < str.end; i++) {
    putc(str.data[i], stderr);
  }
  putc('\n', stderr);
}

void String__ErrorPrint(String str) {
  for (size_t i = str.start; i < str.end; i++) {
    putc(str.data[i], stderr);
  }
}

void String__Cut(String *str, size_t begin, size_t end) {
  str->start = begin;
  str->end = end;
}

void String__Init(String *str, char *data) {
  str->data = data;
  str->start = 0;
  str->end = strlen(str->data);
}

void String__Print(String str) {
  for (size_t i = str.start; i < str.end; i++) {
    putchar(str.data[i]);
  }
}

String String__FromCstr(char *cstr) {
  String str = {0};
  String__Init(&str, cstr);
  return str;
}

#endif
