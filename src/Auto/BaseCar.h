//
// Created by Josi on 03.03.2024.
//

#ifndef RAYLIBSTARTER_BASECAR_H
#define RAYLIBSTARTER_BASECAR_H

#include "components/BaseWheels.h"
#include "components/BaseGears.h"
#include "components/BaseEngine.h"
#include "components/BaseBreak.h"
#include "components/BaseFrame.h"
#include "components/BaseSuspension.h"


namespace car {

    class BaseCar {
    public:
        void accelerate();
        void brake();
        void accelerateBackwards();
        void turnLeft();
        void turnRight();
        void startEngine();
        void stopEngine();

        protected:
        car::components::BaseWheels* wheels[2][2];
        car::components::BaseGears gears;
        car::components::BaseEngine engine;
        car::components::BaseBreak breaks;
        car::components::BaseFrame frame;
        car::components::BaseSuspension suspension;
    };

} // car

#endif //RAYLIBSTARTER_BASECAR_H
