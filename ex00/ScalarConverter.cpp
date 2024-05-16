#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this == &other)
		return (*this);
	*this = other;
	return (*this);

}

void	ScalarConverter::convert(std::string conv)
{
	unsigned long		i = 0;
	int		c = 0; //char
	int		p = 0; //ponto
	int		f = 0; //float
	int		n = 0; //number

	if (conv == "nan" || conv == "nanf" || conv == "-inf" || conv == "-inff"
		|| conv == "+inf" || conv == "+inff")
		i = std::string::npos;
	while (i < conv.length() && p < 2 && f < 2)
	{
		if ((conv[i] == '-' || conv[i] == '+') && i > 0)
			break ;
		else if (conv[i] == 'f')
			f++;
		else if (conv[i] == '.')
			p++;
		else if ((conv[i] < '0' || conv[i] > '9') && conv[i] != '-' && conv[i] != '+')
			c++;
		else
			n++;
		i++;
	}
	if (i < conv.length() || c > 1 || p > 1)
		return ;
	/*else if (f)
		convert_float(conv);
	else if (p)
		convert_double(conv);
	else if (n)
		convert_int(conv);
	else
		convert_char(conv);*/
	convert_char(conv);
	convert_int(conv);
	convert_float(conv);
	convert_double(conv);
}

void	ScalarConverter::convert_float(std::string conv)
{
	std::cout << "float:  ";
	if (conv == "-inff" || conv == "-inf")
		std::cout << "-inff\n";
	else if (conv == "+inff" || conv == "+inf")
		std::cout << "+inff\n";
	else if (conv == "nanf"  || conv == "nan")
		std::cout << "nanf\n";
	else if (conv.length() == 1 && (conv[0] < '0' || conv[0] > '9'))
		std::cout << static_cast<float>(conv[0]) << "f\n";
	else
		std::cout << static_cast<float>(atof(conv.c_str())) << "f\n";

}

void	ScalarConverter::convert_double(std::string conv)
{
	std::cout << "double: ";
	if (conv == "-inf" || conv == "-inff")
		std::cout << "-inf\n";
	else if (conv == "+inf"|| conv == "+inff")
		std::cout << "+inf\n";
	else if (conv == "nan" || conv == "nanf")
		std::cout << "nan\n";
	else if (conv.length() == 1 && (conv[0] < '0' || conv[0] > '9'))
		std::cout << static_cast<float>(conv[0]) << "\n";
	else
		std::cout << static_cast<float>(atof(conv.c_str())) << "\n";
}

void	ScalarConverter::convert_int(std::string conv)
{
	std::cout << "int:    ";
	long number = static_cast<long>(atol(conv.c_str()));
	if (std::numeric_limits<int>::max() < number || std::numeric_limits<int>::min() > number)
		std::cout << "overflow\n";
	else if (conv == "nan" || conv == "nanf" || conv == "-inf" || conv == "-inff"
		|| conv == "+inf" || conv == "+inff")
		std::cout << "impossible\n";
	else if (conv.length() == 1 && (conv[0] < '0' || conv[0] > '9'))
		std::cout << static_cast<int>(conv[0]) << std::endl;
	else
		std::cout << static_cast<int>(atoi(conv.c_str())) << std::endl;
}

void	ScalarConverter::convert_char(std::string conv)
{
	std::cout << "char:   ";
	if ((conv == "nan" || conv == "nanf" || conv == "-inf" || conv == "-inff"
		|| conv == "+inf" || conv == "+inff") || (conv[0] == '.' && isdigit(conv[1])))
		std::cout << "impossible\n";
	else if (((conv[0] == '-' || conv[0] == '.') && isdigit(conv[1]))
		|| (isdigit(conv[0]) && atoi(conv.c_str()) < 32) || (conv[0] == '-' && conv[1] == '.'))
		std::cout << "Non displayable\n";
	else if (isdigit(conv[0]) && atoi(conv.c_str()) > 126)
		std::cout << "overflow\n";
	else if (isprint(conv[0]))
		std::cout << "\'" << static_cast<char>(conv[0]) << "\'\n";
	else
		std::cout << "\'" << static_cast<char>(atoi(conv.c_str())) << "\'\n";


}
