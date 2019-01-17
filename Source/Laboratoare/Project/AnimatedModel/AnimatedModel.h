#pragma once
#include <string>
#include <vector>

#include <assimp/Importer.hpp>		// C++ importer interface
#include <assimp/scene.h>			// Output data structure
#include <assimp/postprocess.h>		// Post processing flags

#include <include/glm.h>

class GPUBuffers;
class Texture2D;

struct AnimatedVertexFormat
{
	AnimatedVertexFormat(glm::vec3 position,
				glm::vec3 color = glm::vec3(1),
				glm::vec3 normal = glm::vec3(0, 1, 0),
				glm::vec2 text_coord = glm::vec2(0),
				glm::ivec3 jointIDs = glm::ivec3(0),
				glm::vec3 weights = glm::vec3(0))
		: position(position), normal(normal), color(color), text_coord(text_coord),
		  jointIDs(jointIDs), weights(weights) { };

	// position of the vertex
	glm::vec3 position;		

	// vertex normal
	glm::vec3 normal;

	// vertex texture coordinate
	glm::vec2 text_coord;

	// vertex color
	glm::vec3 color;

	// 
	glm::ivec3 jointIDs;
	glm::vec3 weights;
};

struct Material
{
	Material()
	{
		texture = nullptr;
	}

	glm::vec4 ambient;
	glm::vec4 diffuse;
	glm::vec4 specular;
	glm::vec4 emissive;
	float shininess;

	Texture2D* texture;
};

static const unsigned int INVALID_MATERIAL = 0xFFFFFFFF;

struct MeshEntry
{
	MeshEntry()
	{
		nrIndices = 0;
		baseVertex = 0;
		baseIndex = 0;
		materialIndex = INVALID_MATERIAL;
	}
	unsigned short nrIndices;
	unsigned short baseVertex;
	unsigned short baseIndex;
	unsigned int materialIndex;
};

class AnimatedModel
{

};