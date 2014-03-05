#ifndef INCLUDE_NjlkYmUyZTM2YTI4YjZmMjhjYjkzYjlh
#define INCLUDE_NjlkYmUyZTM2YTI4YjZmMjhjYjkzYjlh 1


#include <string>

#include <qmonix/qmonix.hpp>
#include <qmonix/fireable_timing_event.hpp>
#include <qmonix/event_dispatcher.hpp>


namespace qmonix
{

	class tracker
	{
		private:
			event_dispatcher *dispatcher;

		public:
			/**
			 * Creates a new tracker and assigns the specified
			 * event dispatcher to it.
			 *
			 * @param dispatcher event dispatcher object
			 *	(not NULL).
			 */
			tracker(event_dispatcher *dispatcher);


			/**
			 * Destroys tracker and event dispatcher object
			 * assigned to it. Does not dispatch the collected
			 * events, this must be done explicitly with
			 * dispatch().
			 */
			~tracker(void);


			/**
			 * Fires an event with the specified tag.
			 * Event volume is 1.
			 *
			 * @param tag fired event tag name.
			 */
			void fire(std::string tag);


			/**
			 * Fires an event with the specified tag and assings
			 * it the specified volume value.
			 */
			void fire(std::string tag, event_volume_value volume);


			/**
			 * Starts timing event with the specified tag name.
			 *
			 * @param tag timing event tag.
			 * @return pointer to created and started timing event.
			 */
			fireable_timing_event *start(std::string tag);


			/**
			 * Dispatches events with the event_disaptcher
			 * associated with the tracker.
			 */
			void dispatch(void);
	};

}


#endif /* INCLUDE_NjlkYmUyZTM2YTI4YjZmMjhjYjkzYjlh */
