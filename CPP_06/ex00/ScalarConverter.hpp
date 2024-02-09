#ifndef SCALACONVERTER_HPP
# define SCALACONVERTER_HPP

# include <iostream>
# include <sstream>
# include <iomanip>

class ScalaConverter
{
	private:
		ScalaConverter();
		ScalaConverter(ScalaConverter &s);
		ScalaConverter &operator=(ScalaConverter &s);
		~ScalaConverter();

		static bool isInt(const std::string &literal);
		static bool isFloat(const std::string &literal);
		static bool isDouble(const std::string &literal);

		static void fromFail();
		static void fromChar(const std::string &literal);
		static void fromInt(const std::string &literal);
		static void fromFloat(const std::string &literal);
		static void fromDouble(const std::string &literal);
		static void fromLiteral(const std::string &literal);

	public:
		static void convert(const std::string &literal);
};

#endif // SCALACONVERTER_HPP