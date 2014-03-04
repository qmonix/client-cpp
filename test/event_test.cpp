#include <string>

#include <gtest/gtest.h>

#include <qmonix/event.hpp>


using namespace std;


TEST(event, create)
{
	qmonix::event *ev = NULL;

	ev = new qmonix::event("event1");
	ASSERT_TRUE(ev != NULL);

	string tag = ev->get_tag();
	ASSERT_EQ("event1", tag);

	qmonix::time_value time_arised = ev->get_time_arised();
	ASSERT_TRUE(time_arised > 0);

	delete ev;
}
