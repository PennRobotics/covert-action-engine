#pragma once

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
  /// CIABanned,  // TODO: Is there a separate screen for trying to access the CIA office after being banned?
  CIAAddBan,
  ReviewWiretaps,
  CIASam,
  CIACrypto,
  CodedMessages,
  CrimeChronology,
  CityMainMenu,
  Airport,
  Hotel,
    HotelLoungeModal,
  NewGameMaybe,  // TODO: figure out correct name and group appropriately (probably duplicated)
    HotelSleepThruCase,
  LoadSave,
  Building1,  // TODO: replace with a single Building screen and condition for building type
  Building2,
  Building3,
  Building4,
  Building5,
    BuildingWatch,
  Typewriter,
  MiniGameCombatStart,
    CombatArrest,
    CombatRecover,
    CombatCaptive,
  MiniGameDrivingStart,
    DrivingCarSelect,
    DrivingArrest,
    DrivingTargetGone,
    DrivingShootout,
    DrivingEscapedPursuer,
  MiniGameCryptoStart,
  MiniGameElecStart,
    ElecModalBugged,
    ElecModalTrace,
    ElecModalAlarm,
  GameExitModal,
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
    Intercepted,
    PhoneBugged,
    CarTraced,
    Timeout,
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

struct Face {
    uint8_t gender_id;
    uint8_t hair_id;
    uint8_t eye_id;
    uint8_t skin_id;
    uint8_t clothing_id;
    uint8_t accessory_id;
};

using callsign_t = std::string;
using city_t = std::vector<uint8_t>;  // TODO: change this type and all below
using org_t = std::vector<uint8_t>;
using rank_t = std::vector<uint8_t>;
using role_t = std::vector<uint8_t>;
using casedata_t = std::vector<uint8_t>;

struct Agent {
    callsign_t Name;
    Face Photo;
    city_t Location;
    org_t Affiliation;
    rank_t Rank;
    role_t Role;
    city_t RecruitedIn;
    Agent* RecruitedBy;
    casedata_t Data;
};
