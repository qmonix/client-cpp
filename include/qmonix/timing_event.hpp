/**
 * Timing events extend volume events. Timing event volume is the amount of
 * time since event has been started and running. To get this time use
 * get_volume().
 */

#ifndef INCLUDE_MmE3MzZiMWU5NjkzZGY5YjI5ODk1ZWMx
#define INCLUDE_MmE3MzZiMWU5NjkzZGY5YjI5ODk1ZWMx 1


#include <string>

#include <qmonix/qmonix.hpp>
#include <qmonix/volume_event.hpp>


namespace qmonix
{
	enum timing_event_state
	{
		TIMING_EVENT_STARTED,
		TIMING_EVENT_PAUSED,
		TIMING_EVENT_STOPPED
	};


	class timing_event : public volume_event
	{
		private:
			enum timing_event_state state;
			time_value time_started;

		public:
			/**
			 * Creates timing event with the specified tag.
			 * Initially timing event is started.
			 *
			 * @param tag event tag.
			 */
			timing_event(std::string tag);


			virtual ~timing_event(void);


			/**
			 * Returns current state of timing event.
			 *
			 * @return event state.
			 */
			enum timing_event_state get_state();


			/**
			 * Pauses the timing event. Does nothing if timing
			 * event is not running.
			 */
			void pause();


			/**
			 * Resumes a paused event. If event was not paused
			 * does nothing.
			 */
			void resume();


			/**
			 * Stops timing event. After this operation timing
			 * event cannot be resumed.
			 */
			void stop();
	};

}


#endif /* INCLUDE_MmE3MzZiMWU5NjkzZGY5YjI5ODk1ZWMx */
