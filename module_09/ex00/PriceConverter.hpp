#ifndef PriceConverter_HPP
# define PriceConverter_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <regex>
#include <vector>
#include <iterator>

class PriceConverter
{

	private:
		std::fstream 					file;
		std::map<std::string, std::string> 		database;
		
	public:
		PriceConverter();
		PriceConverter(std::string filename);
		PriceConverter( PriceConverter const & src );
		~PriceConverter();
		PriceConverter &		operator=( PriceConverter const & rhs );
		

		void 	open_file(std::string filename);
		bool 	is_open;

		bool 	validate(std::string);
		void	fill_lines();

		void 	process();


};

#endif /* *************************************************** PriceConverter_H */