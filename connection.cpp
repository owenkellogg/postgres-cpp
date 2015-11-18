#include <iostream>
#include <pqxx/pqxx>

int main()
{
	std::string sql;

	try {
	pqxx::connection conn("dbname=test user=postgres hostaddr=127.0.0.1 port=5432");

	std::cout << "hello postgres" << std::endl;

	if (conn.is_open())
	{
		std::cout << "Opened database successfully: " << conn.dbname() << std::endl;
	}
	else {
		std::cout << "Failed to open database" << std::endl;
		return 1;
	}

	sql = "CREATE TABLE company(" \
	"id INT PRIMARY KEY," \
	"name TEXT NOT NULL," \
	"age INT NOT NULL," \
	"address CHAR(50)," \
	"salary REAL)" ;

	pqxx::work W(conn);

	W.exec(sql);
	W.commit();
	std::cout << "Table created successfully!" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
