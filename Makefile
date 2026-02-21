make: clean build run 

build:
	g++ ./src/main.cpp ./src/vector3.cpp ./src/ray.cpp ./src/sphere.cpp -o main.exe

run:
	./main.exe

clean:
	rm ./main.exe -f
	rm ./test.pp -f


