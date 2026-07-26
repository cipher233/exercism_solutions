#include <string>

namespace log_line {
std::string message(std::string line) {
    // return the message
    return line.substr(line.find(' ') + 1);
}

std::string log_level(std::string line) {
    // return the log level
    size_t start = line.find('[');
    size_t end = line.find(']');
    return line.substr(start + 1, end - start - 1);
}

std::string reformat(std::string line) {
    // return the reformatted message
    return message(line) + " (" + log_level(line) + ")";
}
}  // namespace log_line
