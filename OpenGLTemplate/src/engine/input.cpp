﻿#include "engine/input.h"
#include "engine/window.h"

namespace Engine {
	namespace Input {
		float zoom = 1.0;  

		bool keyPressedData[GLFW_KEY_LAST] = {};
		bool mouseButtonPressedData[GLFW_MOUSE_BUTTON_LAST] = {};
		float mouseX = 0.0f;
		float mouseY = 0.0f;
		float mouseScrollX = 0.0f;
		float mouseScrollY = 0.0f;

		// Utility
		bool isKeyDown(int key) {
			if (key >= 0 && key < GLFW_KEY_LAST) {
				return keyPressedData[key];
			}
			return false;
		}

		bool isMouseButtonDown(int mouseButton) {
			if (mouseButton >= 0 && mouseButton < GLFW_MOUSE_BUTTON_LAST) {
				return mouseButtonPressedData[mouseButton];
			}
			return false;
		}

		// Callbacks
		void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			if (key >= 0 && key < GLFW_KEY_LAST) {
				keyPressedData[key] = action == GLFW_PRESS;
			}
		}

		void mousePosCallback(GLFWwindow* window, double xpos, double ypos) {
			mouseX = (float)xpos;
			mouseY = (float)ypos;
		}

		void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
			if (button >= 0 && button < GLFW_MOUSE_BUTTON_LAST) {
				mouseButtonPressedData[button] = action == GLFW_PRESS;
			}
		}

		void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
			mouseScrollX = (float)xoffset;
			mouseScrollY = (float)yoffset;

			// Zwiększ/zmniejsz zoom w zależności od scrolla
			if (yoffset > 0) {
				Engine::Input::zoom *= 1.1f;  // Zwiększenie zoomu
			}
			else if (yoffset < 0) {
				Engine::Input::zoom *= 0.9f;  // Zmniejszenie zoomu
			}
		}
	}
}