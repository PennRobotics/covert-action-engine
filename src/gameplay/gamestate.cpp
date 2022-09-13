//
// Created by wright on 06/09/22.
//

#include "gamestate.h"

void GameState::initMiniGameClasses() {
}

GameScreen GameState::getNextScreen(ScreenExitCondition condition) {
  GameScreen nextscreen;  // TODO: what is `nextscreen`?
  // TODO: possibly clear `comingFrom` and set an overrideable default

  if (this->inMiniGame) {
    switch (this->currentMiniGame) {
      case MiniGameType::Combat:
        if (condition == ScreenExitCondition::None) { return GameScreen::CityMainMenu; }
        if (condition == ScreenExitCondition::Arrest) { return GameScreen::CombatArrest; }
        if (condition == ScreenExitCondition::Shot) { return GameScreen::CombatRecover; }
        if (condition == ScreenExitCondition::Lose) { return GameScreen::CombatCaptive; }
      case MiniGameType::Driving:
      case MiniGameType::Crypto:
      case MiniGameType::Elec:
        break;
    }
  } else {
    // this->inMiniGame is false
    switch (this->currentScreen) {
      case GameScreen::Splash1:
        return GameScreen::Splash2;
      case GameScreen::Splash2:
        return GameScreen::BeginMenu;
      case GameScreen::BeginMenu:
        if (this->selectedChoice == 1) {}
        if (this->selectedChoice == 2) { return GameScreen::Load; }
        if (this->selectedChoice == 3) { return GameScreen::SkillPractice; }
        if (this->selectedChoice == 4) { return GameScreen::HallOfFame; }
        return GameScreen::NewCharacter;
      case GameScreen::Load:
        return GameScreen::UNKNOWN;
      case GameScreen::SkillPractice:  // TODO
        (this->modalSequence)++;
        // TODO: set comingFrom to BeginMenu
        // TODO: how to deal with the transition from not in minigame into the minigame??
        if (this->modalSequence == 3) {
          if (this->selectedChoice == 1) { return GameScreen::MiniGameCombatStart; }
          if (this->selectedChoice == 2) { return GameScreen::MiniGameDrivingStart; }
          if (this->selectedChoice == 3) { return GameScreen::MiniGameCryptoStart; }
          if (this->selectedChoice == 4) { return GameScreen::MiniGameElecStart; }
        }
        // TODO: default?
        break;
      case GameScreen::HallOfFame:  // TODO
        break;
      case GameScreen::NewCharacter:
        (this->modalSequence)++;
        if (this->modalSequence > 3) { return GameScreen::SkillUpgrade; }
        break;
      case GameScreen::SkillUpgrade:
        (this->modalSequence)++;
        if (this->modalSequence > 4) {
          this->comingFrom = OriginScreen::ChiefCaseIntro;
          return GameScreen::Chief;
        }
        break;
      case GameScreen::Chief:
        if (this->comingFrom == OriginScreen::ChiefCaseIntro) { return GameScreen::MastermindLineup; }
        if (this->comingFrom == OriginScreen::ChiefInfoHandout) {
          this->isTwelve = true;
          return GameScreen::ShowNewClues;
        }
        if (this->comingFrom == OriginScreen::ChiefKickMaxOut) { return GameScreen::CIAContact; }
        break;
      case GameScreen::MastermindLineup:
        this->comingFrom = OriginScreen::ChiefInfoHandout;
        return GameScreen::Chief;
      case GameScreen::ShowNewClues:
        if (this->comingFrom == OriginScreen::ChiefInfoHandout) {
          this->comingFrom = OriginScreen::ChiefKickMaxOut;
          return GameScreen::Chief;
        }
        if (this->comingFrom ==
            OriginScreen::CIA) { return GameScreen::CIAIntel; /* TODO: make sure new clues at 12 during crypto do not jump here! */ }
        break;
      case GameScreen::CIAContact:
        this->comingFrom = OriginScreen::CIA;
        return GameScreen::CIASam;
      case GameScreen::CIAMainMenu:
        if (this->selectedChoice == 1) { return GameScreen::CIAData; }
        if (this->selectedChoice == 2) { return GameScreen::CIAIntel; }
        if (this->selectedChoice == 3) { return GameScreen::CIACrypto; }
        this->comingFrom = OriginScreen::CityMenu;
        return GameScreen::CityMainMenu;
      case GameScreen::CIAData:
        if (this->selectedChoice == 1) { return GameScreen::ReviewClues; }
        if (this->selectedChoice == 2) { return GameScreen::ReviewSuspects; }
        if (this->selectedChoice == 3) { return GameScreen::ReviewInsideInfo; }
        if (this->selectedChoice == 4) { return GameScreen::ReviewNews; }
        if (this->selectedChoice == 5) { return GameScreen::ReviewOrg; }
        if (this->selectedChoice == 6) { return GameScreen::ReviewCity; }
        if (this->selectedChoice == 7) { return GameScreen::ReviewActivity; }
        return GameScreen::CIAMainMenu;
      case GameScreen::CIAIntel:
        if (this->selectedChoice == 1 || this->selectedChoice == 2) {
          return GameScreen::ShowNewClues;
        }
        if (this->selectedChoice == 3) { return GameScreen::ReviewWiretaps; }
        if (this->selectedChoice == 4) {
          // TODO: check if current office has double agent
          if (0) {
            // TODO: DA found!
          } else {
            return GameScreen::CIABanned;
          }
        }
        if (this->selectedChoice == 5) { return GameScreen::CIASam; }
        break;
      case GameScreen::CIASam:
        return GameScreen::CIAMainMenu;
      case GameScreen::CIACrypto:
        break;
      case GameScreen::CodedMessages:
        break;
      case GameScreen::CrimeChronology:
        break;
      case GameScreen::CIABanned:
        return GameScreen::CityMainMenu;
      case GameScreen::CityMainMenu:
        // TODO: airport, hotel, ..., data
        break;
      case GameScreen::Airport:
        break;
      case GameScreen::Hotel:
        break;
      case GameScreen::LoadSave:
        break;
      case GameScreen::ReviewClues:
        break;
      case GameScreen::ReviewSuspects:
        break;
      case GameScreen::ReviewInsideInfo:
        break;
      case GameScreen::ReviewNews:
        break;
      case GameScreen::ReviewOrg:
        break;
      case GameScreen::ReviewCity:
        break;
      case GameScreen::ReviewActivity:
        break;
      case GameScreen::Building1:
        break;
      case GameScreen::Building2:
        break;
      case GameScreen::Building3:
        break;
      case GameScreen::Building4:
        break;
      case GameScreen::Building5:
        break;
      case GameScreen::CombatArrest:
        break;
      case GameScreen::CombatRecover:
        break;
      case GameScreen::CombatCaptive:
        break;
      case GameScreen::Typewriter:
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
        return GameScreen::GameExit;  // TODO
    }
  }
  // TODO: throw something; (should never reach this point)
  return GameScreen::GameExit;
}

void GameState::enterMiniGame(MiniGameType miniGame) {
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

Difficulty GameState::getGameDifficulty() {
  return this->gameDifficulty;
}

void GameState::setGameDifficulty(Difficulty gd) {
  this->gameDifficulty = gd;
}
