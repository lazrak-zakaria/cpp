#include "find_replace.hpp"


bool	find_replace(std::string file, std::string from, std::string to)
{
	std::ifstream	ifs(file);
	if (!ifs.is_open())
	{
		std::cout << "Error file\n";
		return (false);
	}

	file += ".replace";
	std::ofstream ofs(file,std::ofstream::trunc);
	if (!ofs.is_open())
	{
		std::cout << "Error file\n";
		return (false);
	}

	std::size_t	found = std::string::npos;
	std::size_t	to_found_len = from.length();
	std::string	line;
	while ('_')
	{
		getline(ifs, line);
		if (ifs.eof() && line.empty())
			break; 
		// https://stackoverflow.com/questions/59296633/stdgetline-is-not-reading-last-line-of-input-file-that-has-no-n
		// if (ifs.eof()) it can be true even if the line is not empty == lastline without '\n'
		 	// break; 
		if (!from.empty())
			found = line.find(from);
		while (found != std::string::npos)
		{
			line.insert(found, to);
			line.erase(found + to.length(), to_found_len);
			found = line.find(from, found + to.length());
		}
		ofs << line ;
		if (!ifs.eof()) // cuz i should not append '\n' to the last line if not end with '\n'
			ofs << "\n";
		if (ifs.eof())
			break;
	}
	ofs.close();
	ifs.close();
	return (true);
}