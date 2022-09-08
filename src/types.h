#ifndef __TYPES_H
#define __TYPES_H

enum class Aptitude {
    Average   = -1,
    Good      =  0,
    Excellent =  1,
    Awesome   =  2,
};

enum class Difficulty {
  Level1 = 1,
  Level2 = 2,
  Level3 = 3,
  Level4 = 4
};

enum class MiniGameType {
  Combat,
  Driving,
  Crypto,
  Elec,
  Inactive,
};

enum class GameScreen {
    Splash1,
    Splash2,
    CityMainMenu,
    Building1,
    Building2,
    Building3,
    Building4,
    Building5,
    Chief,
    CIAMain,
    CIAData,
    CIAIntel,
    CIASam,
    CIACrypto,
    CombatArrest,
    CombatRecover,
    CombatCaptive,
    Hotel,
    LoadSave,
    ReviewClues,
    ReviewSuspects,
    ReviewInsideInfo,
    ReviewNews,
    ReviewOrg,
    ReviewCity,
    ReviewActivity,
    Typewriter,
    GameExit,
};

enum class ScreenExitCondition {
    Lose = -1,
    None = 0,
    Win = 1,
    Arrest,
    Shot,
};

#endif
