/*
An example of tightly coupled code where components are highly dependent on each other
*/
// #include <iostream>
// #include <string>

// class MySQLDatabase {
// public:
//     void connect() {
//         std::cout << "Connecting to MySQL database..." << std::endl;
//     }

//     void query(const std::string& sql) {
//         std::cout << "Executing MySQL query: " << sql << std::endl;
//     }
// };

// class UserRepository {
// private:
//     MySQLDatabase db; //direct dependency on concrete implementation

// public:
//     UserRepository() {
//         db.connect(); //creates and manages its own database connection
//     }

//     void getUser(int id) {
//         db.query("SELECT * FROM users WHERE id = " + std::to_string(id));
//     }
// };


// int main() {
//     UserRepository repo;
//     repo.getUser();

//     return 0;
// }

/*
The above example is bad. Why?
1. UserRepository is tightly coupled to MySQLDatabase
2. Changing databases would require modifying UserRepository
3. Difficult to test UserRepository without a real MySQL connection
4. UserRepository manages its own database connection

*/

//the same example, but with decoupling

#include <iostream>
#include <string>
#include <memory>

//abstract interface for database operations
class Database {
public:
    virtual ~Database() = default;
    virtual void connect() = 0;
    virtual void query(const std::string& sql) = 0;
};

//concrete mysql implementation
class MySQLDatabase : public Database {
public:
    void connect() override {
        std::cout << "Connecting to MySQL database..." << std::endl;
    }

    void query(const std::string& sql) override {
        std::cout << "Executing MySQL query: " << sql << std::endl;
    }
};

// Concrete PostgreSQL implementation
class PostgreSQLDatabase : public Database {
public:
    void connect() override { 
        std::cout << "Connecting to PostgreSQL database..." << std::endl; 
    }
    
    void query(const std::string& sql) override { 
        std::cout << "Executing PostgreSQL query: " << sql << std::endl; 
    }
};


// UserRepository depends only on the Database interface
class UserRepository {
private:
    std::shared_ptr<Database> db;  // Dependency on abstraction
    
public:
    // Dependency is injected through constructor
    UserRepository(std::shared_ptr<Database> database) : db(database) {
        db->connect();
    }
    
    void getUser(int id) {
        db->query("SELECT * FROM users WHERE id = " + std::to_string(id));
    }
};

int main() {
    // Dependency injection - we can easily switch implementations
    auto mysqlDb = std::make_shared<MySQLDatabase>();
    UserRepository mysqlRepo(mysqlDb);
    mysqlRepo.getUser(1);
    
    auto pgDb = std::make_shared<PostgreSQLDatabase>();
    UserRepository pgRepo(pgDb);
    pgRepo.getUser(2);
    
    return 0;
}

/*
In Object-Oriented Programming (OOP), dependency injection is a design pattern that 
promotes loose coupling and modularity by providing a class with its dependencies 
(other objects it needs to function) externally, rather than having it create 
them internally. 
*/