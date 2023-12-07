# FILE="gtk-counter"
# GTK_FLAGS="`pkg-config --cflags gtk4`"
# GTK_LIBS="`pkg-config --libs gtk4`"

# gcc $FILE.c $GTK_FLAGS -o $FILE.exe $GTK_LIBS
# $FILE.exe

# rm -rf main.exe
gcc main.c `pkg-config --cflags gtk4` -o main `pkg-config --libs gtk4` -mwindows && ./main.exe
# gcc examples/button.c `pkg-config --cflags gtk4` -o examples/button `pkg-config --libs gtk4` -mwindows && ./examples/button.exe
# gcc examples/stack.c `pkg-config --cflags gtk4` -o examples/stack `pkg-config --libs gtk4` -mwindows && ./examples/stack.exe
# gcc examples/loop.c `pkg-config --cflags gtk4` -o examples/loop `pkg-config --libs gtk4` -mwindows && ./examples/loop.exe
# gcc examples/drop.c `pkg-config --cflags gtk4` -o examples/drop `pkg-config --libs gtk4` -mwindows && ./examples/drop.exe
# gcc examples/popover.c `pkg-config --cflags gtk4` -o examples/popover `pkg-config --libs gtk4` -mwindows && ./examples/popover.exe
# gcc examples/grid.c `pkg-config --cflags gtk4` -o examples/grid `pkg-config --libs gtk4` -mwindows && ./examples/grid.exe
# gcc examples/widget.c `pkg-config --cflags gtk4` -o examples/widget `pkg-config --libs gtk4` -mwindows && ./examples/widget.exe
