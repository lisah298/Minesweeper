#include <memory>
#include <string>
#include <iostream>
#include <string.h>

using Action = char;
using namespace std;
class Command
{

public:
    const Action get_action() const { return action; };
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
    };
    //setter
    void set_action(Action act)
    {
        action = act;
    };
    void read()
    {
        size_t x;
        size_t y;
        Action action;
        cout << "Please enter your command\n";
        cin >> action >> x >> y;
        set_action(action);
        if (action == 'q' or action == 'h')
        {
            coordinates.release();
        }
        else
        {
            Coordinates new_coordinates{x, y};
            coordinates = make_unique<Coordinates>(new_coordinates);
        }
        //clear console for next command
        //cin.unget();
    };
    bool validate(const GridSize &size) const
    {

        bool command;
        // 1. check whether the action is one of the supported actions
        if (action == 'q' || action == 'h' || action == 'r' || action == 'a' || action == 'd')
        {
            command = true;
            cout << "command is valid" << endl;
        }
        else
        {
            command = false;
            cout << "command is not valid" << endl;
            return false;
        }
        // 2. Check if the action needs coordinates
        if (action == 'h' || action == 'q' && coordinates == nullptr)
        {
            return true;
        }
        else if (action == 'r' || action == 'a' || action == 'd' && coordinates != nullptr)
        {
            if (get_coordinates().x <= size.rows && get_coordinates().y <= size.columns)
            {
                return true;
            }
            else
            {
                cout << "coordinates are not valid" << endl;
                return false;
            }
        }
        else if (action == 'r' || action == 'a' || action == 'd' && coordinates == nullptr)
        {
            return false;
        }
        else if (action == 'h' || action == 'q' && coordinates != nullptr)
        {
            return false;
        }
        else
        {
            cout << "Oops something went wrong";
        };

        // 3. Check if coordinates exist, they are valid -- belong to the grid
    }

private:
    Action action;
    unique_ptr<Coordinates> coordinates{nullptr};
    /* bool validate(const GridSize &size) const
    {
        bool command;
        bool coords;
        bool coords_needed;
        // 1. check whether the action is one of the supported actions
        if (action == 'q' || action == 'h' || action == 'r' || action == 'a' || action == 'd')
        {
            command = true;
        }
        else
        {
            command = false;
            return false;
        }
        // 2. Check if the action needs coordinates
        if (action == 'h' || action == 'q' && coordinates == nullptr)
        {
            return true;
        }
        else if (action == 'r' || action == 'a' || action == 'd' && coordinates != nullptr)
        { // 3. Check if coordinates exist, they are valid -- belong to the grid
            if (get_coordinates().x <= size.rows && get_coordinates().y <= size.columns)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (action == 'r' || action == 'a' || action == 'd' && coordinates == nullptr)
        {
            return false;
        }
        else if (action == 'h' || action == 'q' && coordinates != nullptr)
        {
            return false;
        }
        else
        {
            cout << "Oops something went wrong";
        };
    } */
};