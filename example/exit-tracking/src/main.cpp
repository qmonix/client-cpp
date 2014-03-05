#include <iostream>

#include <qmonix/tracker.hpp>
#include <qmonix/event_dispatcher.hpp>
#include <qmonix/qmonix.hpp>

using namespace std;
using namespace qmonix;


int
main(int argc, char *argv[])
{
	argc = argc;
	argv = argv;

	tracker *qtrack = new tracker(
		new event_dispatcher("http://localhost:8337/event/"));

	qtrack->fire("exit_app/started");
	qtrack->dispatch();

	string command = "";
	while (command != "exit")
	{
		cout << "Qmonix client version: " << qmonix::version << endl;
		cout << "Type 'exit' to quit." << endl;

		cin >> command;
	}

	qtrack->fire("exit_app/exited");
	qtrack->dispatch();
	delete qtrack;

	return 0;
}
