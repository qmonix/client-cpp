#include <cstdlib>
#include <ctime>

#include <string>
#include <sstream>

#include <qmonix/event.hpp>
#include <qmonix/qmonix.hpp>


using namespace qmonix;
using namespace std;


event::event(std::string tag)
{
	this->tag = tag;
	this->time_arised = time(NULL);
}


event::~event()
{
}


time_value
event::get_time_arised(void)
{
	return this->time_arised;
}


string
event::get_tag(void)
{
	return this->tag;
}


string
event::to_json(void)
{
	string retval = "";
	ostringstream os;

	os << this->time_arised;
	retval = "{\"tag\":\"" + this->tag + "\",\"whenArised\":" + os.str() +
		"}";

	return retval;
}
