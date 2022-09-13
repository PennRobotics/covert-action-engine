#ifndef CA_TYPES_H
#define CA_TYPES_H

#include <string>

enum class Aptitude : int {
    Average   = -1,
    Good      =  0,
    Excellent =  1,
    Awesome   =  2,
};

enum class Difficulty : int {
  Level1 = 1,
  Level2 = 2,
  Level3 = 3,
  Level4 = 4
};

enum class MiniGameType : int {
  Combat,
  Driving,
  Crypto,
  Elec,
  Inactive = 0,
};

enum class GameScreen : int {
  Splash1,
  Splash2,
  BeginMenu,
  NewCharacter,
  Load,
  SkillPractice,
  HallOfFame,
  SkillUpgrade,
  Chief,
  MastermindLineup,
  ShowNewClues,
  CIAContact,
  CIAMainMenu,
  CIAData,
  ReviewClues,
  ReviewSuspects,
  ReviewInsideInfo,
  ReviewNews,
  ReviewOrg,
  ReviewCity,
  ReviewActivity,
  CIAIntel,
  ReviewWiretaps,
  CIASam,
  CIACrypto,
  CodedMessages,
  CrimeChronology,
  CIABanned,
  CityMainMenu,
  Airport,
  Hotel,
  LoadSave,
  Building1,
  Building2,
  Building3,
  Building4,
  Building5,
  CombatArrest,
  CombatRecover,
  CombatCaptive,
  Typewriter,
  GameExit,
  MiniGameCombatStart,
  MiniGameDrivingStart,
  MiniGameCryptoStart,
  MiniGameElecStart,
  UNKNOWN = -1,
};

enum class OriginScreen : int {
  ChiefCaseIntro,
  ChiefInfoHandout,
  ChiefKickMaxOut,
  CIA,
  CityMenu,
  UNKNOWNORIGIN = -1,
};

enum class ScreenExitCondition {
    Lose = -1,
    None = 0,
    Win = 1,
    Arrest,
    Shot,
};

enum class AtlasAlignment {
  TEXT_R,
  TEXT_L,
  TEXT_x,  // TODO: remove
};

struct City {
  std::string name;
  std::string country;
  int x;
  int y;
  AtlasAlignment align;
};

enum class Org {
  TODO,  // TODO
};

enum class Image {
  TODO,  // TODO
};

enum class Mastermind {
  TODO,  // TODO
};

#endif
