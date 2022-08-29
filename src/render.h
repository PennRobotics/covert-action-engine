enum class Color {  /* TODO: double-check enum class assignment */
  BLACK = 0,
  DKRED = 1,
  DKGREEN = 2,
  BROWN = 3,
  DKBLUE = 4,
  UNK = 5,  /*TODO*/
  DKCYAN = 6,
  GREY = 7,
  DKGREY = 8,  /*TODO: transposed light and dark? */
  RED = 9,
  GREEN = 10
  YELLOW = 11,
  BLUE = 12,
  MAGENTA = 13,
  CYAN = 14,
  WHITE = 15,
};

void render_bg(Color c);
void render_text(uint16_t x, uint16_t y, const std::string text, Color c);
void render_bar(uint16_t x, uint16_t y, uint16_t w, uint16_t h, Color c);
