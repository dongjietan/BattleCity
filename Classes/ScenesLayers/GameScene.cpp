//
//  GameScene.cpp
//  BattleCity
//
//  Created by Jay on 15/10/10.
//
//

#include "GameScene.h"
#include "CCAnimationHelper.h"
#include "GameManager.h"
#include "InputLayer.h"
#include "PlayerEntity.h"
#include "BulletCache.h"
#include "EnemyCache.h"
#include "Entity.h"

USING_NS_CC;

static GameScene *_currentGameScene = NULL;
static Rect screenRect = Rect(110, 4, 312, 312);

GameScene* GameScene::getCurrentGameScene(){
    CCASSERT(_currentGameScene, "GameScene instance not yet initialized!");
    return _currentGameScene;
}

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

Rect GameScene::getScreenRect(){
    return screenRect;
}

bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    _currentGameScene = this;
    
    Size screenSize = Director::getInstance()->getVisibleSize();
    
    offset = Vec2(110, 4);
    
    int _bricks[2704];
    bricks = _bricks;
    
    auto inputLayer = InputLayer::create();
    this->addChild(inputLayer, 100, GameSceneLayerTagInput);
    
    return true;
}

void GameScene::onEnter()
{
    Layer::onEnter();
}

void GameScene::onExit()
{
    Layer::onExit();
}

Entity* GameScene::getDefaultPlayer(){
    return _defaultPlayer;
}

EnemyCache* GameScene::getEnemyCache(){
    return _enemyCache;
}

BulletCache* GameScene::getBulletCache(){
    return _bulletCache;
}

void GameScene::addStar(){
    
}

void GameScene::gameOver(){
    
}

void GameScene::showOver(){
    
}

void GameScene::showScore(){
    
}
