#compile and output the apps
all: generator.cpp dumper.cpp log_message.cpp logger.cpp 
	g++ -o generator generator.cpp log_message.cpp logger.cpp -l sqlite3
	g++ -o dumper dumper.cpp log_message.cpp logger.cpp -l sqlite3

#clean up files
clean:
	rm -f generator dumper database *.o
