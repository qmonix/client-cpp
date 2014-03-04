#include <string>

#include <gtest/gtest.h>

#include <qmonix/timing_event.hpp>


using namespace std;


TEST(timing_event, create)
{
	qmonix::timing_event *ev = NULL;

	ev = new qmonix::timing_event("event1");
	ASSERT_TRUE(ev != NULL);

	string tag = ev->get_tag();
	ASSERT_EQ("event1", tag);

	qmonix::time_value time_arised = ev->get_time_arised();
	ASSERT_TRUE(time_arised > 0);

	delete ev;
}


TEST(timing_event, pause_resume_stop)
{
	qmonix::timing_event *ev = NULL;

	ev = new qmonix::timing_event("event1");
	ASSERT_TRUE(ev != NULL);

	qmonix::event_volume_value volume1 = ev->get_volume();
	ASSERT_TRUE(volume1 == 0);

	ev->pause();
	qmonix::event_volume_value volume2 = ev->get_volume();
	ASSERT_TRUE(volume2 >= volume1);

	ev->resume();
	ev->stop();
	qmonix::event_volume_value volume3 = ev->get_volume();
	ASSERT_TRUE(volume3 >= volume2);

	delete ev;
}
