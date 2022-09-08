//
// Created by wright on 06/09/22.
//

#include "gamestate.h"

void GameState::initMiniGameClasses() {
    mGameCombat = std::make_unique<MiniGameCombat>();
    mGameDriving = std::make_unique<MiniGameDriving>();
    mGameCrypto = std::make_unique<MiniGameCryptography>();
    mGameElec = std::make_unique<MiniGameElectronics>();
}

GameScreen GameState::getNextScreen(ScreenExitCondition condition) {
    GameScreen nextscreen;

    if (this->inMiniGame) {
        switch (this->currentMiniGame) {
            case MiniGameType::Combat:
                if (condition == ScreenExitCondition::None)  { return GameScreen::CityMainMenu; }
                if (condition == ScreenExitCondition::Arrest)  { return GameScreen::CombatArrest; }
                if (condition == ScreenExitCondition::Shot)  { return GameScreen::CombatRecover; }
                if (condition == ScreenExitCondition::Lose)  { return GameScreen::CombatCaptive; }
            case MiniGameType::Driving:
            case MiniGameType::Crypto:
            case MiniGameType::Elec:
                break;
        }
    } else {
      switch (this->currentScreen) {
        case GameScreen::Splash1:  return GameScreen::Splash2;
        case GameScreen::Splash2:  return GameScreen::BeginMenu;
        case GameScreen::BeginMenu:
          if (this->selectedChoice == 1)  { return GameScreen::NewCharacter; }
          if (this->selectedChoice == 2)  { return GameScreen::Load; }
          if (this->selectedChoice == 3)  { return GameScreen::SkillPractice; }
          return GameScreen::HallOfFame;
        case GameScreen::NewCharacter:
          return GameScreen::SkillUpgrade;
        case GameScreen::SkillUpgrade:
          this->comingFrom = Origin::ChiefCaseIntro;
          return GameScreen::Chief;
        case GameScreen::Chief:
          if (this->comingFrom == Origin::ChiefCaseIntro)  { return GameScreen::MastermindLineup; }
          if (this->comingFrom == Origin::ChiefInfoHandout)  { this->isTwelve = true; return GameScreen::ShowNewClues; }
          if (this->comingFrom == Origin::ChiefKickMaxOut)  { return GameScreen::CIAContact; }
          break;
        case GameScreen::MastermindLineup:
          this->comingFrom = Origin::ChiefInfoHandout;
          return GameScreen::Chief;
        case GameScreen::ShowNewClues:
          if (this->comingFrom == Origin::ChiefInfoHandout)  { this->comingFrom = Origin::ChiefKickMaxOut; return GameScreen::Chief; }
          if (this->comingFrom == Origin::CIA)  { return GameScreen::CIAIntel; /* TODO: make sure new clues at 12 during crypto do not jump here! */ }
          break;
        case GameScreen::CIAContact:
          this->comingFrom = Origin::CIA;
          return GameScreen::CIASam;
        case GameScreen::CIAMainMenu:
          if (this->selectedChoice == 1)  { return GameScreen::CIAData; }
          if (this->selectedChoice == 2)  { return GameScreen::CIAIntel; }
          if (this->selectedChoice == 3)  { return GameScreen::CIACrypto; }
          this->comingFrom = Origin::CityMenu;
          return GameScreen::CityMainMenu;
        case GameScreen::CIAData:
          if (this->selectedChoice == 1)  { return GameScreen::ReviewClues; }
          if (this->selectedChoice == 2)  { return GameScreen::ReviewSuspects; }
          if (this->selectedChoice == 3)  { return GameScreen::ReviewInsideInfo; }
          if (this->selectedChoice == 4)  { return GameScreen::ReviewNews; }
          if (this->selectedChoice == 5)  { return GameScreen::ReviewOrg; }
          if (this->selectedChoice == 6)  { return GameScreen::ReviewCity; }
          if (this->selectedChoice == 7)  { return GameScreen::ReviewActivity; }
          return GameScreen::CIAMainMenu;
        case GameScreen::CIAIntel:
          if (this->selectedChoice == 1 || this->selectedChoice == 2) {
            return GameScreen::ShowNewClues;
          }
          if (this->selectedChoice == 3)  { return GameScreen::ReviewWiretaps; }
          if (this->selectedChoice == 4) {
            // TODO: check if current office has double agent
            if (0) {
              // TODO: DA found!
            } else {
              return GameScreen::CIABanned;
            }
          }
          if (this->selectedChoice == 5)  { return GameScreen::; }
          break;
        case GameScreen::CIASam:
          break;
        case GameScreen::CIACrypto:
          break;
        case GameScreen::CIABanned:  return GameScreen::CityMainMenu;
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
        default:
          return GameScreen::GameExit;  // TODO
      }
    }
    // TODO: throw something; (should never reach this point)
    return GameScreen::GameExit;
}

void GameState::enterMiniGame(MiniGameType miniGame) {
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


}
