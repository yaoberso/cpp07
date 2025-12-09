#include "../include/ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <cmath>

static void printChar(double d)
{
    std::cout << "char: ";
    if (std::isnan(d) || d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

static void printInt(double d)
{
    std::cout << "int: ";
    if (std::isnan(d) || d < INT_MIN || d > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
}

static void printFloat(double d)
{
    std::cout << "float: ";
    if (std::isnan(d))
        std::cout << "nanf" << std::endl;
    else if (d == std::numeric_limits<double>::infinity())
        std::cout << "+inff" << std::endl;
    else if (d == -std::numeric_limits<double>::infinity())
        std::cout << "-inff" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1)
                  << static_cast<float>(d) << "f" << std::endl;
}

static void printDouble(double d)
{
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan" << std::endl;
    else if (d == std::numeric_limits<double>::infinity())
        std::cout << "+inf" << std::endl;
    else if (d == -std::numeric_limits<double>::infinity())
        std::cout << "-inf" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1)
                  << d << std::endl;
}

/* ************************************************************************** */
/*                            TYPE DETECTION                                   */
/* ************************************************************************** */

bool ScalarConverter::isCharLiteral(const std::string &s)
{
    return (s.size() == 3 && s[0] == '\'' && s[2] == '\'');
}

bool ScalarConverter::isIntLiteral(const std::string &s)
{
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;

    if (i == s.size()) return false;

    for (; i < s.size(); i++)
        if (!isdigit(s[i]))
            return false;

    return true;
}

bool ScalarConverter::isFloatLiteral(const std::string &s)
{
    if (s == "-inff" || s == "+inff" || s == "nanf")
        return true;

    if (s.size() < 2 || s[s.size() - 1] != 'f')
        return false;

    bool dot = false;
    size_t i = 0;
    std::string core = s.substr(0, s.size() - 1);

    if (core[i] == '+' || core[i] == '-')
        i++;

    if (i == core.size()) return false;

    for (; i < core.size(); i++)
    {
        if (core[i] == '.') {
            if (dot) return false;
            dot = true;
        }
        else if (!isdigit(core[i]))
            return false;
    }

    return true;
}

bool ScalarConverter::isDoubleLiteral(const std::string &s)
{
    if (s == "-inf" || s == "+inf" || s == "nan")
        return true;

    bool dot = false;
    size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;

    if (i == s.size()) return false;

    for (; i < s.size(); i++)
    {
        if (s[i] == '.') {
            if (dot) return false;
            dot = true;
        }
        else if (!isdigit(s[i]))
            return false;
    }

    return dot;
}

/* ************************************************************************** */
/*                                 CONVERT                                     */
/* ************************************************************************** */

void ScalarConverter::convert(const std::string &literal)
{
    double baseValue = 0.0;
    if (isCharLiteral(literal))
    {
        baseValue = static_cast<double>(literal[1]);
    }
    else if (isIntLiteral(literal))
    {
        errno = 0;
        long n = std::strtol(literal.c_str(), NULL, 10);
        baseValue = static_cast<double>(n);
    }
    else if (isFloatLiteral(literal))
    {
        baseValue = std::strtod(literal.c_str(), NULL);
    }
    else if (isDoubleLiteral(literal))
    {
        baseValue = std::strtod(literal.c_str(), NULL);
    }
    else
    {
        std::cout << "Invalid input" << std::endl;
        return;
    }
    printChar(baseValue);
    printInt(baseValue);
    printFloat(baseValue);
    printDouble(baseValue);
}

//atof pour double et float
//atoi pour int