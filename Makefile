OBJFILES := obj/compiler.o obj/executor.o obj/main.o obj/service_stack_func.o obj/stack_func.o obj/virt_mach_func.o
FLAGS := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: main.exe 

run: main.exe
	./main.exe

obj/compiler.o: src/compiler.cpp
	@ g++ src/compiler.cpp -c $(FLAGS) -o obj/compiler.o

obj/executor.o: src/executor.cpp
	@ g++ src/executor.cpp -c $(FLAGS) -o obj/executor.o

obj/main.o: src/main.cpp
	@ g++ src/main.cpp -c $(FLAGS) -o obj/main.o

obj/service_stack_func.o: src/service_stack_func.cpp
	@ g++ src/service_stack_func.cpp -c $(FLAGS) -o obj/service_stack_func.o

obj/stack_func.o: src/stack_func.cpp
	@ g++ src/stack_func.cpp -c $(FLAGS) -o obj/stack_func.o

obj/virt_mach_func.o: src/virt_mach_func.cpp
	@ g++ src/virt_mach_func.cpp -c $(FLAGS) -o obj/virt_mach_func.o

main.exe : $(OBJFILES)
	@ g++ $(FLAGS) $(OBJFILES) -o main.exe