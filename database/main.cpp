#include <iostream>
#include "Database.h"
#include "Property.h"
#include "Tools.h"
#include "User.h"

using namespace std;

void registerUser(Database& db, const string& name, const string& mobile)
{
	User user;
	user.setID(Tools::uuid());
	user.setUserName(name);
	user.setMobile(mobile);
	db.registerUser(user);
}

int main(int argc, char** argv)
{
	Database db;
	registerUser(db, "张三", "13795947206");
	registerUser(db, "李四", "13895732810");
	registerUser(db, "王五", "12700660066");
	return 0;
}
