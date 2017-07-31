default:
	g++ *.cpp -l pthread `pkg-config --cflags --libs libnotify` -o grocery 

clean:
	rm tlist

