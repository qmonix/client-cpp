#ifndef INCLUDE_OTA3NzU3YWVkODg5OGI2MmI0NDVkYWQ0
#define INCLUDE_OTA3NzU3YWVkODg5OGI2MmI0NDVkYWQ0 1


#include <string>
#include <list>

#include <qmonix/qmonix.hpp>
#include <qmonix/event.hpp>


namespace qmonix
{
	class event_dispatcher
	{
		private:
			std::list<event *> collected_events;
			std::string server_address;

		public:
			/**
			 * Creates a new HTTP event dispatcher and assigns
			 * server address to it.
			 *
			 * @param server_address server address where collected
			 *	events will be sent to.
			 */
			event_dispatcher(std::string server_address);


			/**
			 * Does not dispatch the collected events, this must
			 * be done explicitly with dispatch().
			 */
			~event_dispatcher(void);


			/**
			 * Adds the specified event object to the list of
			 * events that will be explicitly dispatched with
			 * dispatch().
			 *
			 * @param ev event to dispatch (not NULL).
			 */
			void submit(qmonix::event *ev);


			/**
			 * Sends collected events over HTTP to the server whose
			 * address was specified with constructor. Clears the
			 * collected event list.
			 */
			void dispatch(void);


			/**
			 * Returns collected events serialized to JSON encoded
			 * message. This message is ready to be sent to server.
			 *
			 * @return JSON object representing message of
			 *	collected events.
			 */
			std::string to_json(void);
	};
}


#endif /* INCLUDE_OTA3NzU3YWVkODg5OGI2MmI0NDVkYWQ0 */
