#include <string>

#include <qmonix/qmonix.hpp>
#include <qmonix/tracker.hpp>
#include <qmonix/event.hpp>
#include <qmonix/fireable_timing_event.hpp>
#include <qmonix/volume_event.hpp>
#include <qmonix/event_dispatcher.hpp>


using namespace std;
using namespace qmonix;


tracker::tracker(event_dispatcher *dispatcher)
{
	this->dispatcher = dispatcher;
}


tracker::~tracker(void)
{
	delete this->dispatcher;
	this->dispatcher = NULL;
}


void
tracker::fire(string tag)
{
	event *ev = NULL;

	ev = new event(tag);
	this->dispatcher->submit(ev);
}


void
tracker::fire(std::string tag, event_volume_value volume)
{
	event *ev = NULL;

	ev = new volume_event(tag, volume);
	this->dispatcher->submit(ev);
}


fireable_timing_event *
tracker::start(std::string tag)
{
	fireable_timing_event *retval = NULL;

	retval = new fireable_timing_event(tag, this->dispatcher);

	return retval;
}


void
tracker::dispatch(void)
{
	this->dispatcher->dispatch();
}
