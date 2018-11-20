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