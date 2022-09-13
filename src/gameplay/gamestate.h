#ifndef CA_GAMESTATE_H
#define CA_GAMESTATE_H

#include <memory>
#include "../types.h"

/// #include "../minigame/combat.h"
/// #include "../minigame/driving.h"
/// #include "../minigame/cryptography.h"
/// #include "../minigame/electronics.h"

/// std::unique_ptr<MiniGameCombat> mGameCombat;
/// std::unique_ptr<MiniGameDriving> mGameDriving;
/// std::unique_ptr<MiniGameCryptography> mGameCrypto;
/// std::unique_ptr<MiniGameElectronics> mGameElec;

class GameState {
public:
  GameState() = default;
  ~GameState() = default;
  GameState(const GameState&) = delete;
  GameState& operator=(const GameState&) = delete;

  void initMiniGameClasses();

  void enterMiniGame(MiniGameType miniGame);
  GameScreen getNextScreen(ScreenExitCondition condition = ScreenExitCondition::None);

/// protected:
  bool inMiniGame;
  MiniGameType currentMiniGame{MiniGameType::Inactive};
  GameScreen currentScreen{GameScreen::Splash1};
  bool isTwelve { true };
  Difficulty getGameDifficulty();  // TODO

/// private:
  int selectedChoice;
  OriginScreen comingFrom{OriginScreen::UNKNOWNORIGIN};
  int modalSequence { 0 };
  Difficulty gameDifficulty;

  void setGameDifficulty(Difficulty gameDifficulty);
};


#endif
