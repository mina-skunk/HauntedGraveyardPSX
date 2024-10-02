# Haunted Graveyard

This is an attempt to make a PSX game sprint for Halloween.

|          |                             |
|---------:|:----------------------------|  
| Genre    | Top-Down 2D Indie Adventure |
| Platform | PlayStation (PSX Homebrew)  |
| Theme    | Halloween                   |

![Haunted Graveyard](/resources/HauntedGraveyard.png "Haunted Graveyard")

## Overview

Haunted Graveyard is a top-down 2D adventure where players control Alex, a character in a Halloween costume, navigating through three Halloween-themed levels: the Entrance, Graveyard, and Crypt. The objective is to find keys to unlock each successive level while avoiding or outsmarting ghosts.

## Mechanics

- Controls
  - Movement: D-Pad for movement.
  - Interaction: Cross button to interact with objects and NPCs.
- Objective
  - Find Keys: Keys are scattered throughout the levels. Each key unlocks a new areas.
  - Avoid Ghosts: Ghosts move around the levels and will chase or hinder Alex. Avoid them or find ways to outsmart them.
- Levels
  1. Entrance
      - Objective: Find the gate key to enter the Graveyard.
      - Features: An eerie entrance with a gate. Basic introduction to controls and game mechanics.
  2. Graveyard
      - Objective: Collect three keys to unlock the Crypt.
      - Features: Gravestones, eerie fog, and wandering ghosts.
  3. Crypt
      - Objective: Find the final key to escape or complete the game.
      - Features: Dark, labyrinthine corridors with stronger ghosts.
- NPCs
  - Grave Keeper: Offers clues or hints. Located at the entrance or key points of the Graveyard.
- Items
  - Keys: Collectible items that unlock doors or areas.
- Art and Aesthetics
  - Style: Spooky, cartoony, with a mix of dark and colorful Halloween-themed elements.
  - Character Design: Alex in a classic Halloween costume (e.g., ghost, vampire, or pumpkin).
  - Environment Design: Spooky graveyard with gravestones, mist, and a spooky crypt. Ensure that each level feels distinct but thematically connected.
- Sound and Music
  - Background Music: Atmospheric and spooky music suitable for Halloween.
  - No sound effects: There may be limitations of SFX with the PSX SDK used, for now focus on using music to create an immersive experience.

## Script

- Title Screen
  1. Title Screen Background
     - Spooky music plays.
     - Title: “Haunted Graveyard”
     - Options: Start, Instructions
  2. Instructions Screen
     - Text: “Use the D-Pad to move. Press Cross to interact. Find keys to unlock new areas and avoid ghosts!”
- Level 1: Entrance
  1. Entrance Scene
     - Alex enters the scene with basic Halloween costume.
     - Grave Keeper appears (stationary, with a dialogue box):
       - Grave Keeper: “The gate to the Graveyard is locked. Search the area for the key to proceed.”
  2. Player finds the key and unlocks the gate
     - Grave Keeper (if interacted with): “Good luck in the Graveyard. Beware the wandering spirits!”
- Level 2: Graveyard
  1. Graveyard Scene
     - Spooky fog and wandering ghosts are present.
     - Grave Keeper:“Three keys are needed to enter the Crypt. Look around and be cautious of the spirits.”
  2. Player collects keys
     - Grave Keeper (if interacted with): “You’ve gathered all the keys. The Crypt awaits. Prepare for more challenges!”
- Level 3: Crypt
  1. Crypt Scene
     - Dark and maze-like corridors with challenging ghosts.
  2. Player finds the final key and reaches the exit
     - Exit door opens.
     - Grave Keeper: “Congratulations! You’ve navigated the Haunted Graveyard. Enjoy your victory and have a spooky Halloween!”
- Ending Screen
  1. Ending Screen Background
     - Triumphant or celebratory background music plays.
     - Text: “Thank you for playing Haunted Graveyard! Happy Halloween!”
  2. Options
     - Replay
     - Main Menu

## Credits / assets to use

- [Modern UI](https://limezu.itch.io/modernuserinterface) by [LimeZu](https://limezu.itch.io/)
  - Playstation buttons
  - Textbox
- [Modern exteriors](https://limezu.itch.io/modernexteriors) by [LimeZu](https://limezu.itch.io/)
  - Graveyard tiles
- [Fungus Cave](https://limezu.itch.io/fungus-cave) by [LimeZu](https://limezu.itch.io/)
  - tiles (for undergroiund/the crypt)
- Music
  - Title: [Spooky Halloween Cartoon](https://freemusicarchive.org/music/artur-aravidi/single/spooky-halloween-cartoonmp3/) by [Artur Aravidi](https://freemusicarchive.org/music/artur-aravidi/)
- Developer, Mina (me)
- SDK: psyqo
  - [pcsx-redux team](/grumpycoders/pcsx-redux), @nicolasnoble, @axetion, and everyone on the [discord](https://discord.gg/QByKPpH)

 
## Convert Assets

### Audio

`ffmpeg -i '.\resources\Artur Aravidi - Spooky Halloween Cartoon.mp3.mp3' -acodec pcm_s16le -ac 2 -ar 44100 .\audio_tracks\spooky_halloween_cartoon.wav`  

### Image

`cd .\tools\psx-conv\`  
`npm i`  
`node .\index.js texture ..\..\resources\MinaSkunkDevelopment.png --name splash_tex ..\..\splash.h`  
`node .\index.js texture ..\..\resources\UI.png --name ui_tex ..\..\ui.h`  
`node .\index.js texture ..\..\resources\HauntedGraveyard.png --name title_tex ..\..\title.h`  
`node .\index.js texture ..\..\resources\StevePage.png --name steve_tex ..\..\steve.h`  
`node .\index.js texture ..\..\resources\GraveyardTileSet.png --name graveyard_tileset_tex ..\..\tileset.h`  

### Maps  

`cd .\tools\psx-conv\`  
`npm i`  
`node .\index.js tilemap ..\..\resources\Level1EntranceMap.tmx --name level1_map --layer 0 ..\..\level1_map.h`  
`node .\index.js tilemap ..\..\resources\Level1EntranceMap.tmx --name level1_map_detail --layer 1 ..\..\level1_map_detail.h`  
`node .\index.js tilemap ..\..\resources\Level1EntranceMap.tmx --name level1_map_surface --layer 2 ..\..\level1_map_surface.h`  

## Publish

`make`
`mkpsxiso .\HauntedGraveyard.xml`  
