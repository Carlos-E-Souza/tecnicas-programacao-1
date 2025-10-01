#ifndef GERENTEDAO_HPP_INCLUDED
#define GERENTEDAO_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <optional>

#include "BaseDAO.hpp"
#include "../container/Gerente.hpp"

using namespace std;

class GerenteDAO : public BaseDAO<Gerente> {

    public:
        GerenteDAO(sqlite3* db) : BaseDAO<Gerente>(db) {}

        bool createTable() override;
        bool remove(const Gerente& gerente) override;
        vector<Gerente> findAll() override;
        optional<Gerente> findByEmail(const string& email);
        bool insert(const Gerente& gerente) override;
        bool update(const Gerente& gerente) override;

};

#endif // GERENTEDAO_HPP_INCLUDED
