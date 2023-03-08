/*
** EPITECH PROJECT, 2023
** olympecpp [WSL : Ubuntu-22.04]
** File description:
** StringUtils
*/

#include "StringUtils.hpp"

namespace olympe {
    std::vector<std::string> StringUtils::split(const std::string &str, char delim) {
        std::vector<std::string> elems;
        std::stringstream ss(str);
        std::string item;

        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    std::string &StringUtils::trim(std::string &str) {
        str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) {
            return !std::isspace(ch);
        }));
        str.erase(std::unique(str.begin(), str.end(), [](char a, char b) {
            return std::isspace(a) && std::isspace(b);
        }), str.end());
        return str;
    }

    bool StringUtils::isNumber(const std::string &str) {
        return !str.empty() && std::find_if(str.begin(), str.end(), [](char c) {
            return !std::isdigit(c);
        }) == str.end();
    }

    bool StringUtils::endWith(const std::string &str, const std::string &suffix) {
        return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
    }

    bool StringUtils::endWithIgnoreCase(const std::string &str, const std::string &suffix) {
        return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix, 0, suffix.size()) == 0;
    }

    bool StringUtils::startWith(const std::string &str, const std::string &prefix) {
        return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
    }

    bool StringUtils::startWithIgnoreCase(const std::string &str, const std::string &prefix) {
        return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix, 0, prefix.size()) == 0;
    }

    std::string &StringUtils::toLowerCase(std::string &str) {
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        return str;
    }

    std::string &StringUtils::toUpperCase(std::string &str) {
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
            return std::toupper(c);
        });
        return str;
    }
}
