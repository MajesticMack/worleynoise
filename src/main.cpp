#include "worleygen.h"
#include <filesystem>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <string>

int main(int argc, char** argv)
{
  int Width = 1024;
  int Height = 1024;
  WorleyGenerator Generator(Width, Height);
  std::vector<uint8_t> PixMap = Generator.Generate(10, 50);
  std::filesystem::path Filepath = std::filesystem::current_path();
  Filepath /= "worleynoise.png";
  std::string Filename = Filepath.string();

  stbi_write_png(Filename.c_str(), Width, Height, 1, PixMap.data(), Width);
  return 0;
}
