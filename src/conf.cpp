#include <fstream>
#include <iostream>
#include "conf.h"

using namespace std;

namespace zfr
{

vector<section> reader::read(string filepath)
{
    vector<section> sec;

    ifstream in(filepath, ios::in);
    if (!in)
    {
        cout << "error cant read " << filepath << endl;
        return sec;
    }

    istreambuf_iterator<char> beg(in), end;
    string data(beg, end);
    in.close();

    //cout << data << endl;
    lexical_analysis(data);

    return sec;
}

vector<string> reader::lexical_analysis(string data)
{
    vector<string> result;
    string tstr;

    for (auto it = data.begin(); it != data.end(); ++it)
    {
        switch(*it)
        {
            case ' ':
                if (!tstr.empty())
                {
                    result.push_back(tstr);
                    tstr = "";
                }
                break;
            case ';':
                if (!tstr.empty())
                {
                    result.push_back(tstr);
                    tstr = "";
                }

                result.push_back(";");
                break;
            case '\n':
                break;
            default:
                tstr += *it;
                break;
        }
    }

    for (auto it = result.begin(); it != result.end(); ++it)
    {
        cout << *it << endl;
    }

    return result;
}

} //namespace zfr
