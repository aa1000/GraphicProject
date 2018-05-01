﻿#pragma once
#include "GVector.h"
#include "GL/freeglut.h"
#include "GObject.h"

class RenderedObject : public GObject
{
public:
	int glListIndex;

	GVector Location;
	GVector Rotation;
	GVector Scale;

	RenderedObject();
	RenderedObject(int glListIndex);
	~RenderedObject();

	void SetScale(float NewScale);
	virtual bool Load(char* FileName);
	void ApplyTransforms();
	virtual void Build();
	virtual void Compile();
	virtual void Render();
};
