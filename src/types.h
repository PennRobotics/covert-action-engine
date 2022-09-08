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

#endif
