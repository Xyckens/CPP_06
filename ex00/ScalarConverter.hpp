#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

#include <cstdlib>

#include <string> 

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& other);

public:
	static void	convert(std::string conv);
	static void	convert_char(std::string conv);
	static void	convert_int(std::string conv);
	static void	convert_float(std::string conv);
	static void	convert_double(std::string conv);
};

#endif
