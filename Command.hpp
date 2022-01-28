#include <memory>
#include <string>
#include <iostream>
#include <string.h>

using Action = char;
using namespace std;
class Command
{

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
    void read()
    {
        size_t x;
        size_t y;
        Action action;
        cout << "Please enter your command\n";
        cin >> action >> x >> y;
        cout << x << y << endl;

        if (action == 'q' or action == 'h')
        {
            coordinates.release();
        }
        else
        {
            Coordinates new_coordinates{x, y};
            coordinates = make_unique<Coordinates>(new_coordinates);
        }
    };

private:
    Action action;
    unique_ptr<Coordinates> coordinates{nullptr};
    /*  void read()
    {
        string input;
        cout << "Pleas enter your command\n";
        cin >> action;
        if (action == 'q' or action == 'h')
        {
            coordinates.release();
        }
        else
        {
            Coordinates new_coordinates;
            std::cin >> new_coordinates.x;
            std::cin >> new_coordinates.y;
            coordinates = make_unique<Coordinates>(new_coordinates);
        }
    }; */
};