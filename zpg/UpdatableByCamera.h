#pragma once

class Camera;
class UpdatableByCamera
{
public:
	UpdatableByCamera();
	virtual void update_by_camera(Camera* camera) = 0;
};

