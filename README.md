# At0m

## Overview

At0m is a simple interactive OpenGL application built with GLFW and ImGui, allowing users to create and visualize atoms in a 3D space. This project serves as a basic framework for learning OpenGL, ImGui integration, and real-time rendering techniques.

## Features

-   **Interactive Atom Creation:** Add atoms to the scene by clicking within the application window.
-   **Color Customization:** Modify the color of the atoms using ImGui's color picker.
-   **OpenGL Rendering:** Utilizes OpenGL for rendering the atoms as points.
-   **Real-time Updates:** Atoms are rendered in real-time as they are added.
-   **ImGui Interface:** Provides a user-friendly interface for atom creation and color selection.

## Dependencies

-   GLFW
-   Glad
-   ImGui
-   OpenGL

## Building the Project

To build the project, follow these steps:

1.  **Clone the repository:**

    ```sh
    git clone [repository URL]
    cd At0m
    ```

2.  **Create a build directory:**

    ```sh
    mkdir build
    cd build
    ```

3.  **Configure the project using CMake:**

    ```sh
    cmake ..
    ```

4.  **Build the project:**

    ```sh
    cmake --build . --config Debug
    ```

    or

    ```sh
    cmake --build . --config Release
    ```

5.  **Run the executable:**

    -   On Windows, the executable will be located in `build\Debug` or `build\Release`.
    -   On Linux, the executable will be located in `build`.

## Usage

1.  Run the compiled executable.
2.  Use the ImGui panel to select a color for the atoms.
3.  Click the "Add Atom" button to enable atom insertion mode.
4.  Click within the window to create atoms at the mouse cursor's position.
5.  Toggle the "Add Atom" button to stop atom insertion.

## Project Structure

At0m/
├── .vs/ # Visual Studio project settings
├── .vscode/ # VS Code settings
├── build/ # Build directory
├── dependencies/ # External libraries (GLFW, Glad, ImGui)
├── src/ # Source files
│ ├── atom_launcher.cpp # Main application class
│ ├── atom_launcher.h # Header for main application class
│ ├── atom.cpp # Atom class implementation
│ ├── atom.h # Atom class definition
│ ├── CMakeLists.txt # CMake build file
│ ├── Input_handler.cpp # Input handling implementation
│ ├── input_handler.h # Input handling definitions
│ ├── main.cpp # Entry point
│ ├── shader/ # Shader files
│ │ ├── fragment_shader.glsl
│ │ └── vertex_shader.glsl
│ └── util/ # Utility files
├── README.md # This file

## Code Overview

-   `src/main.cpp`: Contains the main function that initializes and runs the [`AtomLauncher`](src/atom_launcher.h) application.
-   `src/atom_launcher.cpp`: Implements the [`AtomLauncher`](src/atom_launcher.h) class, which manages the GLFW window, OpenGL context, ImGui integration, and atom rendering.
-   `src/atom.cpp`: Implements the Atom class, which represents an atom with a position and color.
-   `src/input_handler.cpp`: Handles user input events such as key presses and mouse clicks.
-   `src/shader/`: Contains the GLSL shader programs for rendering the atoms.

## Contributing

Contributions are welcome! Feel free to submit pull requests or open issues for bug fixes, feature requests, or improvements.

