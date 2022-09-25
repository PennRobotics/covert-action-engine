#pragma once

/// #include <functional>
/// #include <memory>
#include "../gui/gui.h"

class GameState : public GUI {
public:
  GameState() = default;
  ~GameState() = default;
  GameState(const GameState&) = delete;
  GameState& operator=(const GameState&) = delete;

  void initMiniGameClasses();
  void startGUI();
  void enterMiniGame(MiniGameType miniGame);
  void getNextScreen(ScreenExitCondition condition = ScreenExitCondition::None);
  Difficulty getGameDifficulty();  // TODO
  void setGameDifficulty(Difficulty gameDifficulty);

  MiniGameType currentMiniGame { MiniGameType::Inactive };
  GameScreen currentScreen { GameScreen::Splash1 };
  bool inMiniGame;
  bool isTwelve { true };
  OriginScreen comingFrom { OriginScreen::UNKNOWNORIGIN };
  int modalSequence { 0 };
  Difficulty gameDifficulty;
};
