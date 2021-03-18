#pragma once
#include <string>
using std::string;

namespace wisec {
	class Information {
	public:
		const string get_name() const noexcept;

		void set_name(const string name) noexcept;

		const string& get_message() const noexcept;

		void set_message(const string message) noexcept;

		const bool is_error() const noexcept;

		void set_error(bool error) noexcept;

		Information(string& name, string& message, bool error) noexcept;

	protected:
		string name;
		string message;
		bool error;
	};

	using Error = Information;
	using Warning = Information;

	Information new_warning(string name, string message) noexcept;

	Information new_error(string name, string message) noexcept;
}
