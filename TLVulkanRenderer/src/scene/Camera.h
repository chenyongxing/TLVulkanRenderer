#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "geometry/Ray.h"

struct Camera {
	Camera();
	Camera(float width, float height);

	// -- Camera attributes
	glm::mat4 GetViewProj() const;
	glm::mat4 GetView() const;
	glm::mat4 GetProj() const;
	void EnablePerspective(bool enabled);
	void RecomputeAttributes();

	// -- Camera movement
	void RotateAboutRight(float deg);
	void RotateAboutUp(float deg);
	void Zoom(float amount);
	void TranslateAlongRight(float amount);
	void TranslateAlongUp(float amount);
	Ray GenerateRay(float x, float y) const;

	// -- Attributes
	glm::ivec2 resolution;
	float fov;
	glm::vec3 eye;
	glm::vec3 lookAt;
	glm::vec3 forward;
	glm::vec3 up;
	glm::vec3 right;
	float nearClip;
	float farClip;
	glm::vec2 pixelLength;
	int samplesPerPixel;
	float aspect;

	glm::mat4 viewMat;
	glm::mat4 projMat;
	bool isPerspective = true;
};
