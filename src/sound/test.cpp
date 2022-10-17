#include "lisyarus.h"
#include <map>

engine audio_;
mixer_ptr mixer_;
std::map<int, channel_ptr> channels_;

float smooth_pitch_ = 0.f;

clock<> clock_;
float time_ = 0.f;


int main() {
	mixer_ = make_mixer();
	mixer_->add(tone);  // TODO: tone
	audio_.output()->stream(mixer_);
}
