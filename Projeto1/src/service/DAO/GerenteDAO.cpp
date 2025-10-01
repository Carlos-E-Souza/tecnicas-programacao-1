#include "GerenteDAO.hpp"

bool GerenteDAO::createTable() {
    const char* sql = R"(
        CREATE TABLE IF NOT EXISTS gerente (
            email TEXT UNIQUE PRIMARY KEY,
            nome TEXT NOT NULL,
            ramal TEXT UNIQUE NOT NULL,
            senha TEXT NOT NULL
        );
    )";
    char* errMsg = nullptr;
    int returnCode = sqlite3_exec(db_, sql, nullptr, nullptr, &errMsg);
    if (returnCode != SQLITE_OK) {
        cerr << "SQL error ao criar tabela gerente: " << errMsg << endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool GerenteDAO::remove(const Gerente& gerente) {
    const char* sql = "DELETE FROM gerente WHERE email = ?;";
    sqlite3_stmt* stmt;
    int returnCode = sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr);
    if (returnCode != SQLITE_OK) {
        cerr << "Falha ao preparar delete statement: " << sqlite3_errmsg(db_) << endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, gerente.getEmail().c_str(), -1, SQLITE_STATIC);

    returnCode = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (returnCode != SQLITE_DONE) {
        cerr << "Erro ao deletar gerente: " << sqlite3_errmsg(db_) << endl;
        return false;
    }
    cout << "Gerente deletado" << endl;
    return true;
}

bool GerenteDAO::insert(const Gerente& gerente) {
    const char* sql = "INSERT INTO gerente (email, nome, ramal, senha) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    int returnCode = sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr);
    if (returnCode != SQLITE_OK) {
        cerr << "Falha ao preparar insert statement: " << sqlite3_errmsg(db_) << endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, gerente.getEmail().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, gerente.getNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, gerente.getRamal().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, gerente.getSenha().c_str(), -1, SQLITE_STATIC);

    returnCode = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (returnCode == SQLITE_DONE) {
        cout << "Gerente inserido com sucesso" << endl;
        return true;
    }
    return false;
}

bool GerenteDAO::update(const Gerente& gerente) {
    const char* sql = "UPDATE gerente SET nome = ?, ramal = ?, senha = ? WHERE email = ?;";
    sqlite3_stmt* stmt;
    int returnCode = sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr);
    if (returnCode != SQLITE_OK) {
        cerr << "Falha ao preparar update statement para gerente: " << sqlite3_errmsg(db_) << endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, gerente.getNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, gerente.getRamal().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, gerente.getSenha().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, gerente.getEmail().c_str(), -1, SQLITE_STATIC); // WHERE clause

    returnCode = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (returnCode == SQLITE_DONE) {
        cout << "Gerente atualizado com sucesso" << endl;
        return true;
    } else {
        cerr << "Erro ao atualizar gerente: " << sqlite3_errmsg(db_) << endl;
        return false;
    }
}


vector<Gerente> GerenteDAO::findAll() {
    vector<Gerente> gerentes;
    const char* sql = "SELECT email, nome, ramal, senha FROM gerente ORDER BY email;";
    sqlite3_stmt* stmt;

    int returnCode = sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr);
    if (returnCode != SQLITE_OK) {
        return gerentes;
    }

    while ((returnCode = sqlite3_step(stmt)) == SQLITE_ROW) {
        gerentes.emplace_back(
            (const char*)sqlite3_column_text(stmt, 0),
            (const char*)sqlite3_column_text(stmt, 1),
            (const char*)sqlite3_column_text(stmt, 2),
            (const char*)sqlite3_column_text(stmt, 3)
        );
    }

    sqlite3_finalize(stmt);
    return gerentes;
}

optional<Gerente> GerenteDAO::findByEmail(const string& email) {
    const char* sql = "SELECT email, nome, ramal, senha FROM gerente WHERE email = ?;";
    sqlite3_stmt* stmt;

    int returnCode = sqlite3_prepare_v2(db_, sql, -1, &stmt, nullptr);
    if (returnCode != SQLITE_OK) {
        return nullopt;
    }

    sqlite3_bind_text(stmt, 1, email.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        Gerente gerente(
            (const char*)sqlite3_column_text(stmt, 0),
            (const char*)sqlite3_column_text(stmt, 1),
            (const char*)sqlite3_column_text(stmt, 2),
            (const char*)sqlite3_column_text(stmt, 3)
        );
        sqlite3_finalize(stmt);
        return gerente;
    }

    sqlite3_finalize(stmt);
    return nullopt;
}
