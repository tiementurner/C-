#ifndef PriceConverter_HPP
# define PriceConverter_HPP

# include <iostream>
# include <string>
# include <fstream>

class PriceConverter
{

	private:
		std::fstream file;
		
	public:
		PriceConverter();
		PriceConverter(std::string filename);
		PriceConverter( PriceConverter const & src );
		~PriceConverter();
		PriceConverter &		operator=( PriceConverter const & rhs );
		

		void open_file(std::string filename);
		bool is_open;

		bool 	validate(std::string);
		void	fill_lines();




};

#endif /* *************************************************** PriceConverter_H */