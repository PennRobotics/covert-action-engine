/// #include <SDL.h>
typedef int SDL_Keysym;
typedef int SDL_Keycode;
#include <map>
#include <vector>

namespace kbd {
	std::map<SDL_Keysym, SDL_Keycode> keymap;
	std::vector<std::pair<SDL_Keysym, SDL_Keycode>> keypairs;

	void load_default_keymap() {
		for (auto& keypair : keypairs) {  // TODO: const
			keymap[keypair.second] = keypair.first;
		}
	}

}  /* namespace kbd */

int main() { kbd::load_default_keymap(); return 0; }

