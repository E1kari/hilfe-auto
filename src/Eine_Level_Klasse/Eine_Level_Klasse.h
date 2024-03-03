//
// Created by Josi on 02.03.2024.
//

#ifndef RAYLIBSTARTER_EINE_LEVEL_KLASSE_H
#define RAYLIBSTARTER_EINE_LEVEL_KLASSE_H

namespace Game {

    enum State {
        debug,
        colliding,
        random30sec,
        randomOnClick,
    };

    class Eine_Level_Klasse {
        public:
        int Eine_Level_KlasseMain(Game::State state);

    };

} // Game

#endif //RAYLIBSTARTER_EINE_LEVEL_KLASSE_H
