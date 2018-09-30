#include <stdio.h>
#include <iostream>

#include "environment.h"
#include "conf.h"

using namespace std;
using namespace zfr;
using namespace environment;

int main()
{
    string dir = get_bin_dir();
    cout << dir << endl;
    string filepath = dir + "/../conf/qcow2.conf";
    reader::read(filepath);
    return 0;
}
