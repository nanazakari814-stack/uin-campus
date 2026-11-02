#include <iostream>
#include "uincampus/version.hpp"
int main() {
    std::cout << "uin-campus version:" << uincampus::get_version() << std::endl;
    return 0;
}