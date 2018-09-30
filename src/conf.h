#include <string>
#include <vector>

using namespace std;

namespace zfr
{

class meta_data
{
protected:
    string name;
    uint32_t offset; //local offset
    uint32_t size;
    string type;
};

class section : public meta_data
{
protected:
    vector<meta_data> _meta_v;
};

class reader
{
public:
    static vector<section> read(string filepath);

    static vector<string> lexical_analysis(string data);
};

} //namespace zfr
