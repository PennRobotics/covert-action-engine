#include <typeinfo>
#include "cryptography.h"

MiniGameCryptography::MiniGameCryptography() {
  std::cout << "CR\n";
}


int MiniGameCryptography::start(Difficulty level) {
  letter_counts.fill(0);
  user_decipher.fill(' ');

  // Create character array from Z to A.
  std::string ascii_base(26, ' ');
  std::iota(ascii_base.begin(), ascii_base.end(), 'A');
  std::reverse(ascii_base.begin(), ascii_base.end());

  std::srand(std::time(nullptr));  // RNG seed

  int cipher_idx = 0;
  for (auto& c : cipher_key) {
    // Shuffle when the next cipher letter matches the original letter or last cipher letter will be Z.
    while (cipher_idx == ascii_base.back() - 'A' || ascii_base[0] == 'Z') {
      std::random_shuffle(ascii_base.begin(), ascii_base.end());
    }

    c = ascii_base.back();  // Assign a cipher letter
    ascii_base.pop_back();
    decipher_key[c - 'A'] = 'A' + cipher_idx;  // Map the matching decipher letter
    cipher_idx++;
  }

  test_convert_message(cipher_key);

  return 0;
}


// TODO: on higher difficulties, unused letters are recycled so that high-freq letters (E, T, S) use two cipher characters. is this randomly chosen or predetermined??
// TODO: strip punctuation depending on difficulty
// TODO: when checking the message, any remaining letters are valid when letter_counts[...] is zero!


void MiniGameCryptography::test_convert_message(const auto& key) {
  int l = 0;
  // std::string test_msg = "AB. CA";
  std::string test_msg = "MI6 IS READY TO REWARD YOU FOR YOUR SUCCESS.  THE ALARM SYSTEM AT A LARGE INDUSTRIAL WAREHOUSE IS A BETA MODEL HUGHES ELECTROMASTER. THIS MONTHS ACCESS CODE WORD IS ROSEBUD.  OUT PROJECT HERE IN NASSAU PROCEEDS ON SCHEDULE. NONE DOUBT YOUR LOYALTY. WE ARE CONFIDENT YOUR WORK IN MEDELLIN WILL CONTINUE ON SCHEDULE. FELLOW WARRIORS OF THE FLN NOW IS THE TIME FOR ACTION.";
  // std::string test_msg = "OUR PROJECT HERE IN SAN JUAN PROCEEDS ON SCHEDULE I AM PLANNING TO VISIT MEDELLIN SHORTLY YOUR SUPPORT IS ESSENTIAL IN THIS OPERATION M18 IS READY TO REWARD YOU FOR YOUR SUCCESS WE WELCOME COOPERATION WITH THE HAITIAN JUNTA";
  static const unsigned int WRAP_LEN = 42;

  unsigned int lines = 1 + test_msg.length() / WRAP_LEN;

  // TODO: letter_counts is broken because it is being printed before being fully calculated. Push everything into a vector and replace letter_counts at the end.
  std::cout << user_decipher[l] << " " << (char)('A' + l) << " " << letter_counts[l] << "\n"; ++l;
  for (int line = 0; line < lines; ++line) {
    if (line != 0) {
      if (test_msg.substr(line * WRAP_LEN - 1, 2).find(' ') == std::string::npos)  { std::cout << "-"; }
      std::cout << "\n" << user_decipher[l] << " " << (char)('A' + l) << " " << letter_counts[l]; ++l;
      std::cout << "\n" << user_decipher[l] << " " << (char)('A' + l) << " " << letter_counts[l]; ++l;
      std::cout << std::endl;
    }

    // std::cout << decipher_key[l] << " " << (char)('A' + l) << " " << letter_counts[l] << std::endl;
    std::cout << user_decipher[l] << " " << (char)('A' + l) << " " << letter_counts[l] << "   "; ++l;

    for (auto& letter : test_msg.substr(line * WRAP_LEN, WRAP_LEN)) {
      if (letter < 'A' || letter > 'Z')  { std::cout << letter; continue; }
      auto idx = letter - 'A';
      std::cout << key[idx];
      letter_counts[key[idx] - 'A']++;
    }
  }
  while (l < 26) {
    std::cout << "\n" << user_decipher[l] << " " << (char)('A' + l) << " " << letter_counts[l]; ++l;
  }
  std::cout << std::endl;
}

MiniGameCryptography::~MiniGameCryptography()  {}

void MiniGameCryptography::draw() {
    // TODO
}




