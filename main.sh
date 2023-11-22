rm -rf build/*.exe &&
gcc src/main.c -o build/main.exe -liup -lgdi32 -lcomdlg32 -lcomctl32 -luuid -loleaut32 -lole32 -mwindows &&
gcc src/student.c -o build/student.exe -liup -lgdi32 -lcomdlg32 -lcomctl32 -luuid -loleaut32 -lole32 -mwindows &&
gcc src/teacher.c -o build/teacher.exe -liup -lgdi32 -lcomdlg32 -lcomctl32 -luuid -loleaut32 -lole32 -mwindows &&
./build/main
