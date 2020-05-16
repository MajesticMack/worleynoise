#include "worleygen.h"
#include <random>
#include <queue>
#include <math.h>

float Distance(float X1, float Y1, float X2, float Y2)
{
  return sqrt(pow(X2 - X1, 2) + pow(Y2 - Y1, 2));
}
WorleyGenerator::WorleyGenerator(int NoisewWidth, int NoiseHeight)
  : Width(NoisewWidth), Height(NoiseHeight)
{

}

std::vector<Point> WorleyGenerator::GeneratePoints(unsigned int Num, unsigned int Seed)
{
  std::vector<Point> Points;
  Points.resize(Num);

  std::default_random_engine Gen(Seed);
  std::uniform_real_distribution<> WidthDis(0.0, Width);
  std::uniform_real_distribution<> HeightDis(0.0, Height);
  for (unsigned int i = 0; i < Num; i++)
  {
    Points[i].X = (float)WidthDis(Gen);
    Points[i].Y = (float)HeightDis(Gen);
  }
  return Points;
}

std::vector<uint8_t> WorleyGenerator::Generate(unsigned int NumCells, unsigned int Seed)
{
  std::vector<Point> Points = GeneratePoints(NumCells, Seed);
  std::vector<uint8_t> PixMap;
  PixMap.resize(Width * Height);

  for (int i = 0; i < Height; i++)
  {
    for (int j = 0; j < Width; j++)
    {
      std::priority_queue<uint8_t, std::vector<uint8_t>, std::greater<uint8_t>> Distances;

      for (int k = 0; k < Points.size(); k++)
      {
        float Dist = Distance((float)j, (float)i, Points[k].X, Points[k].Y);
        Dist = 0.f + (Dist - 0.0f) * (255.f - 0.0f) / ((sqrt(pow((float)Width, 2) + pow((float)Height, 2))) - 0.0f);
        Distances.push((uint8_t)Dist);
      }
      PixMap[j + i * Height] = 255 - Distances.top();
    }
  }
  return PixMap;
}
