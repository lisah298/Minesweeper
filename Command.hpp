#include <memory>

using Action = char;
using namespace std;
class Command
{

private:
    Action action;
    unique_ptr<Coordinates> coordinates;

public:
    const Action &get_action() const { return action; };
    const Coordinates &get_coordinates() const
    {
        }
};