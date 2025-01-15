all: compile run

compile:
	# g++ -std=c++17 -IC:/opencv/build/include -L C:/opencv/build/x64/vc15/lib -lopencv_world451 opencv.cpp -o main.exe
	g++ -std=c++17 -IC:/opencv/build/include opencv.cpp -o test.exe -LC:/opencv/build/x64/mingw/lib -lopencv_core -lopencv_highgui -lopencv_imgcodecs

run:
	./main.exe