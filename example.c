/*
  https://github.com/benja2998/String.h - free library for real strings in C

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

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "String.h"

int main(int argc, char **argv) {
  if (argc != 2) {
    String error = String__FromCstr("bad usage");
    String__ErrorPrintln(error);
    return 1;
  }

  // really easy to make a String
  String str = String__FromCstr(argv[1]);

  // example of working with functions that expect cstrs
  printf("%s: %d\n", str.data, 69);

  // Printing
  String__Println(str);

  // you can cut them!
  String__Cut(&str, 1, str.end);
  String__Println(str);

  // concatenation
  String str2 = String__FromCstr(" lol");
  String str3 = String__Cat(str, str2);
  String__Println(str3);

  return 0;
}
