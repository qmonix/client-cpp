#include <ctime>

#include <string>

#include <qmonix/timing_event.hpp>


using namespace std;
using namespace qmonix;


timing_event::timing_event(string tag) : volume_event(tag, 0)
{
	this->state = TIMING_EVENT_STARTED;
	this->time_started = this->time_arised;
}


timing_event::~timing_event(void)
{
}


enum timing_event_state
timing_event::get_state()
{
	return this->state;
}


void
timing_event::pause()
{
	if (this->state == TIMING_EVENT_STARTED)
	{
		this->volume += time(NULL) - this->time_started;
		this->state = TIMING_EVENT_PAUSED;
	}
}


void
timing_event::resume()
{
	if (this->state == TIMING_EVENT_PAUSED)
	{
		this->time_started = time(NULL);
		this->state = TIMING_EVENT_STARTED;
	}
}


void
timing_event::stop()
{
	if (this->state != TIMING_EVENT_STOPPED)
	{
		this->volume += time(NULL) - this->time_started;
		this->state = TIMING_EVENT_STOPPED;
	}
}
