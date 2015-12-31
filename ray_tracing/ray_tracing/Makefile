
all: RayTracing_c

RayTracing_c: main.o
	g++ -o RayTracing_c main.o

main.o: main.cpp raytracing.h
	g++ -c main.cpp -o main.o -O3 -Wall

clean:
	rm -f main.o RayTracing_c out.ppm
