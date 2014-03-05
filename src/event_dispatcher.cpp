#include <cstdlib>

#include <string>
#include <sstream>

extern "C"
{
#include <curl/curl.h>
}

#include <qmonix/logging.hpp>
#include <qmonix/qmonix.hpp>
#include <qmonix/event_dispatcher.hpp>
#include <qmonix/event.hpp>


using namespace std;
using namespace qmonix;


/**
 * Sends HTTP POST request to the specified URL.
 *
 * @param url target URL.
 * @param data post data.
 * @return 0 on success.
 * @return -1 on error.
 */
static int http_post(string url, string data);


/**
 * This callback is called when curl receives HTTP response data.
 */
static size_t curl_write_result_cb(char *ptr, size_t size, size_t nmemb,
	void *userdata);


event_dispatcher::event_dispatcher(string server_address)
{
	this->server_address = server_address;

	curl_global_init(CURL_GLOBAL_ALL);
}


event_dispatcher::~event_dispatcher(void)
{
	list<event*>::iterator it;

	// Destroy collected events.
	for (it = this->collected_events.begin();
		it != this->collected_events.end(); it++)
	{
		delete *it;
	}

	curl_global_cleanup();
}


void
event_dispatcher::submit(event *ev)
{
	this->collected_events.push_back(ev);
}


void
event_dispatcher::dispatch(void)
{
	http_post(this->server_address, this->to_json());
	this->collected_events.clear();
}


string
event_dispatcher::to_json(void)
{
	string retval;
	ostringstream os;
	list<event *>::iterator it;

	retval = "{\"version\":\"" + qmonix::version + "\",\"events\":[";

	for (it = this->collected_events.begin();
		it != this->collected_events.end(); it++)
	{
		retval += (*it)->to_json() + ",";
	}

	if (this->collected_events.size() > 0)
	{
		retval.resize(retval.size() - 1);
	}

	os << time(NULL);
	retval += "],\"whenSent\":" + os.str() + "}";

	return retval;
}


static int
http_post(string url, string data)
{
	int retval = -1;
	CURL *curl = NULL;
	CURLcode ret;

	curl = curl_easy_init();
	if (curl == NULL)
	{
		QLOG_ERROR("Failed to init curl.");
		goto done;
	}

	ret = curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	if (ret != CURLE_OK)
	{
		QLOG_ERROR("Failed to set url.");
		goto done;
	}

	ret = curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
	if (ret != CURLE_OK)
	{
		QLOG_ERROR("Failed to set POST data.");
		goto done;
	}

	ret = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,
		curl_write_result_cb);
	if (ret != CURLE_OK)
	{
		QLOG_ERROR("Failed to set curl write callback.");
		goto done;
	}

	ret = curl_easy_perform(curl);
	if (ret != CURLE_OK)
	{
		QLOG_ERROR("Failed to send http request.");
		goto done;
	}

	// success.
	retval = 0;

done:
	if (curl != NULL)
	{
		curl_easy_cleanup(curl);
		curl = NULL;
	}

	return retval;
}


size_t
curl_write_result_cb(char *ptr, size_t size, size_t nmemb, void *userdata)
{
	size_t retval = 0;

	userdata = userdata;

	QLOG_DEBUG("Received: " << ptr);

	retval = size * nmemb;

	return retval;
}
