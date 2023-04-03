#pragma once
#include "includes.h"

class WHGGameLayer : public cocos2d::CCLayer
{
public:
	static WHGGameLayer* create();
	static cocos2d::CCScene* scene();
	bool init();
	void backButtonCallback(cocos2d::CCObject*);
};