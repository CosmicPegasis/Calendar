CXX := g++ -I include -c

bin/app: bin/main.o bin/user_interaction.o bin/users.o bin/calendar.o bin/agendas.o
	g++ bin/main.o bin/user_interaction.o bin/users.o bin/calendar.o bin/agendas.o

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

clean: 
	rm bin/*
