#include <string>
#include <sstream>

#include <qmonix/volume_event.hpp>
#include <qmonix/event.hpp>
#include <qmonix/qmonix.hpp>


using namespace std;
using namespace qmonix;


volume_event::volume_event(string tag, event_volume_value volume) : event(tag)
{
	this->volume = volume;
}


event_volume_value
volume_event::get_volume(void)
{
	return this->volume;
}


string
volume_event::to_json(void)
{
	string retval = "";
	ostringstream os;

	os << this->time_arised;
	retval = "{\"tag\":\"" + this->tag + "\",\"whenArised\":" + os.str();

	os.str("");
	os << this->volume;
	retval += ",\"volume\":" + os.str() + "}";

	return retval;
}
