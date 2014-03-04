#include <string>

#include <qmonix/fireable_timing_event.hpp>


using namespace std;
using namespace qmonix;


fireable_timing_event::fireable_timing_event(string tag,
	event_dispatcher *ev_dispatcher) : timing_event(tag)
{
	this->ev_dispatcher = ev_dispatcher;
}


void
fireable_timing_event::fire(void)
{
	this->stop();
	this->ev_dispatcher->submit(this);
}
