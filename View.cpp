#include "View.h"

View::View(Model* model) : _model(model), window(sf::VideoMode(720, 720), "Minesweeper")
{
    window.setFramerateLimit(60);
}


void View::step()
{
    sf::Texture texture;
    if (!texture.loadFromFile("minesweep_cut.png"))
        exit(1);

    SpriteSheetCutter m(texture, 11, 12);

    if(HAS_DELAY)
    sf::sleep(sf::milliseconds(DELAY));

    window.clear();


    const auto& nodes = _model->getNodes();
    int cellSize = 720 / _model->getRows();

    for (int row = 0; row < _model->getRows(); row++)
    {
        for (int col = 0; col < _model->getCols(); col++)
        {
            /*if (nodes[row][col].hasFlag() && nodes[row][col].isBomb())
            {
                m.set(0, 10);
                //m.setColor(sf::Color::White);
            } else if (nodes[row][col].isBomb())
            {
                m.set(0,6);
            } else*/ if(nodes[row][col].hasFlag())
            {
                m.set(0,2);
            } else
            {
                int neighbors = nodes[row][col].getNeighbors();

                if (neighbors == 0)
                {
                    m.set(0, 0);
                } else
                {
                    m.set(1, neighbors - 1);
                }

                if (nodes[row][col].is_is_selected())
                {
                    m.setColor(sf::Color(255, 165, 0, 150));
                }
                else
                {
                    m.setColor(sf::Color::White);
                }
            }

            m.setPosition(col * cellSize, row * cellSize);
            window.draw(m);
        }
    }

    window.display();
}