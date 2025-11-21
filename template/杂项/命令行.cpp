********** bat **********
@echo off
g++ %1.cpp -std=c++20 -O2 -Wall -o %1 -D_GLIBCXX_DEBUG
.\%1 < in.txt > out.txt
@REM type out.txt
*************************

********** sh *********** chmod +x
#!/bin/bash
g++ -std=c++20 -O2 -Wall "$1.cpp" -o "$1" -D_GLIBCXX_DEBUG
./"$1" < in.txt > out.txt
cat out.txt
*************************

********** sh *********** chmod +x
#!/usr/bin/env bash
set -e
g++ -std=c++17 -O2 -o data data.cpp
g++ -std=c++17 -O2 -o std std.cpp
g++ -std=c++17 -O2 -o my my.cpp
i=1
while true; do
    ./data > data.in
    ./std < data.in > std.out
    ./solve < data.in > my.out

    if ! diff -Z std.out my.out >/dev/null; then
        echo "wrong answer on test #$i"
        echo "input:"
        cat data.in
        echo "expected:"
        cat std.out
        echo "received:"
        cat my.out
        break
    fi
    echo "Passed #$i"
    ((i++))
done

*************************

********** bat **********
@echo off
:loop
    gen.exe > 1.in
    std.exe < 1.in > std.out
    my.exe < 1.in > my.out
    fc my.out std.out > nul
    if %errorlevel%==0 (
        echo ac
        goto loop
    ) else (
        echo wa
        goto :eof
    )
*************************