#!/bin/sh
LIBS="-liup -lgdi32 -lcomdlg32 -lcomctl32 -luuid -loleaut32 -lole32 -mwindows"

rm -rf *.exe

gcc main.c -o main.exe $LIBS
gcc student_window.c -o student_window.exe $LIBS
gcc teacher_window.c -o teacher_window.exe $LIBS
gcc take-attendance.c -o take-attendance.exe $LIBS

./main
