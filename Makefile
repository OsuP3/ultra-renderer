
make: clean build run video preview
	@echo All build targets completed

preview: build
	@echo Making preview
	./main.exe --preview
	ffmpeg -i frame-preview.ppm frame-preview.png -y
	@echo Preview created
	rm ./frame-preview.ppm

build:
	@echo Making build
	g++ ./src/main.cpp ./src/vector3.cpp ./src/ray.cpp ./src/sphere.cpp ./src/plane.cpp -o main.exe
	@echo Build finished

run:
	@echo Running main
	./main.exe

video:
	@echo Creating video
	ffmpeg -framerate 30 -i "./frames/frame-%d.ppm" -c:v libx264 -pix_fmt yuv420p output.mp4 -y
	@echo Video rendered

clean:
	@echo Cleaning build artifacts
	rm ./main.exe -f
	rm ./test.pp -f
	rm ./frames/* -f
	@echo Build artifacts cleaned



