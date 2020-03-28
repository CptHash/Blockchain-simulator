/*
** EPITECH PROJECT
** Created by mathieu on 12-03-20.
** File description:
** N/a
*/

#ifndef TEMPLATE_EXCEPTION_HPP
#define TEMPLATE_EXCEPTION_HPP

#include <exception>
#include <iostream>

class Error: public std::exception
{
    public:
        Error(std::string const& str, std::string const& file)
        throw(): str_what(str), str_file(file){}

        virtual const char* what() const throw()
        {
            return str_what.c_str();
        }

        virtual const char* file() const throw()
        {
            return str_file.c_str();
        }

        virtual ~Error() throw()
        {}

        private:
            std::string str_what;
            std::string str_file;
};

#endif //TEMPLATE_EXCEPTION_HPP
