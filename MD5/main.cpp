#include <iostream>
#include <string>
#include "MD5.h"

int main(const int argc, const char *argv[])
{
        std::string str = "grape";
        MD5 md5 = MD5(str);
        std::string hashStr = md5.hexdigest();
        std::cout << hashStr << std::endl;

        // 或者
        //cout << "hashStr:" << MD5(str) << endl;
        return 0;
}
