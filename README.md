# BattleTank
Open world one on one tank fight with simple AI with UE4


Commits
* V0.01 First commit to start repository
* V0.05 Cloned on PC with gitignore
* v0.1 Engine/gitignore setup
* v0.15 Map created with terrain deformation
* v0.25 Map Textured, Tank assembled and setup in a BPmode, Camera X-Y setup with a bug
* v0.3 Camera bug fixed, Basic Main Menu made, Start Button functional
* v0.35 Player Controller + Tank Class in C++ made so you can use polymorphism with Player/AI
* v0.4 AI Controller made in C++, AI can Find and get the player Tank with a GetMethod
* v0.45 Player Controller finds world position of crosshair using a line trace with a Pixel Screen position with a max range trace line
* v0.5 Tank BP Deriving to a Tank Aiming Component in C++ That has a set location using the tank barrel position as a start
* v0.6 Tank has 2 custom Static Mesh for Turret/Barrel. Aim Component searchs for posible position then 
delegates to Turret/Barrel Component to rotate in the direction needed with a fixed max speed editable
* v0.65 Fire button added to the game with a Projectile BP made as a placeholder appearing correctly in barrel fire position
* v0.7 Changed Collision for a simpler form. Changed Tank to improved tank models. TankTrack c++ file Created
* v0.75 Made a change in blueprint to make meshs/materials autoassing in runtime to bypass a bug in UE 4.20 that
unassings meshs every Compilation/Change of level. TankTrack added and made new collision to fall on the tracks.
Input and collision added to the tracks.
* v0.85 Snow Particle System added, moving tank with rotation and AI pathfinding integrated.