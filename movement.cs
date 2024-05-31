using System;

namespace matrix
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = 4, y = 4;
            Console.Title = "rougelike";
            string[,] matrix9x9 = new string[9,9];
 


            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    matrix9x9[i, j] = ".";
                }
            }

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (i == 0 || i == 8 || j == 0 || j == 8)
                    {
                        matrix9x9[i, j] = "#";
                    }
                }
            }

            matrix9x9[y, x] = "@";
            



            DrawMap();
            void DrawMap()
            {
                Console.Clear();
                for (Int32 iy = 0; iy < 9; iy += 1)
                {
                    for (Int32 ix = 0; ix < 9; ix += 1)
                    {
                        Console.Write(" {0}",matrix9x9[iy, ix]);
                    }

                    Console.WriteLine();
                }
            }

            while (true)
            {
                var key = Console.ReadKey().Key;
                if (key == ConsoleKey.UpArrow && matrix9x9[y - 1, x] == ".")
                {
                    matrix9x9[y, x] = ".";
                    matrix9x9[y -= 1, x] = "@";
                    DrawMap();
                }
                else if (key == ConsoleKey.DownArrow && matrix9x9[y + 1, x] == ".")
                {
                    matrix9x9[y, x] = ".";
                    matrix9x9[y += 1, x] = "@";
                    DrawMap();
                }
                else if (key == ConsoleKey.LeftArrow && matrix9x9[y, x - 1] == ".")
                {
                    matrix9x9[y, x] = ".";
                    matrix9x9[y, x -= 1] = "@";
                    DrawMap();
                }
                else if (key == ConsoleKey.RightArrow && matrix9x9[y, x + 1] == ".")
                {
                    matrix9x9[y, x] = ".";
                    matrix9x9[y, x += 1] = "@";
                    DrawMap();
                }
                else
                {
                    DrawMap();
                }




            }





            
        }
    }
}
