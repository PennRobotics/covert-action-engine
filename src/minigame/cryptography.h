#include <algorithm>
#include <array>
#include <ctime>
#include <iostream>  // TODO-debug
#include <numeric>
#include <string>

#include "../types.h"
#include "minigame.h"

class MiniGameCryptography : public MiniGame {
public:
  MiniGameCryptography();  // TODO = default;
  virtual ~MiniGameCryptography();
  int start(Difficulty level);
  void draw() override;
private:
  void test_convert_message(const auto& key);
  time_t start_time;  // TODO
  std::string message;
  std::array<char, 26> cipher_key;
  std::array<char, 26> decipher_key;
  std::array<char, 26> user_decipher{};
  std::array<unsigned int, 26> letter_counts;
};

