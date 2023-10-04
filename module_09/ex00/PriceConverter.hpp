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
		std::fstream 							file;
		std::map<std::string, std::string> 		database;
		int										year;
		int										month;
		int										day;
		float									amount;
	public:
		PriceConverter();
		PriceConverter(std::string filename);
		PriceConverter( PriceConverter const & src );
		~PriceConverter();
		PriceConverter &		operator=( PriceConverter const & rhs );
		

		void 		open_file(std::string filename);
		bool 		is_open;

		bool 		validate_date(std::string date);
		bool		validate_amount(std::string amount);
		
		void		convert_price();

		void 		process();


};

#endif /* *************************************************** PriceConverter_H */