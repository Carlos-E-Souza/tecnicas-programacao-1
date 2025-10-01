#include <iostream>
#include <stdexcept>
#include <string>

#include "/src/service/DAO/DatabaseManager.hpp"

using namespace std;

int main(){
    DatabaseManager dbManager("/home/kadu/sqlite3Databases/base_teste.db");

    if (!dbManager.isOpen()) {
        return 1;
    }

    if (!dbManager.createTables()) {
        std::cerr << "Failed to create tables" << std::endl;
        return 1;
    }

    Gerente gerente();

    dbManager.getGerenteDAO()->insert()
    return 0;
}
