#include "environment.h"

#include <unistd.h>

namespace zfr
{

namespace environment
{

string get_bin_dir()
{
    char dir[4096] = {0};
    ssize_t n = readlink("/proc/self/exe", dir, 4096);
    if (n < 0)
    {
        return "";
    }

    string bin = string(dir, n);
    return bin.substr(0, bin.find_last_of('/'));
}

} //namespace environment

} //namespace zfr
