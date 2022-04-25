#!/bin/sh

set -e

ca65 -o cpu.o cpu.asm
ld65 -o cpu.bin -C cpu.ld cpu.o

printf \
'const byte rom0[] PROGMEM = {
%s
};

const byte rom1[] PROGMEM = {
%s
};
'                                         \
  "$(xxd -i -s 0     -l 16384 < cpu.bin)" \
  "$(xxd -i -s 16384 -l 16384 < cpu.bin)" \
  > rom.ino
