#include "information.h"
#include <string>
using namespace std;

namespace wisec {
	const string Information::get_name() const noexcept {
		return name;
	}

	void Information::set_name(const string name) noexcept {
		this->name = name;
	}

	const string& Information::get_message() const noexcept {
		return message;
	}

	void Information::set_message(const string message) noexcept {
		this->message = message;
	}

	const bool Information::is_error() const noexcept {
		return error;
	}

	void Information::set_error(bool error) noexcept {
		this->error = error;
	}

	Information::Information(string& name, string& message, bool error) noexcept {
		set_name(name);
		set_message(message);
	}

	Information new_warning(string name, string message) noexcept {
		return Information(name, message, false);
	}

	Information new_error(string name, string message) noexcept {
		return Information(name, message, true);
	}
}