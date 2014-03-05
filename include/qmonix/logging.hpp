/**
 * Qmonix SDK c++ client uses logging macros defined in here, you can
 * easily redefine those macros to adopt to your current logging system.
 */

#ifndef INCLUDE_iZDBiMmI0NzdiMjU2MDA5ZTRjN2JjNjFk
#define INCLUDE_iZDBiMmI0NzdiMjU2MDA5ZTRjN2JjNjFk 1


#include <iostream>
#include <sstream>


/* do not use it directly */
#define QLOG_(level, log_expr) \
	std::cerr << "[" level "] " << __FUNCTION__ << ":" << __LINE__ \
		<< ": " << log_expr << '\n';


#define QLOG_ERROR(log_expr) QLOG_("error", log_expr)
#define QLOG_WARNING(log_expr) QLOG_("warning", log_expr)
#define QLOG_INFO(log_expr) QLOG_("info", log_expr)

/* Debug logs disabled on release build. */
#ifdef QMONIX_BUILD_RELEASE

#define QLOG_DEBUG(log_expr) \
{ \
	std::stringstream ss; \
	ss << log_expr; \
}

#else

#define QLOG_DEBUG(log_expr) QLOG_("debug", log_expr)

#endif


#endif /* INCLUDE_iZDBiMmI0NzdiMjU2MDA5ZTRjN2JjNjFk */
