#include <gtest/gtest.h>

#include <qmonix/tracker.hpp>
#include <qmonix/event_dispatcher.hpp>


using namespace qmonix;
using namespace std;


TEST(tracker, dispatch)
{
	tracker *test_tracker = NULL;
	event_dispatcher *ev_dispatcher = NULL;
	fireable_timing_event *time_ev = NULL;

	ev_dispatcher = new event_dispatcher("http://127.0.0.1:8080");
	ASSERT_TRUE(ev_dispatcher != NULL);

	test_tracker = new tracker(ev_dispatcher);
	ASSERT_TRUE(test_tracker != NULL);
	ev_dispatcher = NULL;

	test_tracker->fire("event1");
	test_tracker->fire("volume_event1", 15);
	time_ev = test_tracker->start("timing_event1");
	time_ev->fire();

	test_tracker->dispatch();

	delete test_tracker;
	test_tracker = NULL;
}
