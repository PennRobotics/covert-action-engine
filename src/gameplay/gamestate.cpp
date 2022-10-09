#include "gamestate.h"



void GameState::initMiniGameClasses()
{
}


/*! \mainpage
 *
 *  Screen State Transition Chart
 *  \dot
 *  digraph GameScreenFSM {
 *    node [shape = ellipse];
 *
 *    Splash1;
 *    Splash2;
 *    BeginMenu;
 *    NewCharacter;
 *    Load;
 *    SkillPractice;
 *    HallOfFame;
 *    SkillUpgrade;
 *    Chief;
 *    MastermindLineup;
 *    ShowNewClues;
 *    CIAContact;
 *    CIAMainMenu;
 *    CIAData;
 *    Data;
 *    ReviewClues;
 *    ReviewSuspects;
 *    ReviewInsideInfo;
 *    ReviewNews;
 *    ReviewOrg;
 *    ReviewCity;
 *    ReviewActivity;
 *    CIAIntel;
 *    CIABanned;
 *    ReviewWiretaps;
 *    CIASam;
 *    CIACrypto;
 *    CodedMessages;
 *    CrimeChronology;
 *    CityMainMenu;
 *    Airport;
 *    Hotel;
 *    LoadSave;
 *    BuildingExterior;
 *    BuildingWatch;
 *    Typewriter;
 *    MiniGameCombatStart;
 *    CombatArrest;
 *    CombatRecover;
 *    CombatCaptive;
 *    MiniGameDrivingStart;
 *    DrivingCarSelect;
 *    MiniGameCryptoStart;
 *    MiniGameElecStart;
 *    GameExit;
 *
 *    node [shape = box3d];
 *
 *    Combat
 *    Driving
 *    Cryptography
 *    Electronics
 *
 *    Splash1 -> Splash2 -> BeginMenu -> {NewCharacter, Load, SkillPractice, HallOfFame};
 *    HallOfFame -> BeginMenu;
 *    SkillPractice -> {MiniGameCombatStart, MiniGameDrivingStart, MiniGameCryptoStart, MiniGameElecStart};
 *
 *    BuildingExterior -> {MiniGameElecStart, MiniGameCombatStart, BuildingWatch, Data, CityMainMenu};
 *    BuildingWatch -> {BuildingWatch, MiniGameDrivingStart, MiniGameElecStart, Data};
 *
 *    MiniGameCombatStart -> Combat;
 *    Combat -> {CombatArrest, CombatRecover, CombatCaptive, CityMainMenu, BeginMenu};
 *    MiniGameDrivingStart -> DrivingCarSelect -> Driving;
 *    MiniGameCryptoStart -> Cryptography;
 *    MiniGameElecStart -> Electronics;
 *
 *    NewCharacter -> SkillUpgrade -> Chief;
 *    Chief -> MastermindLineup;
 *    MastermindLineup -> Chief;
 *    Chief -> ShowNewClues -> CIAContact -> {CIASam, CIAMainMenu};
 *
 *    CIAMainMenu -> {CIAData, CIAIntel, CIACrypto};
 *    CIAData -> {ReviewClues, ReviewSuspects, ReviewInsideInfo, ReviewNews, ReviewOrg, ReviewCity, ReviewActivity};
 *    Data -> {ReviewClues, ReviewSuspects, ReviewInsideInfo, ReviewNews, ReviewOrg, ReviewCity, ReviewActivity};
 *
 *    CityMainMenu -> {Airport, Hotel, CIAContact, CIABanned, BuildingObserve};
 *    Hotel -> {CityMenu, Load, GameExit}
 *  }
 *  \enddot
 */


#include <iostream>  // TODO-debug
void GameState::getNextScreen(ScreenExitCondition condition)
{
  // TODO: possibly clear `origScreen` and set an overrideable default

  if (this->inMiniGame) {
    switch (this->currentMiniGame) {
      case MiniGameType::Combat:
        if (condition == ScreenExitCondition::None)  { currentScreen = GameScreen::CityMainMenu; }
        if (condition == ScreenExitCondition::Arrest)  { currentScreen = GameScreen::CombatArrest; }
        if (condition == ScreenExitCondition::Shot)  { currentScreen = GameScreen::CombatRecover; }
        if (condition == ScreenExitCondition::Lose)  { currentScreen = GameScreen::CombatCaptive; }
        break;
      case MiniGameType::Driving:
        /// TODO: what happens when pressing <Esc>?
        /// if (condition == ScreenExitCondition::None)  { currentScreen = GameScreen::CityMainMenu; }
        if (condition == ScreenExitCondition::Arrest)  { currentScreen = GameScreen::DrivingArrest; }
        if (condition == ScreenExitCondition::Lose)  { currentScreen = GameScreen::DrivingTargetGone; }
        if (condition == ScreenExitCondition::Intercepted)  { currentScreen = GameScreen::DrivingShootout; }
        if (condition == ScreenExitCondition::Win)  { currentScreen = GameScreen::DrivingEscapedPursuer; }
        /// TODO: differentiate between 'hunter' and 'hunted' outcome
        break;
      case MiniGameType::Crypto:
        currentScreen = goBackFrom(origScreen);
        /* TODO: back to referrer. Are all clues handled by clue routine? */
        break;
      case MiniGameType::Elec:
        /// TODO: differentiate between 'trace' and 'phone bug'
        if (condition == ScreenExitCondition::None)  { /*TODO: back to prev menu? */ }
        if (condition == ScreenExitCondition::Timeout)  { /*TODO: back to prev menu? */ }
        if (condition == ScreenExitCondition::PhoneBugged)  { currentScreen = GameScreen::ElecModalBugged; }
        if (condition == ScreenExitCondition::CarTraced)  { currentScreen = GameScreen::ElecModalTrace; }
        if (condition == ScreenExitCondition::Lose)  { currentScreen = GameScreen::ElecModalAlarm; }
        break;
    }
  } else {  // this->inMiniGame is false
    switch (this->currentScreen) {
      case GameScreen::Splash1:
        currentScreen = GameScreen::Splash2;
        break;
      case GameScreen::Splash2:
        currentScreen = GameScreen::BeginMenu;
        break;
      case GameScreen::BeginMenu:
        std::cout << "Leaving menu, choice " << selectedChoice << " active." << std::endl;
        if (this->selectedChoice == 0 ||
            this->selectedChoice == 1)  { currentScreen = GameScreen::NewCharacter; }
        if (this->selectedChoice == 2)  { currentScreen = GameScreen::Load; }
        if (this->selectedChoice == 3)  { currentScreen = GameScreen::SkillPractice; }
        if (this->selectedChoice == 4)  { currentScreen = GameScreen::HallOfFame; }
        break;
      case GameScreen::Load:
        currentScreen = GameScreen::UNKNOWN;
        break;
      case GameScreen::SkillPractice:  // TODO
        (this->modalSequence)++;  // TODO: this double-increments currently (FIXME) using ENTER but not ESC
        std::cout << this->modalSequence << std::endl;
        // TODO: set origScreen to BeginMenu
        // TODO: how to deal with the transition from not in minigame into the minigame??
        if (this->modalSequence == 3) {
          if (this->selectedChoice == 1)  { currentScreen = GameScreen::MiniGameCombatStart; }
          if (this->selectedChoice == 2)  { currentScreen = GameScreen::MiniGameDrivingStart; }
          if (this->selectedChoice == 3)  { currentScreen = GameScreen::MiniGameCryptoStart; }
          if (this->selectedChoice == 4)  { currentScreen = GameScreen::MiniGameElecStart; }
        }
        // TODO: default?
        break;
      case GameScreen::HallOfFame:  // TODO
        currentScreen = GameScreen::UNKNOWN;
        break;
      case GameScreen::NewCharacter:
        (this->modalSequence)++;
        if (this->modalSequence > 3)  { currentScreen = GameScreen::SkillUpgrade; }
        break;
      case GameScreen::SkillUpgrade:
        (this->modalSequence)++;
        if (this->modalSequence > 4) {
          this->origScreen = OriginScreen::ChiefCaseIntro;
          currentScreen = GameScreen::Chief;
        }
        break;
      case GameScreen::Chief:
        if (this->origScreen == OriginScreen::ChiefCaseIntro)  { currentScreen = GameScreen::MastermindLineup; }
        if (this->origScreen == OriginScreen::ChiefInfoHandout) {
          this->isTwelve = true;
          currentScreen = GameScreen::ShowNewClues;
        }
        if (this->origScreen == OriginScreen::ChiefKickMaxOut)  { currentScreen = GameScreen::CIAContact; }
        break;
      case GameScreen::MastermindLineup:
        this->origScreen = OriginScreen::ChiefInfoHandout;
        currentScreen = GameScreen::Chief;
        break;
      case GameScreen::ShowNewClues:
        // TODO: when clues and updates (messages, etc.) are finished, set isTwelve to false
        if (this->origScreen == OriginScreen::ChiefInfoHandout) {
          this->origScreen = OriginScreen::ChiefKickMaxOut;
          currentScreen = GameScreen::Chief;
        }
        if (this->origScreen == OriginScreen::CIA) {
          currentScreen = GameScreen::CIAIntel; /* TODO: make sure new clues at 12 during crypto do not jump here! */
        }
        break;
      case GameScreen::CIAContact:
        this->origScreen = OriginScreen::CIA;
        currentScreen = GameScreen::CIASam;
        break;
      case GameScreen::CIAMainMenu:
        if (this->selectedChoice == 0)  { currentScreen = GameScreen::CityMainMenu; }
        if (this->selectedChoice == 1)  { currentScreen = GameScreen::CIAData; }
        if (this->selectedChoice == 2)  { currentScreen = GameScreen::CIAIntel; }
        if (this->selectedChoice == 3)  { currentScreen = GameScreen::CIACrypto; }
        break;
      case GameScreen::CIAData:
        if (this->selectedChoice == 0)  { currentScreen = GameScreen::CIAMainMenu; }
        if (this->selectedChoice == 1)  { currentScreen = GameScreen::ReviewClues; }
        if (this->selectedChoice == 2)  { currentScreen = GameScreen::ReviewSuspects; }
        if (this->selectedChoice == 3)  { currentScreen = GameScreen::ReviewInsideInfo; }
        if (this->selectedChoice == 4)  { currentScreen = GameScreen::ReviewNews; }
        if (this->selectedChoice == 5)  { currentScreen = GameScreen::ReviewOrg; }
        if (this->selectedChoice == 6)  { currentScreen = GameScreen::ReviewCity; }
        if (this->selectedChoice == 7)  { currentScreen = GameScreen::ReviewActivity; }
      case GameScreen::CIAIntel:
        if (this->selectedChoice == 0)  { currentScreen = GameScreen::CIAMainMenu; }
        if (this->selectedChoice == 1 ||
            this->selectedChoice == 2)  { currentScreen = GameScreen::ShowNewClues; }
        if (this->selectedChoice == 3)  { currentScreen = GameScreen::ReviewWiretaps; }
        if (this->selectedChoice == 4) {
          // TODO: check if current office has double agent
          if (0) {
            // TODO: DA found!
          } else {
            currentScreen = GameScreen::CIAAddBan;
          }
        }
        if (this->selectedChoice == 5)  { currentScreen = GameScreen::CIASam; }
        break;
      case GameScreen::CIASam:
        currentScreen = GameScreen::CIAMainMenu;
        break;
      case GameScreen::CIACrypto:
        if (this->selectedChoice == 0)  { currentScreen = GameScreen::CIAMainMenu; }
        if (this->selectedChoice == 1)  { currentScreen = GameScreen::CodedMessages; }
        if (this->selectedChoice == 2)  { currentScreen = GameScreen::CrimeChronology; }
        // TODO
        break;
      case GameScreen::CodedMessages:
        break;
      case GameScreen::CrimeChronology:
        break;
      case GameScreen::CIAAddBan:
        currentScreen = GameScreen::CityMainMenu;
        break;
      case GameScreen::CityMainMenu:
        // TODO: airport, hotel, ..., data
        break;
      case GameScreen::Airport:
        /* TODO: show animation */
        /* TODO: change current city */
        currentScreen = GameScreen::CityMainMenu;
        break;
      case GameScreen::Hotel:
        // TODO: double check order
        // TODO: double check <Esc> case
        if (this->selectedChoice == 0)  { currentScreen = GameScreen::CityMainMenu; }
        if (this->selectedChoice == 1)  { currentScreen = GameScreen::HotelLoungeModal; }
        if (this->selectedChoice == 2)  { currentScreen = GameScreen::CityMainMenu; }
        if (this->selectedChoice == 3)  { currentScreen = GameScreen::LoadSave; }
        if (this->selectedChoice == 4)  { currentScreen = GameScreen::HotelSleepThruCase; }
        if (this->selectedChoice == 5)  { currentScreen = GameScreen::NewGameMaybe; }
        if (this->selectedChoice == 6)  { currentScreen = GameScreen::Hotel; }
        if (this->selectedChoice == 7)  { currentScreen = GameScreen::GameExitModal; }
        break;
      case GameScreen::LoadSave:
        break;
      case GameScreen::ReviewClues:
      case GameScreen::ReviewSuspects:
      case GameScreen::ReviewInsideInfo:
      case GameScreen::ReviewNews:
      case GameScreen::ReviewOrg:
      case GameScreen::ReviewCity:
      case GameScreen::ReviewActivity:
        currentScreen = goBackFrom(origScreen);
        break;
      case GameScreen::Building1:
      case GameScreen::Building2:
      case GameScreen::Building3:
      case GameScreen::Building4:
      case GameScreen::Building5:
        if (this->selectedChoice == 0)  { currentScreen = GameScreen::CityMainMenu; }
        if (this->selectedChoice == 1)  { currentScreen = GameScreen::MiniGameCombatStart; }
        if (this->selectedChoice == 2)  { currentScreen = GameScreen::MiniGameElecStart; }
        // TODO: watch should go back to the correct building
        if (this->selectedChoice == 3)  { currentScreen = GameScreen::BuildingWatch; }
        if (this->selectedChoice == 4)  { currentScreen = GameScreen::CityMainMenu; }
        if (this->selectedChoice == 5)  { currentScreen = GameScreen::TODO; }
        break;
      case GameScreen::CombatArrest:
        break;
      case GameScreen::CombatRecover:
        break;
      case GameScreen::CombatCaptive:
        break;
      case GameScreen::Typewriter:
        break;
      case GameScreen::GameExitModal:
        currentScreen = GameScreen::GameExit;
        break;
      case GameScreen::GameExit:
        break;
      case GameScreen::ReviewWiretaps:
        break;
      case GameScreen::MiniGameCombatStart:
        break;
      case GameScreen::MiniGameDrivingStart:
        break;
      case GameScreen::MiniGameCryptoStart:
        break;
      case GameScreen::MiniGameElecStart:
        break;
      case GameScreen::UNKNOWN:  // TODO
      default:
        currentScreen = GameScreen::GameExit;  // TODO
        break;
    }
  }
}


GameScreen goBackFrom(OriginScreen os)
{
  GameScreen gs;
  switch (os) {
    case OriginScreen::ChiefCaseIntro:
      break;
    case OriginScreen::ChiefInfoHandout:
      break;
    case OriginScreen::ChiefKickMaxOut:
      break;
    case OriginScreen::CIA:
      break;
    case OriginScreen::CityMenu:
      break;
    case OriginScreen::UNKNOWNORIGIN:
    default:
      break;
  }
}


void GameState::enterMiniGame(MiniGameType miniGame)
{
  /* TODO-debug
  this->currentMiniGame = miniGame;
  this->inMiniGame = true;
  switch (miniGame) {
    case MiniGameType::Combat:  // TODO: define breakin, breakout, or ambush
      mGameCombat->start(Difficulty::Level1);  // TODO: determine difficulty within class
      break;
    case MiniGameType::Driving:  // TODO: define chase or evade
      mGameDriving->start(Difficulty::Level1);
      break;
    case MiniGameType::Crypto:
      mGameCrypto->start(Difficulty::Level1);
      break;
    case MiniGameType::Elec:  // TODO: define tap or trace
      mGameElec->start(Difficulty::Level1);
      break;
  }

// */
}

// TODO: make order of functions match the class order in the header
Difficulty GameState::getGameDifficulty()
{
  return this->gameDifficulty;
}

void GameState::setGameDifficulty(Difficulty gd)
{
  this->gameDifficulty = gd;
}
