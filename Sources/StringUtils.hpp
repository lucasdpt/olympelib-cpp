/*
** EPITECH PROJECT, 2023
** olympecpp [WSL : Ubuntu-22.04]
** File description:
** StringUtils
*/

#ifndef STRINGUTILS_HPP_
#define STRINGUTILS_HPP_

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

namespace olympe {
    class StringUtils {
        public:
            static std::vector<std::string> split(const std::string &str, char delim);
            static std::string &trim(std::string &str);

            static bool isNumber(const std::string &str);

            static bool endWith(const std::string &str, const std::string &suffix);
            static bool endWithIgnoreCase(const std::string &str, const std::string &suffix);
            static bool startWith(const std::string &str, const std::string &prefix);
            static bool startWithIgnoreCase(const std::string &str, const std::string &prefix);

            static std::string &toLowerCase(std::string &str);
            static std::string &toUpperCase(std::string &str);
    };
}

#endif /* !STRINGUTILS_HPP_ */
