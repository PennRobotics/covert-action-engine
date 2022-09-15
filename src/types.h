#ifndef CA_TYPES_H
#define CA_TYPES_H

#include <functional>
#include <string>

enum class DialogType {
  INFOTIMER,
  INFO,
  MENU,
  MINIMENU,
  TEXTENTRY,
  SKILLSELECT,
  MINIGAME,
};

struct GfxFns {
    std::function<void()> drawBG = [](){};
    std::function<void()> drawBox = [](){};
    std::function<void()> drawText = [](){};
    std::function<void()> drawImage = [](){};
    std::function<void()> drawAnimation = [](){};
    std::function<void()> drawSprite = [](){};
};


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
  CIABanned,
  ReviewWiretaps,
  CIASam,
  CIACrypto,
  CodedMessages,
  CrimeChronology,
  CityMainMenu,
  Airport,
  Hotel,
  LoadSave,
  Building1,
  Building2,
  Building3,
  Building4,
  Building5,
  Typewriter,
  MiniGameCombatStart,
  CombatArrest,
  CombatRecover,
  CombatCaptive,
  MiniGameDrivingStart,
  DrivingCarSelect,
  MiniGameCryptoStart,
  MiniGameElecStart,
  GameExit,
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

enum class MidiFile {
  Intro,  // TODO
};

#endif
