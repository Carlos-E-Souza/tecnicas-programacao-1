#ifndef BASEDAO_HPP_INCLUDED
#define BASEDAO_HPP_INCLUDED

#include <vector>
#include <sqlite3.h>

template<typename T> class BaseDAO {

    protected:
        sqlite3* db_;

    public:
        BaseDAO(sqlite3* db) : db_(db) {}
        virtual ~BaseDAO() = default;

        virtual bool insert(const T& entity) = 0;
        virtual bool update(const T& entity) = 0;
        virtual bool remove(const T& entity) = 0;
        virtual std::vector<T> findAll() = 0;
        virtual bool createTable() = 0;
};

#endif // BASEDAO_HPP_INCLUDED
