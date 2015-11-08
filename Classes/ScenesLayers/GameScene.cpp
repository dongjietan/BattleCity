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
#include "EnemyEntity.h"
#include "Born.h"
#include "Blast.h"
#include "MainMenuScene.h"
#include "LevelScene.h"
#include "ScoreScene.h"

USING_NS_CC;

static GameScene *_currentGameScene = NULL;
const Rect GameScene::_screenRect(110, 4, 312, 312);
//游戏界面偏移量
const Vec2 GameScene::_offset(110, 4);

GameScene* GameScene::getCurrentGameScene(){
    CCASSERT(_currentGameScene, "GameScene instance not yet initialized!");
    return _currentGameScene;
}

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer, 0, GameSceneLayerTagGame);
    return scene;
}

Rect GameScene::getScreenRect(){
    return _screenRect;
}

bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    _currentGameScene = this;
    
    int _bricks[2704];
    bricks = _bricks;
    
    auto inputLayer = InputLayer::create();
    this->addChild(inputLayer, 100, GameSceneLayerTagInput);
    
    Size screenSize = Director::getInstance()->getVisibleSize();
    
    //灰色背景
    auto backGround = LayerColor::create(Color4B(153, 153, 153, 255), screenSize.width, screenSize.height);
    this->addChild(backGround, -10);
    
    //黑色游戏背景
    auto gameRect = LayerColor::create(Color4B(0, 0, 0, 255), screenSize.height - 8, screenSize.height - 8);
    gameRect->setPosition(_offset);
    this->addChild(gameRect, 0);
    
    //旗子
    auto flag = Sprite::createWithSpriteFrameName("flag.png");
    flag->setPosition(50, 260);
    this->addChild(flag);
    
    //IP标签
    auto IPLB = Label::createWithSystemFont("I P", "STHeitiJ-Light", 20);
    IPLB->setColor(Color3B::BLACK);
    IPLB->setPosition(50, 200);
    this->addChild(IPLB);
    
    //玩家命数
    auto liveStr = StringUtils::format("%d", GameManager::getInstance()->getLives() - 1);
    liveLB = Label::createWithSystemFont(liveStr, "STHeitiJ-Light", 15);
    liveLB->setColor(Color3B::BLACK);
    liveLB->setPosition(54, 178);
    this->addChild(liveLB, 0, kTagLiveLabel);
    
    //小坦克标志
    auto logo = Sprite::createWithSpriteFrameName("logo1.png");
    logo->setPosition(40, 180);
    this->addChild(logo);
    
    this->initLevel();
    
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

PlayerEntity* GameScene::getDefaultPlayer(){
    auto node = this->getChildByTag(GameSceneNodeTagPlayer);
    CCASSERT(dynamic_cast<PlayerEntity *>(node), "node is not a PlayerEntity!");
    return dynamic_cast<PlayerEntity *>(node);
}

Entity* GameScene::getDefaultBoss(){
    auto node = this->getChildByTag(GameSceneNodeTagBoss);
    CCASSERT(dynamic_cast<Entity *>(node), "node is not a Entity!");
    return dynamic_cast<Entity *>(node);
}

EnemyCache* GameScene::getEnemyCache(){
    auto node = this->getChildByTag(GameSceneNodeTagEnemyCache);
    CCASSERT(dynamic_cast<EnemyCache *>(node), "node is not a EnemyCache!");
    return dynamic_cast<EnemyCache *>(node);
}

BulletCache* GameScene::getBulletCache(){
    auto node = this->getChildByTag(GameSceneNodeTagBulletCache);
    CCASSERT(dynamic_cast<BulletCache *>(node), "node is not a BulletCache!");
    return dynamic_cast<BulletCache *>(node);
}

void GameScene::begin(){
    this->addStar();
    this->scheduleUpdate();
    auto layer = this->getChildByTag(GameSceneLayerTagInput);
    layer->scheduleUpdate();
}

void GameScene::initLevel(){
    auto levelStr = StringUtils::format("%d", GameManager::getInstance()->getLevel());
    auto stageLB = Label::createWithSystemFont(levelStr, "STHeitiJ-Light", 15);
    stageLB->setColor(Color3B::BLACK);
    stageLB->setPosition(55, 240);
    this->addChild(stageLB);
    
    auto mapName = StringUtils::format("stage%d.tmx", GameManager::getInstance()->getLevel());
    auto tileMap = TMXTiledMap::create(mapName);
    this->addChild(tileMap, 1, GameSceneLayerTagMap);
    tileMap->setPosition(_offset);
    
    //主基地标志
    auto boss = Entity::createWithSpriteFrameName("boss.png");
    boss->setPosition(6*24 + 12, 12);
    this->addChild(boss, 0, GameSceneNodeTagBoss);
    
    auto enemyCache = EnemyCache::create();
    this->addChild(enemyCache, 0, GameSceneNodeTagEnemyCache);
    
    auto bulletCache = BulletCache::create();
    this->addChild(bulletCache, 1, GameSceneNodeTagBulletCache);
    
    auto player = PlayerEntity::createP
}

void GameScene::addStar(){
    
}

void GameScene::gameOver(){
    
}

void GameScene::showOver(){
    
}

void GameScene::showScore(){
    
}

void GameScene::update(float delta){
    
}
