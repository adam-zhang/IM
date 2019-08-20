#ifndef __DATABASE__H
#define __DATABASE__H

#include <string>
#include <memory>

class User;
class Group;
class Dialog;
class GroupDialog;

namespace sqlite
{
	class connection;
};

class Database
{
	public:
		Database();
		~Database();
	public:
	private:
		void initialize();
		bool createTables();
		bool createUsers();
		bool createGroups();
		bool createGroupMembers();
		bool createDialogs();
		bool createGroupDialogs();
		bool createTable(const std::string& sql);
	public:
		bool registerUser(const User&);
	private:
		std::unique_ptr<sqlite::connection> connection_;
};
#endif//__DATABASE__H
