#include <string>
#include <unordered_map>
#include <vector>

struct FontChar {
  std::vector<unsigned char> vrows;
};

static std::unordered_map<char, FontChar> alphabet;

static std::string outputrow[8];

void render_char_ascii(char);
void endl_ascii();

int createFontTable() {
  alphabet.reserve(70);
  alphabet['A'].vrows = {0x0E,0x38,0xC8,0xC8,0x38,0x0E,0};
  alphabet['B'].vrows = {0xBE,0x92,0x92,0x92,0x92,0x6C,0};
  alphabet['C'].vrows = {0x38,0x44,0x82,0x82,0x82,0x82,0};
  alphabet['D'].vrows = {0xBE,0x82,0x82,0x82,0x44,0x38,0};
  alphabet['E'].vrows = {0xBE,0x92,0x92,0x92,0x92,0x92,0};
  alphabet['F'].vrows = {0xBE,0x90,0x90,0x90,0x90,0x90,0};
  alphabet['G'].vrows = {0x38,0x44,0x82,0x92,0x92,0x94,0};
  alphabet['H'].vrows = {0xFE,0x10,0x10,0x10,0x00,0xFE,0};
  alphabet['I'].vrows = {0x82,0xBE,0x82,0};
  alphabet['J'].vrows = {0x02,0x02,0x82,0xBC,0x80,0};
  alphabet['K'].vrows = {0xFE,0x00,0x10,0x28,0x44,0x82,0};
  alphabet['L'].vrows = {0xFE,0x02,0x02,0x02,0x02,0x02,0};
  alphabet['M'].vrows = {0xBE,0x80,0x80,0x7E,0x80,0x80,0x7E,0};
  alphabet['N'].vrows = {0xBE,0x80,0x80,0x80,0x80,0x7E,0};
  alphabet['O'].vrows = {0x7C,0x82,0x82,0x82,0x82,0x7C,0};
  alphabet['P'].vrows = {0xBE,0x90,0x90,0x90,0x90,0x60,0};
  alphabet['Q'].vrows = {0x7C,0x82,0x82,0x83,0x81,0x7D,0};
  alphabet['R'].vrows = {0xBE,0x90,0x90,0x90,0x90,0x6E,0};
  alphabet['S'].vrows = {0x42,0xA2,0x92,0x8A,0x84,0};
  alphabet['T'].vrows = {0x80,0x80,0xBE,0x80,0x80,0};
  alphabet['U'].vrows = {0xFC,0x02,0x02,0x02,0x02,0xFE,0};
  alphabet['V'].vrows = {0xE0,0x18,0x06,0x06,0x18,0xE0,0};
  alphabet['W'].vrows = {0xF0,0x0E,0x30,0xC0,0x30,0x0E,0xF0,0};
  alphabet['X'].vrows = {0x82,0x44,0x30,0x18,0x44,0x82,0};
  alphabet['Y'].vrows = {0xE2,0x12,0x12,0x12,0x14,0xF8,0};
  alphabet['Z'].vrows = {0x86,0x8A,0x92,0xA2,0x82,0x82,0};
  alphabet['a'].vrows = {0x1C,0x22,0x22,0x20,0x3E,0};
  alphabet['b'].vrows = {0xFE,0x02,0x22,0x22,0x1C,0};
  alphabet['c'].vrows = {0x1C,0x22,0x22,0x22,0x22,0};
  alphabet['d'].vrows = {0x1C,0x22,0x22,0x02,0xFE,0};
  alphabet['e'].vrows = {0x1C,0x22,0x2A,0x32,0x22,0};
  alphabet['f'].vrows = {0x7E,0x90,0x90,0x90,0};
  alphabet['g'].vrows = {0x19,0x25,0x25,0x21,0x3E,0};
  alphabet['h'].vrows = {0xFE,0x00,0x20,0x20,0x1E,0};
  alphabet['i'].vrows = {0xBE,0};
  alphabet['j'].vrows = {0x01,0x01,0xBE,0};
  alphabet['k'].vrows = {0xFE,0x00,0x08,0x14,0x22,0};
  alphabet['l'].vrows = {0xFE,0};
  alphabet['m'].vrows = {0x3E,0x20,0x20,0x1E,0x20,0x20,0x1E,0};
  alphabet['n'].vrows = {0x3E,0x00,0x20,0x20,0x1E,0};
  alphabet['o'].vrows = {0x1C,0x22,0x22,0x22,0x1C,0};
  alphabet['p'].vrows = {0x3F,0x20,0x22,0x22,0x1C,0};
  alphabet['q'].vrows = {0x1C,0x22,0x22,0x20,0x3F,0};
  alphabet['r'].vrows = {0x1E,0x20,0x20,0x20,0};
  alphabet['s'].vrows = {0x12,0x2A,0x2A,0x2A,0x24,0};
  alphabet['t'].vrows = {0xFC,0x22,0x22,0x22,0};
  alphabet['u'].vrows = {0x3C,0x02,0x02,0x02,0x3C,0};
  alphabet['v'].vrows = {0x38,0x04,0x02,0x04,0x38,0};
  alphabet['w'].vrows = {0x3C,0x02,0x02,0x3C,0x02,0x02,0x3E,0};
  alphabet['x'].vrows = {0x22,0x14,0x08,0x14,0x22,0};
  alphabet['y'].vrows = {0x39,0x05,0x06,0x04,0x38,0};
  alphabet['z'].vrows = {0x22,0x26,0x2A,0x32,0x22,0};
  alphabet['0'].vrows = {0x7C,0x8A,0x92,0xA2,0x7C,0};
  alphabet['1'].vrows = {0x40,0x80,0xFE,0};
  alphabet['2'].vrows = {0x8A,0x92,0x92,0x92,0x62,0};
  alphabet['3'].vrows = {0x82,0x92,0x92,0xD2,0x8C,0};
  alphabet['4'].vrows = {0x10,0x30,0x50,0xD6,0x10,0};
  alphabet['5'].vrows = {0xB2,0x92,0x92,0x92,0x8C,0};
  alphabet['6'].vrows = {0x1C,0x62,0x92,0x12,0x0C,0};
  alphabet['7'].vrows = {0x80,0x86,0x98,0xA0,0x80,0};
  alphabet['8'].vrows = {0x6C,0x92,0x82,0x92,0x6C,0};
  alphabet['9'].vrows = {0x60,0x90,0x92,0x8C,0x70,0};
  alphabet[' '].vrows = {0,0,0,0,0,0,0};
  alphabet['.'].vrows = {0x06,0x06,0};
  alphabet[','].vrows = {0x06,0x07,0};
  alphabet[':'].vrows = {0x36,0x36,0};
  alphabet['/'].vrows = {0x06,0x08,0x10,0x20,0xC0,0};
  alphabet['!'].vrows = {0xF6,0};
  alphabet['@'].vrows = {0x0C,0x12,0x1E,0x02,0x3C,0x12,0};
  alphabet['#'].vrows = {0x24,0x6E,0x6E,0x24,0x6E,0x24,0};
  alphabet['$'].vrows = {0x24,0x54,0x54,0xD6,0x54,0x48,0};
alphabet['%'].vrows = {0xAA,0x55,0xAA,0x55,0xAA,0x55,0};
alphabet['"'].vrows = {0xAA,0x55,0xAA,0x55,0xAA,0x55,0};
alphabet['&'].vrows = {0xAA,0x55,0xAA,0x55,0xAA,0x55,0};
alphabet['*'].vrows = {0xAA,0x55,0xAA,0x55,0xAA,0x55,0};
alphabet['('].vrows = {0xAA,0x55,0xAA,0x55,0xAA,0x55,0};
alphabet[')'].vrows = {0xAA,0x55,0xAA,0x55,0xAA,0x55,0};
alphabet['_'].vrows = {0xAA,0x55,0xAA,0x55,0xAA,0x55,0};
alphabet['+'].vrows = {0xAA,0x55,0xAA,0x55,0xAA,0x55,0};
alphabet['-'].vrows = {0xAA,0x55,0xAA,0x55,0xAA,0x55,0};
alphabet['='].vrows = {0xAA,0x55,0xAA,0x55,0xAA,0x55,0};
// TODO: add remaining symbols
  alphabet['\''].vrows= {0xC0,0xE0,0};

  for (char c : "ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
    render_char_ascii(c);
  }
  endl_ascii();

  for (char c : "abcdefghijklmnopqrstuvwxyz") {
    render_char_ascii(c);
  }
  endl_ascii();

  for (char c : "0123456789 .,/?\'\":;") {
    render_char_ascii(c);
  }
  endl_ascii();

  for (char c : "!@#$%^&*()_+-=[]{}<>~`") {
    render_char_ascii(c);
  }
  endl_ascii();

  return 0;
}

void render_char_ascii(char c) {
  for (auto& vrow : alphabet[c].vrows) {
    for (int i = 0; i < 8; ++i) {
      outputrow[i] += (vrow & (0x80>>i)) ? "█" : " ";
    }
  }
}

void endl_ascii() {
  for (int i = 0; i < 8; ++i) {
    /// std::cout << outputrow[i] << std::endl;
    outputrow[i].clear();
  }
}
