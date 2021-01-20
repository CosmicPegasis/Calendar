CXX := g++ -I include -c

all: bin/app

bin/app: bin/main.o bin/user_interaction.o bin/users.o bin/calendar.o bin/agendas.o bin/date_processer.o
	g++ bin/main.o bin/user_interaction.o bin/users.o bin/calendar.o bin/agendas.o bin/date_processer.o

bin/main.o: src/main.cpp
	$(CXX) src/main.cpp -o bin/main.o

bin/user_interaction.o: src/user_interaction.cpp include/user_interaction.hpp
	$(CXX) src/user_interaction.cpp -o bin/user_interaction.o

bin/users.o: src/users.cpp include/users.hpp
	$(CXX) src/users.cpp -o bin/users.o

bin/calendar.o: src/features/calendar.cpp include/calendar.hpp
	$(CXX) src/features/calendar.cpp -o bin/calendar.o

bin/agendas.o: src/features/agendas.cpp include/agendas.hpp
	$(CXX) src/features/agendas.cpp -o bin/agendas.o

bin/date_processer.o: src/features/date_processer.cpp include/date_processer.hpp
	$(CXX) src/features/date_processer.cpp -o bin/date_processer.o

clean: 
	rm -rf bin/*
