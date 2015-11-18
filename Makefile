all: connection.cpp
	g++ connection.cpp -I /usr/local/lib -I /usr/local/include/pqxx -lpqxx -lpq -o program
