#include "utest.h"

UTEST_MAIN();

UTEST(cae, test_utest) {
    ASSERT_TRUE(1);
}

#include "../src/disk/loadsave.h"
UTEST(cae, disk_loadsave) {
///     EXPECT_EQ((int)FileStatus::Ok, (int)load_game(0));
///     EXPECT_EQ((int)FileStatus::Ok, (int)save_game("savetest.deleteme"));
///     EXPECT_EQ((int)FileStatus::NotFound, (int)load_game(4));
}

//*
#include "../src/gameplay/gamestate.h"
#include "../src/covert.h"
UTEST(cae, difficulty_calculation) {
  mainChar = std::make_unique<MainChar>();

  gameState = std::make_unique<GameState>();
  gameState->initMiniGameClasses();

  gui = std::make_unique<GUI>();

  // Electronics
  mainChar->setSkillLevels(Aptitude::Average, Aptitude::Average, Aptitude::Average, Aptitude::Average);
  gameState->setGameDifficulty(Difficulty::Level1); EXPECT_EQ((int)Difficulty::Level1, (int)Difficulty::Level1);
/* mGameElec->getGameDifficulty()
  gs->setGameDifficulty(Difficulty::Level2); EXPECT_EQ((int)mGameElec->getGameDifficulty(), (int)Difficulty::Level3);
  gs->setGameDifficulty(Difficulty::Level3); EXPECT_EQ((int)mGameElec->getGameDifficulty(), (int)Difficulty::Level4);
  gs->setGameDifficulty(Difficulty::Level4); EXPECT_EQ((int)mGameElec->getGameDifficulty(), (int)Difficulty::Level4);

  mc->setSkillLevels(Aptitude::Average, Aptitude::Average, Aptitude::Average, Aptitude::Good);
  gs->setGameDifficulty(Difficulty::Level1); EXPECT_EQ((int)mGameElec->getGameDifficulty(), (int)Difficulty::Level1);
  gs->setGameDifficulty(Difficulty::Level2); EXPECT_EQ((int)mGameElec->getGameDifficulty(), (int)Difficulty::Level2);
  gs->setGameDifficulty(Difficulty::Level3); EXPECT_EQ((int)mGameElec->getGameDifficulty(), (int)Difficulty::Level3);
  gs->setGameDifficulty(Difficulty::Level4); EXPECT_EQ((int)mGameElec->getGameDifficulty(), (int)Difficulty::Level4);

  mc->setSkillLevels(Aptitude::Average, Aptitude::Average, Aptitude::Average, Aptitude::Excellent);
  gs->setGameDifficulty(Difficulty::Level1); EXPECT_EQ((int)mGameElec->getGameDifficulty(), (int)Difficulty::Level1);
  gs->setGameDifficulty(Difficulty::Level2); EXPECT_EQ((int)mGameElec->getGameDifficulty(), (int)Difficulty::Level1);
  gs->setGameDifficulty(Difficulty::Level3); EXPECT_EQ((int)mGameElec->getGameDifficulty(), (int)Difficulty::Level2);
  gs->setGameDifficulty(Difficulty::Level4); EXPECT_EQ((int)mGameElec->getGameDifficulty(), (int)Difficulty::Level3);

  mc->setSkillLevels(Aptitude::Average, Aptitude::Average, Aptitude::Average, Aptitude::Awesome);
  gs->setGameDifficulty(Difficulty::Level1); EXPECT_EQ((int)mGameElec->getGameDifficulty(), (int)Difficulty::Level1);
  gs->setGameDifficulty(Difficulty::Level2); EXPECT_EQ((int)mGameElec->getGameDifficulty(), (int)Difficulty::Level1);
  gs->setGameDifficulty(Difficulty::Level3); EXPECT_EQ((int)mGameElec->getGameDifficulty(), (int)Difficulty::Level1);
  gs->setGameDifficulty(Difficulty::Level4); EXPECT_EQ((int)mGameElec->getGameDifficulty(), (int)Difficulty::Level2);

  // Driving
  MiniGameDriving mgd;
  mc->setSkillLevels(Aptitude::Average, Aptitude::Average, Aptitude::Average, Aptitude::Average);
  gs->setGameDifficulty(Difficulty::Level1); EXPECT_EQ((int)mgd.getGameDifficulty(), (int)Difficulty::Level1);
  gs->setGameDifficulty(Difficulty::Level2); EXPECT_EQ((int)mgd.getGameDifficulty(), (int)Difficulty::Level3);
  gs->setGameDifficulty(Difficulty::Level3); EXPECT_EQ((int)mgd.getGameDifficulty(), (int)Difficulty::Level4);
  gs->setGameDifficulty(Difficulty::Level4); EXPECT_EQ((int)mgd.getGameDifficulty(), (int)Difficulty::Level4);

  mc->setSkillLevels(Aptitude::Average, Aptitude::Average, Aptitude::Good, Aptitude::Average);
  gs->setGameDifficulty(Difficulty::Level1); EXPECT_EQ((int)mgd.getGameDifficulty(), (int)Difficulty::Level1);
  gs->setGameDifficulty(Difficulty::Level2); EXPECT_EQ((int)mgd.getGameDifficulty(), (int)Difficulty::Level2);
  gs->setGameDifficulty(Difficulty::Level3); EXPECT_EQ((int)mgd.getGameDifficulty(), (int)Difficulty::Level3);
  gs->setGameDifficulty(Difficulty::Level4); EXPECT_EQ((int)mgd.getGameDifficulty(), (int)Difficulty::Level4);

  mc->setSkillLevels(Aptitude::Average, Aptitude::Average, Aptitude::Excellent, Aptitude::Average);
  gs->setGameDifficulty(Difficulty::Level1); EXPECT_EQ((int)mgd.getGameDifficulty(), (int)Difficulty::Level1);
  gs->setGameDifficulty(Difficulty::Level2); EXPECT_EQ((int)mgd.getGameDifficulty(), (int)Difficulty::Level1);
  gs->setGameDifficulty(Difficulty::Level3); EXPECT_EQ((int)mgd.getGameDifficulty(), (int)Difficulty::Level2);
  gs->setGameDifficulty(Difficulty::Level4); EXPECT_EQ((int)mgd.getGameDifficulty(), (int)Difficulty::Level3);

  mc->setSkillLevels(Aptitude::Average, Aptitude::Average, Aptitude::Awesome, Aptitude::Average);
  gs->setGameDifficulty(Difficulty::Level1); EXPECT_EQ((int)mgd.getGameDifficulty(), (int)Difficulty::Level1);
  gs->setGameDifficulty(Difficulty::Level2); EXPECT_EQ((int)mgd.getGameDifficulty(), (int)Difficulty::Level1);
  gs->setGameDifficulty(Difficulty::Level3); EXPECT_EQ((int)mgd.getGameDifficulty(), (int)Difficulty::Level1);
  gs->setGameDifficulty(Difficulty::Level4); EXPECT_EQ((int)mgd.getGameDifficulty(), (int)Difficulty::Level2);
// */
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