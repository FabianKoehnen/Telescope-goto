#ifndef __Constraints_h__
#define __Constraints_h__

class Constraints{
private:
    int stepsAwayFromTopConstraint;
    int stepsAwayFromBottomConstraint;

    bool isTopActive;
    bool isBottomActive;
public:
    Constraints();

    void setTopConstraint();
    void setBottomConstraint();

    bool isActive();

    bool isValid(int steps, bool isCounterClockwise);
    void moveSteps(int steps, bool isCounterClockwise);
};

#endif