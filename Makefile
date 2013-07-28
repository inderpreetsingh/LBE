
all: laka 

laka:	session.o laka_engine.o auth.o user.o post_loop.o
	g++ session.o laka_engine.o auth.o user.o post_loop.o -o laka  -I/usr/local/include -L/usr/local/lib -lwthttp -lwt -lboost_regex -lboost_signals -lboost_system -lboost_thread -lboost_filesystem -lboost_date_time -lwtdbo -lwtdbosqlite3

session.o: session.C
	g++ -Wall -std=c++0x -c session.C


laka_engine.o: laka_engine.C
	g++ -Wall -std=c++0x  -c laka_engine.C

auth.o: auth.C
	g++ -Wall -std=c++0x -c auth.C

user.o: user.C
	g++ -Wall -std=c++0x -c user.C

post_loop.o: post_loop.C
	g++ -Wall -std=c++0x -c post_loop.C

clean:
	 rm -rf *.o laka

run:
	./laka --docroot . --http-address 0.0.0.0 --http-port 1313                                                     
