//
//  GameManager.h
//  BattleCity
//
//  Created by Jay on 15/10/25.
//
//

#ifndef __BattleCity__GameManager__
#define __BattleCity__GameManager__

#include <stdio.h>
#include "cocos2d.h"

class GameManager : public cocos2d::Ref
{
    
public:
    /** Returns the shared instance of the Game Manager */
    static GameManager* getInstance(void);
    virtual ~GameManager();
    bool init(void);
    
    CC_SYNTHESIZE(bool, over, Over);
    
    void resetGame();
    void resetLevel();
    
    long getHighestScore();
    void setHighestScore(long highestScore);
    bool getChooseLevel();
    void setChooseLevel(bool chooseLevel);
    int getLevel();
    void setLevel(int level);
    long getScore();
    void setScore(long score);
    
    void addCurrentEnemyCountBy(int amount);
    void addScoreBy(long amount);
    void addEnemyAKilled(long amount);
    void addEnemyBKilled(long amount);
    void addEnemyCKilled(long amount);
    void addEnemyDKilled(long amount);
    
protected:
    int _level;
    int _totalLevels;
    long _highestScore;
    int _lives;
    long _score;
    int _enemyAKilled;
    int _enemyBKilled;
    int _enemyCKilled;
    int _enemyDKilled;
    bool _chooseLevel;
    int _enemyRemain;
    int _currentEnemyCount;
};

#endif /* defined(__BattleCity__GameManager__) */
