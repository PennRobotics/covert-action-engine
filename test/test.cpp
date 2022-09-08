#include "utest.h"
#include "../src/disk/loadsave.h"

UTEST_MAIN();

UTEST(cae, test_utest) {
    ASSERT_TRUE(1);
}

UTEST(cae, disk_loadsave) {
    EXPECT_EQ((int)FileStatus::Ok, (int)load_game(0));
    EXPECT_EQ((int)FileStatus::Ok, (int)save_game("savetest.deleteme"));
    EXPECT_EQ((int)FileStatus::NotFound, (int)load_game(4));
}

/*
UTEST(cae, gameplay_agentgenerator) {
    UTEST_SKIP("implement gameplay_agentgenerator test");
}

UTEST(cae, gameplay_case) {
    UTEST_SKIP("implement gameplay_case test");
}

UTEST(cae, gameplay_casegenerator) {
    UTEST_SKIP("implement gameplay_casegenerator test");
}

UTEST(cae, gameplay_discover) {
    UTEST_SKIP("implement gameplay_discover test");
}

UTEST(cae, gameplay_gamestate) {
    UTEST_SKIP("implement gameplay_gamestate test");
}

UTEST(cae, gameplay_time) {
    UTEST_SKIP("implement gameplay_time test");
}

UTEST(cae, gfx_gfx) {
    UTEST_SKIP("implement gfx_gfx test");
}

UTEST(cae, gfx_picloader) {
    UTEST_SKIP("implement gfx_picloader test");
}

UTEST(cae, gui_font) {
    UTEST_SKIP("implement gui_font test");
}

UTEST(cae, gui_gui) {
    UTEST_SKIP("implement gui_gui test");
}

UTEST(cae, gui_menu) {
    UTEST_SKIP("implement gui_menu test");
}

UTEST(cae, gui_point) {
    UTEST_SKIP("implement gui_point test");
}

UTEST(cae, minigame_combat) {
    UTEST_SKIP("implement minigame_combat test");
}

UTEST(cae, minigame_cryptography) {
    UTEST_SKIP("implement minigame_cryptography test");
}

UTEST(cae, minigame_driving) {
    UTEST_SKIP("implement minigame_driving test");
}

UTEST(cae, minigame_electronics) {
    UTEST_SKIP("implement minigame_electronics test");
}

UTEST(cae, minigame_minigame) {
    UTEST_SKIP("implement minigame_minigame test");
}

UTEST(cae, sound_fx) {
    UTEST_SKIP("implement sound_fx test");
}

UTEST(cae, sound_music) {
    UTEST_SKIP("implement sound_music test");
}

UTEST(cae, sound_sound) {
    UTEST_SKIP("implement sound_sound test");
}

UTEST(cae, covert) {
    UTEST_SKIP("implement covert test");
}

UTEST(cae, mission) {
    UTEST_SKIP("implement mission test");
}

UTEST(cae, types) {
    UTEST_SKIP("implement types test");
}
*/