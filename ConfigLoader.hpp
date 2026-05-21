#ifndef CONFIGLOADER_HPP
#define CONFIGLOADER_HPP

#include <string>
#include <stdexcept>

class InvalidExtensionException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class SystemConfigException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class ConfigLoader {
public:
    void load(const std::string &filename);
};

#endif // CONFIGLOADER_HPP
