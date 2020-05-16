#pragma once

#include <vector>
#include <stdint.h>

struct Point
{
  float X;
  float Y;
};

class WorleyGenerator
{
public:
  WorleyGenerator(int NoisewWidth, int NoiseHeight);

  std::vector<uint8_t> Generate(unsigned int NumCells, unsigned int Seed);

private:
  std::vector<Point> GeneratePoints(unsigned int Num, unsigned int Seed);

private:
  int Width;
  int Height;
  int CellCount;
};
