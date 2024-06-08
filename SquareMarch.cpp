// with help of @MAX-TS

#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

#define ARRAYSIZE(a) (sizeof(a) / sizeof(a[0]))


using namespace sf;
int clamp(int value, int min, int max)
{
    if (value > max)
    {
        return max;
    }
    else if (value < min)
    {
        return min;
    }
    else
    {
        return value;
    }
}
int TantumVERDO(int vert){
    return (vert + (vert % 2) * 16) / 2;
}

void DrawLine(RenderWindow& window, Vector2f pos1, Vector2f pos2)
{
	sf::VertexArray lines(sf::LinesStrip, 2);
    
	lines[0].position = sf::Vector2f(pos1);
	lines[1].position = sf::Vector2f(pos2);
    lines[1].color = Color::Green;
    lines[0].color = Color::Green;
    window.draw(lines);
    

}
void RenderCell(RenderWindow& window, int vert, Vector2f pos, int tile_size)
{
    
    //while (true)
    //{
    //    vert = TantumVERDO(vert);
    //    if (vert == 15 || vert == 7 || vert == 3 || vert == 1 || vert == 5 || vert == 0)
    //    {
    //        break;
    //    }
    //    //std::cout << vert << " ";
    //}
    //return vert;
    switch (vert)
    {
    case 1:
		DrawLine(window, { pos.x + tile_size / 2, pos.y + tile_size }, { pos.x, pos.y + tile_size / 2 });
        break;
    case 2:
		DrawLine(window, { pos.x + tile_size, pos.y + tile_size / 2 }, { pos.x + tile_size / 2, pos.y + tile_size });
        break;
    case 3:
        DrawLine(window, { pos.x, pos.y + tile_size / 2 }, { pos.x + tile_size, pos.y + tile_size / 2 });
        break;
    case 4:
        DrawLine(window, { pos.x + tile_size / 2 , pos.y}, { pos.x + tile_size, pos.y + tile_size / 2 });
        break;
    case 5:
        DrawLine(window, { pos.x + tile_size / 2 , pos.y}, { pos.x + tile_size, pos.y + tile_size / 2 });
        DrawLine(window, { pos.x, pos.y + tile_size / 2 }, { pos.x + tile_size / 2, pos.y + tile_size });
        break;
    case 6:
        DrawLine(window, { pos.x + tile_size / 2 , pos.y}, { pos.x + tile_size / 2, pos.y + tile_size});
        break;
    case 7:
        DrawLine(window, { pos.x , pos.y + tile_size / 2}, { pos.x + tile_size / 2, pos.y});
        break;
    case 8:
        DrawLine(window, { pos.x , pos.y + tile_size / 2}, { pos.x + tile_size / 2, pos.y});
        break;
    case 9:
        DrawLine(window, { pos.x + tile_size / 2 , pos.y}, { pos.x + tile_size / 2, pos.y + tile_size});
        break;
    case 10:
        DrawLine(window, { pos.x + tile_size, pos.y + tile_size / 2 }, { pos.x + tile_size / 2 , pos.y });
        DrawLine(window, { pos.x + tile_size / 2, pos.y + tile_size }, { pos.x, pos.y + tile_size / 2 });
        
        
        
        
        break;

    case 11:
        DrawLine(window, { pos.x+tile_size/2, pos.y}, { pos.x + tile_size, pos.y + tile_size/2});
        break;

    case 12:
        DrawLine(window, { pos.x, pos.y + tile_size / 2 }, { pos.x + tile_size, pos.y + tile_size / 2 });
        break;
    case 13:
        DrawLine(window, { pos.x + tile_size / 2, pos.y + tile_size }, { pos.x + tile_size, pos.y + tile_size / 2 });
        break;
    case 14:
        DrawLine(window, { pos.x, pos.y + tile_size / 2 }, { pos.x + tile_size / 2, pos.y + tile_size});
        break;


    }
    
}
int main()
{
    int TILE_SIZE = 15;
    // std::cout << RenderCell(0) <<"\n";
    // std::cout << RenderCell(1) << "\n";
    // std::cout << RenderCell(2) << "\n";
    // std::cout << RenderCell(3) << "\n";
    // std::cout << RenderCell(4) << "\n";
    // std::cout << RenderCell(5) << "\n";
    // std::cout << RenderCell(6) << "\n";
    // std::cout << RenderCell(7) << "\n";
    // std::cout << RenderCell(8) << "\n";
    // std::cout << RenderCell(9) << "\n";
    // std::cout << RenderCell(10) << "\n";
    // std::cout << RenderCell(11) << "\n";
    // std::cout << RenderCell(12) << "\n";
    // std::cout << RenderCell(13) << "\n";
    // std::cout << RenderCell(14) << "\n";
    // std::cout << RenderCell(15) << "\n";
    /*int points[5][5] = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0}
    };*/

    int points[50][50];
    time_t rawtime;
    srand(time(&rawtime));
    for (int i = 0; i < ARRAYSIZE(points) - 1; i++)
    {
        
        for (int j = 0; j < ARRAYSIZE(points) - 1; j++)
        {
            
            std::cout<< rand()<<" ";
            int rnd =  rand() % 2;
            points[i][j] =  rnd;

            
        }
    }
    

    


    RenderWindow window(VideoMode(500,500),"Sigma", Style::Default);
    
    CircleShape shape(1,20);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
	window.setFramerateLimit(60);
    while (window.isOpen())
    {
        window.clear();
        
        
        for (int i = 0; i < ARRAYSIZE(points); i++)
        {
            for (int j = 0; j < ARRAYSIZE(points); j++)
            {

                if (points[i][j] == 1)
                {
                    shape.setFillColor(Color::Green);

                }
                else
                {
                    shape.setFillColor(Color::Black);
                }
                shape.setPosition(j * TILE_SIZE + shape.getRadius(), i * TILE_SIZE + shape.getRadius());
                window.draw(shape);

            }
        }
        
        
        
        for (int i = 0; i < ARRAYSIZE(points) -1; i++)
        {
            for (int j = 0; j < ARRAYSIZE(points) -1; j++)
            {
                
                
                //RenderCell(window, points[j][i+1] + 2*points[j+1][ i+1] + 4*points[j][i+1] + 8*points[j][i], Vector2f(j * 50 + 5, i * 50 + 5 ), 50);
                RenderCell(window, points[i+1][j] + 2 * points[i + 1][j + 1] + 4 * points[i][j + 1] + 8 * points[i][j], Vector2f(j * TILE_SIZE + shape.getRadius(), i * TILE_SIZE + shape.getRadius()), TILE_SIZE);
            }
        }

        
        
        
        
        
        
        Event event;
        while (window.pollEvent(event))
        {
            

            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::Resized)
            {
                sf::FloatRect Area(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(Area));
            }
            //DrawLine(window, { 50, 50 }, { 75, 75 });
        }




        window.display();
    }
    
   
}
