#include <memory>

using Action = char;
using namespace std;
class Command
{

private:
    Action action;
    unique_ptr<Coordinates> coordinates{nullptr};

public:
    const Action &get_action() const { return action; };
    const Coordinates &get_coordinates() const
    {
        if (!coordinates)
        {
            abort();
        }
        else
        {
            return *coordinates;
        }
    }
};