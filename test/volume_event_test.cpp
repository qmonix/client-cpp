#include <string>

#include <gtest/gtest.h>

#include <qmonix/volume_event.hpp>


using namespace std;


TEST(volume_event, create)
{
	qmonix::volume_event *ev_vol = NULL;

	ev_vol = new qmonix::volume_event("event1", 10);

	ASSERT_TRUE(ev_vol != NULL);

	string tag = ev_vol->get_tag();
	ASSERT_EQ("event1", tag);

	qmonix::time_value time_arised = ev_vol->get_time_arised();
	ASSERT_TRUE(time_arised > 0);

	qmonix::event_volume_value volume = ev_vol->get_volume();
	ASSERT_TRUE(volume == 10);

	delete ev_vol;
}
