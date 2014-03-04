#include <string>

#include <gtest/gtest.h>

#include <qmonix/event.hpp>
#include <qmonix/timing_event.hpp>
#include <qmonix/event_dispatcher.hpp>


using namespace std;


TEST(http_event_dispatcher, dispatch)
{
	qmonix::event *ev = NULL;
	qmonix::timing_event *tev = NULL;
	qmonix::event_dispatcher *dispatcher = NULL;

	ev = new qmonix::event("event1");
	ASSERT_TRUE(ev != NULL);

	tev = new qmonix::timing_event("timing-event1");
	ASSERT_TRUE(tev != NULL);

	dispatcher = new qmonix::event_dispatcher("http:/localhost:8080");
	ASSERT_TRUE(dispatcher != NULL);

	dispatcher->submit(ev);
	ev = NULL;

	tev->stop();
	dispatcher->submit(tev);
	tev = NULL;

	dispatcher->dispatch();
	dispatcher->dispatch();

	delete dispatcher;
}
