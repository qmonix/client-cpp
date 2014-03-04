#ifndef INCLUDE_YTk0N2I2MmNkMmU0YTBmYzk2Yjk2MGJh
#define INCLUDE_YTk0N2I2MmNkMmU0YTBmYzk2Yjk2MGJh 1


#include <string>

#include <qmonix/qmonix.hpp>


namespace qmonix
{
	class event
	{
		protected:
			time_value time_arised;
			std::string tag;

		public:
			/**
			 * Creates a new event and assigns it the specified
			 * tag. Event creation time is saved and can be
			 * retrieved with get_time_arised().
			 *
			 * @param tag event tag name.
			 */
			event(std::string tag);


			virtual ~event();


			/**
			 * Returns event tag name.
			 *
			 * @return event tag name.
			 */
			std::string get_tag(void);


			/**
			 * Returns Unix time stamp when event was fired
			 * (created).
			 *
			 * @return event fire time.
			 */
			time_value get_time_arised(void);


			/**
			 * Returns event serialized to JSON object.
			 *
			 * @return JSON object representing event.
			 */
			virtual std::string to_json(void);
	};
}


#endif /* INCLUDE_YTk0N2I2MmNkMmU0YTBmYzk2Yjk2MGJh */
