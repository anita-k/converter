#include <ctime>
#include <iostream>

std::string timestamp(){
    time_t now;
    struct tm nowLocal{};
    now = time(nullptr);
    localtime_s(&nowLocal, &now);

    return std::to_string(nowLocal.tm_mday) + "." + std::to_string(nowLocal.tm_mon) + "."
    + std::to_string(nowLocal.tm_year+1900) + " " + std::to_string(nowLocal.tm_hour) + "."
    + std::to_string(nowLocal.tm_min) + "." + std::to_string(nowLocal.tm_sec) + "\n";

}