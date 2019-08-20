#include "Database.h"
#include <string>
#include <memory>
#include <experimental/filesystem>
#include <boost/log/trivial.hpp>
#include <sqlite3cc.h>

using namespace std;
namespace fs = std::experimental::filesystem;

string databaseName()
{
	auto fileName = fs::current_path().string() + "/im.db";
	return fileName;
}

Database::Database()
	: connection_(make_unique<sqlite::connection>(databaseName()))
{
	initialize();
}

Database::~Database()
{
}

void Database::initialize()
{
	if (!createTables())
		throw std::exception();
}

bool Database::createTables()
{
	return  createUsers()
		&& createGroups()
		&& createGroupMembers()
		&& createDialogs()
		&& createGroupDialogs();
}


bool Database::createGroupDialogs()
{
	string sql = "create table if not exists groupDialogs("
		"id uuid primary key,"
		"time integer not null,"
		"sender uuid not null,"
		"receiver uuid not null,"
		"content text not null,"
		"foreign key (sender) references users(id),"
		"foreign key (receiver) references groups(id)"
		")";
	return createTable(sql);
}



bool Database::createDialogs()
{
	string sql = "create table if not exists dialogs("
		"id uuid primary key,"
		"time integer not null,"
		"sender uuid not null,"
		"receiver uuid not null,"
		"content text not null,"
		"foreign key (sender) references users(id),"
		"foreign key (receiver) references users(id)"
		")";
	return createTable(sql);
}

bool Database::createGroupMembers()
{
	string sql = "create table if not exists groupMembers("
		"id uuid primary key,"
		"groupID uuid not null,"
		"userID uuid not null,"
		"foreign key(groupID) references groups(id),"
		"foreign key(userID) references users(id)"
		")";
	return createTable(sql);
}

bool Database::createGroups()
{
	string sql = "create table if not exists Groups("
		"id uuid primary key,"
		"groupName text not null)";
	return createTable(sql);
}


bool Database::createUsers()
{
	string sql = "create table if not exists Users("
		"id uuid primary key,"
		"userName text not null"
		")";
	return createTable(sql);
}

bool Database::createTable(const string& sql)
{
	BOOST_LOG_TRIVIAL(debug) << "begin";
	sqlite::command comm(*connection_, sql);
	comm.step();
	BOOST_LOG_TRIVIAL(debug) << "end";
	return true;
}
