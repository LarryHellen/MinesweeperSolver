#include "Controller.h"
#include "View.h"

int main()
{
    Model m;
    View v(&m);
    Controller c(&m, &v);


    sf::RenderWindow& window = v.window;
    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        v.step();
    }

    return 0;
}