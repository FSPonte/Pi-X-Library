#ifndef _TRACEBACK_TPP_
#define _TRACEBACK_TPP_

namespace pix
{
	struct traceback_item
	{
		std::string
			file_name, // File name
			fn_name; // Function name
		int line_number;

		traceback_item(const std::string& file_name, const std::string& fn_name, const int line_number)
			: file_name(file_name), fn_name(fn_name), line_number(line_number) {}
	};

	std::vector<traceback_item> traceback::_data;
	
	void traceback::add(const std::string& file_name, const std::string& fn_name, const int line_number) noexcept(true)
	{
		traceback::_data.push_back(traceback_item{file_name, fn_name, line_number});
	}

	void traceback::display(void) noexcept(true)
	{
		for (auto item : traceback::_data)
		{
			std::cout
				<< "file: " << item.file_name << '\n'
				<< "function: " << item.fn_name << '\n';

			if (item.line_number >= 0)
				std::cout << "line_number: " << item.line_number << '\n';

			std::cout << std::endl;
		}
	}
}

#endif // _TRACEBACK_TPP_
