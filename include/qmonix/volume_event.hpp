#ifndef INCLUDE_OGJmZjEwM2NjNDgyMzUyZTQ5YWY2MGQ4
#define INCLUDE_OGJmZjEwM2NjNDgyMzUyZTQ5YWY2MGQ4 1


#include <string>

#include <qmonix/qmonix.hpp>
#include <qmonix/event.hpp>


namespace qmonix
{
	class volume_event : public event
	{
		protected:
			event_volume_value volume;

		public:
			/**
			 * Creates new volume with the specified tag and event
			 * volume.
			 *
			 * @param tag event tag.
			 * @param volume event volume.
			 */
			volume_event(std::string tag,
				event_volume_value volume);


			/**
			 * Returns event volume.
			 *
			 * @return event volume.
			 */
			event_volume_value get_volume(void);


			/**
			 * Returns event serialized to JSON object.
			 *
			 * @return JSON object representing event.
			 */
			virtual std::string to_json(void);
	};
}


#endif /* INCLUDE_OGJmZjEwM2NjNDgyMzUyZTQ5YWY2MGQ4 */
