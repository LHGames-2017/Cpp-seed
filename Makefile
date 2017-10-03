build:
	g++ -std=c++11 utils.cpp DataStructures.cpp ai.cpp -o ai -lboost_system -lcrypto -lssl -lcpprest -I ./includes

clean:
	rm ai
