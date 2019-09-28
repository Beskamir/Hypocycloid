== README ==

This is some skeleton code provided to help you get started on your assignments in CPSC589/689. It creates a simple 2D triangle and shows an example window for the user interface. This code is designed for 2D graphics; if you would like a framework for 3D graphics for use in your projects, this is also available on Mia's course website: https://pages.cpsc.ucalgary.ca/~mmactavi/589/ and includes an .obj loader and an image loader.

imgui (https://github.com/ocornut/imgui) is integrated in this code base to provide some simple UI controls and text rendering. The use of imgui is completely optional, but you may find it useful for changing parameters, displaying debugging information, etc.

This code is provided to you to help you get started on your assignments more easily. It is not mandatory to use this code if you have a different framework that you prefer.

== SETUP ==

This code uses GLFW and GLEW. Source packages and precompiled binaries can be downloaded here:
    GLFW: https://www.glfw.org/
    GLEW: http://glew.sourceforge.net/

Be sure to link to those libraries when building your project. 
These are already installed on the Linux machines in the graphics lab where tutorials are run. On the lab computers, link to the "GL", "glew" and "GLEW" libraries. 

In order to use imgui, you must build all files in /include/imgui with the rest of your project. Also add /include/imgui to your include directories. 