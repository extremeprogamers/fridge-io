#include <string>
#include <vector>

using namespace std;

class AbstractDatabase
{
public:
    virtual bool add(string message);
    virtual bool remove(string message);
    virtual vector<string> getAll();
    virtual bool clear();    
};