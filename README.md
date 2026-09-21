# SonicSpriterZ
Project Dash: Sonic Sprite Fighter (PC first then Port to Vita via VitaSDK)
DBFZ Inspired Fighting Game with Sprite of GameBoy Advance Sonic Characters 
with sprites from the following games
Base: Sonic Battle and Sonic Advance 1,2,3
(Future - Episode BlackDoomX: Megaman X Series, Megaman Series, Megaman Zero Series, Sonic 1,2,3,CD and Final Fantasy Sonic)

STORY
After an alternate ending to Sonic 06 where after the timeline is reversed a crack in the multiverse occurs and accross most sprite work characters now are aware of other sprite dimensions.
Our Speedy Heroes will put the spriterverse back together!






Github Repository Breakdown
src/
main.cpp				// Main game loop
GameStateManager.cpp	// Manages game states
InputManager.cpp		// Handles input processing
ResourceManager.cpp		// Manages textures, sounds, etc.
State.cpp				// Base class for game states

MainMenu.cpp		// Handles main menu logic
GameplayState.cpp	// Handles gameplay logic
PauseState.cpp		// Handles pause menu logic
Options.cpp			// Handles options menu logic

entities/
Character.cpp     // Base class for characters
Sonic.cpp         // Sonic-specific logic
Shadow.cpp        // Shadow-specific logic
Emerl.cpp         // Emerl-specific logic

components/
PhysicsComponent.cpp	// Handles physics
GraphicsComponent.cpp	// Handles rendering
InputComponent.cpp		// Handles entity-specific input

utils/
Logger.cpp        // Handles logging
MathUtils.cpp     // Utility functions for math

include/
headers for implementations (.h files...)

Vertical Slice
1) Gather Libraries and Set up MSVS Project:
	- SFML: Simple and Fast Multimedia Libary handles graphics, input, and audio
	- SDL2: Simple DirectMedia Layer - handles creation, rendering, and input

2) Visuals and Gameplay
	- Read input from the user (Keyboard initial priority, then FightStick, then gamepad...)
	- Show effect of input in game (moving image within window etc.)
	
2) Use Box2D for hitboxes and hurtboxes
	- Hitboxes must match dimensions of character sprites (sketch on iPad)
	- Low hitboxes will need to be made (take from x4-x8 and Procreate for Sonic Characters or find 'look-down' animations/sheets)

3) Sprite Management - manage with libraries like STB Image or SFML built-in's
	- Went with SFML -> Statically Linked so must add Licence for library software

4) State Management for movement
	- Use Finite State Machines for movement, attacks, hit-detection and specials and supers???

Environment:
-Tools: SFML/SDL2 (Libraries, Compiler, IDE)
-MSVS Empty Project and Link to graphics library
-create c++ file
-get a window and go...

VS Code Build and Run
---------------------
1. Install the **CMake Tools** and **C/C++** extensions. VS Code will also
   suggest them when this project is opened.
2. Install the compiler and SFML once from an MSYS2 UCRT64 terminal:

    C:\msys64\usr\bin\pacman.exe -S --needed mingw-w64-ucrt-x86_64-sfml

3. In VS Code, select `File > Open Folder...` and choose the folder containing
   `CMakeLists.txt`, `main.cpp`, `assets`, and `.vscode`. Do not open only
   `src` or `include`.
4. For a quick test cycle, press `Ctrl+Shift+P`, choose `Tasks: Run Task`, and
   select `ProjectDash: Build and Run`. The first run configures CMake and
   builds automatically.
5. To debug, press `F5` and choose the `ProjectDash` configuration. It builds
   before starting GDB.

The working directory is set to the repository root so relative asset paths
continue to work. If the task list is empty, reopen the folder from step 3
and confirm that `.vscode/tasks.json` is present. If CMake cannot be found,
restart VS Code after installing MSYS2 or add
`C:\msys64\ucrt64\bin` and `C:\msys64\usr\bin` to the Windows PATH.

Input Architecture System
Movement (8-way):
- Up (8), Down (2), Left (4), Right (6)
- Diagonals: UF (9), UB (7), DF (3), DB (1)
- Neutral (5)

Button Layout:
- Light Attack (L)
- Medium Attack (M)
- Heavy Attack (H)
- Special (S)
- Assist/Tag 1 (A1)
- Assist/Tag 2 (A2)

FSM Implementation
Base States:
- Idle
- Walking/Running
- Crouching
- Jumping
- Attack Active
- Hit/Block Stun
- Recovery

Special States:
- Tag Animation
- Super Animation
- Special Move
- Dash

Combat System
Phase 1:
- Basic movement and attacks
- Hit/hurt boxes
- Basic combos
- Block system

Phase 2:
- Cancel system
- Special moves
- Tag mechanics
- Basic frame data implementation

Phase 3:
- Advanced mechanics (air dashing, spindashing/unique moves etc.)
- Super moves
- Counter system
- Advanced cancel options

Local MP Setup
- Input buffer system
- Frame advantage tracking
- Hit confirmation system
- Screen boundary management
- Camera control for 2-player view

(Future Online Implement System)
- Implement deterministic game state
- Frame-by-frame state saving
- Input recording/playback system
- Prepare for rollback integration

-------Credits---------
Sprites:
Sega
Sonic Team
Capcom
Marvel
Newgrounds.com

Sprite Rippers:
Spriters Resource 

Lead Programmer(s):
Myself (Chayce Leonard)

Special Thanks:
Lythero
ZzyX_
IHeartJustace
MaxamillianDood
DashieXP
CoryXKenshin
Markiplier

In Rememberance of:
Akira Toriyama
BlackDevilX (Creator of Final Fantasy Sonic X Flash Series and Aeon the Hedgehog)
