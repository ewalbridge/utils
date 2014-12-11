#!/bin/bash

OUT=macgen;
gcc                    $OUT.c -o $OUT        -Wall -O3 
i686-w64-mingw32-gcc   $OUT.c -o $OUT-32.exe -Wall -s
x86_64-w64-mingw32-gcc $OUT.c -o $OUT-64.exe -Wall -s

