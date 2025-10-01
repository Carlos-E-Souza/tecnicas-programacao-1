#ifndef DATABASEMANAGER_HPP_INCLUDED
#define DATABASEMANAGER_HPP_INCLUDED

#include <memory>
#include <string>
#include <iostream>
#include <sqlite3.h>

#include "GerenteDAO.hpp"

using namespace std;

class DatabaseManager {

    private:
        sqlite3* db;
        unique_ptr<GerenteDAO> gerenteDAO;

    public:
        DatabaseManager(const string& dbName) : db(nullptr) {
            int rc = sqlite3_open(dbName.c_str(), &db);
            if (rc) {
                cerr << "Erro ao tentar estabelecer conexão com BD: " << sqlite3_errmsg(db) << endl;
                sqlite3_close(db);
                db = nullptr;
            } else {
                cout << "Conectado ao BD com sucesso" << endl;
                const char* enableForeignKeys = "PRAGMA foreign_keys = ON;";
                char* errMsg = nullptr;
                sqlite3_exec(db, enableForeignKeys, nullptr, nullptr, &errMsg);
                gerenteDAO = make_unique<GerenteDAO>(db);
            }
        }

        ~DatabaseManager() {
            if (db) {
                sqlite3_close(db);
            }
        }

        bool isOpen() const { return db != nullptr; }
        bool createTables() { return gerenteDAO->createTable(); }
        GerenteDAO* getGerenteDAO() { return gerenteDAO.get(); }
        sqlite3* getDatabase() { return db; }
};

#endif // DATABASEMANAGER_HPP_INCLUDED
