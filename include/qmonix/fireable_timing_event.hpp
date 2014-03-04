#ifndef INCLUDE_YTQ2ZTZkNmVkOTExZGQ2MzA3MWQ4ZmMz
#define INCLUDE_YTQ2ZTZkNmVkOTExZGQ2MzA3MWQ4ZmMz 1


#include <string>

#include <qmonix/qmonix.hpp>
#include <qmonix/timing_event.hpp>
#include <qmonix/event_dispatcher.hpp>


namespace qmonix
{
	class fireable_timing_event : public timing_event
	{
		private:
			event_dispatcher *ev_dispatcher;

		public:
			/**
			 * Creates new timing event that you can fire: pass
			 * it to the specified event dispatcher.
			 *
			 * @param tag event tag name.
			 * @param ev_dispatcher pointer to event dispatcher
			 *	object (not NULL).
			 */
			fireable_timing_event(std::string tag,
				event_dispatcher *ev_dispatcher);

			/**
			 * Stops timing event if it was running and submits
			 * it to the event dispatcher specified by constructor.
			 *
			 * Event dispatcher destroys this event.
			 */
			void fire(void);
	};
}


#endif /* INCLUDE_YTQ2ZTZkNmVkOTExZGQ2MzA3MWQ4ZmMz */
