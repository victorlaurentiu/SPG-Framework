#include "Project.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>

using namespace std;

// Order of function calling can be seen in "Source/Core/World.cpp::LoopUpdate()"
// https://github.com/UPB-Graphics/SPG-Framework/blob/master/Source/Core/World.cpp

Project::Project()
{
}

Project::~Project()
{
}

void Project::Init()
{
	auto camera = GetSceneCamera();
	camera->SetPositionAndRotation(glm::vec3(0, 5, 4), glm::quat(glm::vec3(-30 * TO_RADIANS, 0, 0)));
	camera->Update();

	// Load a mesh from file into GPU memory
	{
		Mesh* mesh = new Mesh("kele");
		mesh->LoadMesh(RESOURCE_PATH::ROOT + "kele-thet-tzu-god-of-the-void-and-blood/source", "KelFinal.fbx");
		meshes[mesh->GetMeshID()] = mesh;
	}

	// Load Textures
	{
		std::string texturesPath = RESOURCE_PATH::ROOT + "kele-thet-tzu-god-of-the-void-and-blood/textures";
		TextureManager::LoadTexture(texturesPath, "");
	}

	// Create a shader program for rendering to texture
	{
		std::string shaderPath = "Source/Laboratoare/Project/Shaders/";
		Shader *shader = new Shader("Instances");
		shader->AddShader(shaderPath + "VertexShader.glsl", GL_VERTEX_SHADER);
		shader->AddShader(shaderPath + "FragmentShader.glsl", GL_FRAGMENT_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}
}

void Project::FrameStart()
{

}

void Project::Update(float deltaTimeSeconds)
{
	ClearScreen();

	{
		auto shader = shaders["Instances"];
		shader->Use();

		int loc_instances = shader->GetUniformLocation("instances");
		glUniform1i(loc_instances, 1);

		RenderMesh(meshes["bamboo"], shaders["Instances"], glm::vec3(-3.3f, 0.5f, 0), glm::vec3(0.1f));
	}
}

void Project::FrameEnd()
{
	DrawCoordinatSystem();
}

// Read the documentation of the following functions in: "Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/SPG-Framework/blob/master/Source/Core/Window/InputController.h

void Project::OnInputUpdate(float deltaTime, int mods)
{
	// treat continuous update based on input with window->KeyHold()
};

void Project::OnKeyPress(int key, int mods)
{
	// add key press event
	if (key == GLFW_KEY_EQUAL)
	{
	}
};

void Project::OnKeyRelease(int key, int mods)
{
	// add key release event
};

void Project::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
};

void Project::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
};

void Project::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Project::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
	// treat mouse scroll event
}

void Project::OnWindowResize(int width, int height)
{
	// treat window resize event
}
