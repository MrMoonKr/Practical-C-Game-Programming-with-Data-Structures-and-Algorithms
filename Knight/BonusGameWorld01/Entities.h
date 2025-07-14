#pragma once

#include "Knight.h"

#include "QuadTreeTerrainComponent.h"
#include "PlayerFSM.h"
#include "SkyboxComponent.h"
#include "MagicAttackEffect.h"

class Entity
{
public:
	// method to render the entire level
	virtual bool Create(Scene* pScene, Entity* pContainer = nullptr) = 0;
	virtual void Update(float elapsedTime) = 0;
	SceneActor* _Actor = nullptr;
};

class TerrainEntity : public Entity
{
public:
	// method to render the entire level
	bool Create(Scene* pScene, Entity* pContainer = nullptr) override;
	void Update(float elapsedTime) override;

	QuadTreeTerrainComponent* _Terrain = nullptr;

protected:
	Texture2D treeImage = { 0 };
	Texture2D robotImage = { 0 };
	vector<SceneActor*> imposters = { 0 };
	SkyboxComponent* pSkybox = nullptr;

	int currentIdx = -1;
	float timeDiff = 0.0f;
};

class PlayerEntity : public Entity
{
public:
	// method to render the entire level
	bool Create(Scene* pScene, Entity *pContainer = nullptr) override;
	void Update(float elapsedTime) override;

	~PlayerEntity();

	PlayerFSM* PlayerCharacterFSM = nullptr;

	MagicAttackEffect* pAttackEffect = nullptr;

protected:
	TerrainEntity* pTerrainEntity = nullptr;
};

class PropEntity : public Entity
{
public:
	// method to render the entire level
	bool Create(Scene* pScene, Entity* pContainer = nullptr) override;
	void Update(float elapsedTime) override;

protected:
	TerrainEntity* pTerrainEntity = nullptr;
};
