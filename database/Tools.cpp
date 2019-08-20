#include "Tools.h"
#include <vector>
#include <uuid/uuid.h>

using std::string;
using std::vector;

Tools::Tools()
{
}

Tools::~Tools()
{
}

std::string Tools::uuid()
{
	uuid_t id;
	vector<char> buffer(36);
	uuid_generate(id);
	uuid_unparse(id, &buffer[0]);
	return &buffer[0];
}
