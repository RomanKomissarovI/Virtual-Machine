OBJFILES := obj/assembler.o obj/label_func.o obj/main.o obj/size_counter.o
FLAGS := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: main.exe 

run: main.exe
	./main.exe

obj/assembler.o: src/assembler.cpp
	@ g++ src/assembler.cpp -c $(FLAGS) -o obj/assembler.o

obj/label_func.o: src/label_func.cpp
	@ g++ src/label_func.cpp -c $(FLAGS) -o obj/label_func.o

obj/main.o: src/main.cpp
	@ g++ src/main.cpp -c $(FLAGS) -o obj/main.o

obj/size_counter.o: src/size_counter.cpp
	@ g++ src/size_counter.cpp -c $(FLAGS) -o obj/size_counter.o

main.exe : $(OBJFILES)
	@ g++ $(FLAGS) $(OBJFILES) -o main.exe
