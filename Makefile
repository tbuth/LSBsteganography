all: encoder decoder
encoder: src/encoder.cpp
	g++ -O3 -o bin/encoder src/encoder.cpp -lm -lpthread -lX11 -ljpeg -lpng
decoder: src/decoder.cpp
	g++ -O3 -o bin/decoder src/decoder.cpp -lm -lpthread -lX11 -ljpeg -lpng
