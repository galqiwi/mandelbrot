all:
	g++ -O3 -pthread -std=c++17 `pkg-config --cflags --libs opencv` main.cpp -o main

video15:
	ffmpeg -r 15 -y -f image2 -i %d.jpg video.mp4
video30:
	ffmpeg -r 30 -y -f image2 -i %d.jpg video.mp4
video60:
	ffmpeg -r 60 -y -f image2 -i %d.jpg video.mp4