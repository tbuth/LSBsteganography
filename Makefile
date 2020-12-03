all: encoder decoder
encoder: encoder.cpp
	g++ -O3 -o encoder encoder.cpp -lm -lpthread -lX11 -ljpeg -lpng
decoder: decoder.cpp
	g++ -O3 -o decoder decoder.cpp -lm -lpthread -lX11 -ljpeg -lpng
