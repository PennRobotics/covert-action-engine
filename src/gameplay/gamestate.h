//
// Created by wright on 06/09/22.
//

#ifndef SPNA_GAME_GAMESTATE_H
#define SPNA_GAME_GAMESTATE_H

#include <memory>
#include "../types.h"

#include "../minigame/combat.h"
#include "../minigame/driving.h"
#include "../minigame/cryptography.h"
#include "../minigame/electronics.h"

static std::unique_ptr<MiniGameCombat> mGameCombat;
static std::unique_ptr<MiniGameDriving> mGameDriving;
static std::unique_ptr<MiniGameCryptography> mGameCrypto;
static std::unique_ptr<MiniGameElectronics> mGameElec;

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
    MiniGameType currentMiniGame { MiniGameType::Inactive };
    GameScreen currentScreen { GameScreen::Splash1 };
/// private:
  int selectedChoice;
};





#endif //SPNA_GAME_GAMESTATE_H
