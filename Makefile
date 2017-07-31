default:
	g++ *.cpp -l pthread `pkg-config --cflags --libs libnotify` -o tlist

clean:
	rm tlist

