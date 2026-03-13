# UE_Network_Lab | "The Control Lab"
![The Control Lab](media/controlLab.gif)

A networked party-game template and experimental testbed for multiplayer gameplay engineering.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## 📖 About The Project

This repository contains the Unreal Engine project framework for **The Control Lab**, a networked party-game collection. It serves as the foundational template to engineer individual networked experiments (minigames) within a shared ecosystem.

Key features include a pre-configured **Server Browser**, **Host/Join functionality**, and a standardised **Input Schema** designed for rapid prototyping of multiplayer mechanics. Each experiment is designed as a "test chamber" where players compete to survive under a strict 60-second "Pass/Fail" loop.

---

## 🚀 Getting Started

Follow these instructions to get a copy of the project up and running on your local machine for development and testing.

### Prerequisites

* **Unreal Engine 5.4.4** (or newer).
* **Visual Studio 2022** (Windows) or **Xcode** (macOS) with C++ development support.
* **Git** (for cloning the repository).
* **Epic Games Launcher** installed.

### Installation

1. **Clone the repository:**
    ```sh
    git clone https://github.com/josh-hall-griffith/UE_Network_Lab.git
    ```

2. **Open the Editor:**
    Double-click `UE_Network_Lab.uproject` to launch the Unreal Editor. The **Advanced Sessions Plugin** is included in the `Plugins/` directory and should initialise automatically.

---

## ✨ Technical Standards

To ensure your experiment integrates with the Lab ecosystem, you must adhere to the following technical standards.

### 🎮 Input Schema
All experiments must use the following button mapping schema to maintain compatibility across different levels:

| Action | Key (KB/M) | Controller |
| :--- | :--- | :--- |
| **Move** | WASD | Left Stick |
| **Look/Rotate** | Mouse | Right Stick |
| **Menu Move** | Arrow Keys | D-Pad |
| **Action A: Activate** | E | Left Face Button |
| **Action B: Dash/Cancel** | Shift | Right Face Button |
| **Action C: Jump/Select** | Space | Bottom Face Button |
| **Action D: Special** | Mouse 0 | Top Face Button |
| **Action E: Pause** | Esc | Start/Menu |

### 🧪 Game Rules & Aesthetics
* **60-Second Loop:** The experiment must resolve to a **Pass/Fail** state within 60-120 seconds.
* **Visuals:** Use a strict "Testing Facility" style. Stick to simple geometric shapes and the provided **Lab White** and **Hazard Orange** materials. This ensures project size remains small and performance remains high.
* **Naming Conventions:** Follow industry-standard **PascalCase** for all assets (e.g., `BP_Experiment_CharacterName`, `M_Lab_Floor`).

---

## 🏗️ Core Architecture & Networking

The Lab uses a robust state-driven architecture to manage multiplayer sessions.

### Experiment States (`ControlLab_GameState_e`)
The `ControlLab_GameState_e` enum in the **GameState** controls the flow of the game:
*   `MainMenu`: Initial state for server discovery.
*   `Lobby`: Players wait for the host. The **Start** button is only visible to the **Host** and becomes active once 2 or more players have joined.
*   `Playing`: The active experiment loop. 
*   `GameOver`: Triggered when the timer hits zero or a player wins.

### Networking Essentials
*   **remainingTime (float):** Stored in the `GameState`. This uses **RepNotify** (`OnRep_RemainingTime`) to ensure every client's `WBP_HUD_TIMER` is synchronised with the server's authoritative clock.
*   **winnerID (int):** Defaulting to `-1` (no winner), this is updated on the Server and replicated to all clients to display the victory screen.
*   **Session Cleanup:** If the **Host** exits the session, a custom cleanup event triggers to return all connected clients back to the Main Menu automatically.

---

## 🛠️ Usage

### Creating a New Experiment (Map)
Level contributions must follow the folder and naming structure located in `Content/Experiments/`.

1. **Duplicate the Template:**
![Duplicate Template](media/UE_Duplicate.gif)
   Navigate to `Content/Experiments/Template_Game`. Create a new directory for your experiment. Group-select and drag the template assets onto your new folder and select **Copy Here**.

2. **Rename and Organise Assets:**
   Inside your new folder, rename assets using the experiment prefix (e.g., `MyMinigame`):
   * `Template_Game_Map` → `MyMinigame_Map`
   * `Template_Game_Data` → `MyMinigame_Data`
   * `template_game_thubnail` → `MyMinigame_Thumbnail`

   **Crucial Step:** To modify specific rules or characters, you must also copy and rename:
   * `BP_Template_Game_GameState` → `BP_MyMinigame_GameState`
   * `BP_Template_Game_PlayerController` → `BP_MyMinigame_PlayerController`
   * `BP_Template_Game_ThirdPersonCharacter` → `BP_MyMinigame_ThirdPersonCharacter`

3. **Configure the Experiment Data:**
   Open your duplicated `Data Asset` (`PDA_ExperimentDef`) and complete the **Details** panel:
   * **Experiment Name:** The display name shown in the browser.
   * **Student Author:** Your name or group ID.
   * **Level File:** Link your specific `_Map` asset.
   * **Thumbnail:** Link your `_Thumbnail` texture.
   * **Experiment ID:** Assign a unique integer (consult your instructor for the current range).

### Map World Settings
![WorldSettings](media/WorldSettings.png)
After duplicating the template map, open **World Settings** and ensure the **GameMode Override** is set to a GameMode class that uses your new character and state classes. 

---

## ❓ FAQ

### What is the default entry point?
The default starting map is `Content/Core/Maps/MainMenu`. Always begin from this scene to correctly initialise the network session manager.

### How do I host a session?
![Host Server](media/GFS_Host.PNG)
1. Select **Host** from the main menu.
2. Enter a unique **Server Name**.
3. Select your experiment from the list.
4. Click **Start** to initialise.

### Why can't I see any servers?
*   **Patience:** Broadcast discovery can take up to 20-30 seconds.
*   **Manual Join:** On restricted networks (like University Wi-Fi), use the **Manual Join** option with the host's local IP address.

### The game didn't reset after 60 seconds.
Ensure your experiment's logic sets the `EExperimentState` to `GameOver` when the `remainingTime` reaches zero on the Server.

---

## 🤝 Contributing

This project is an educational framework. If you find bugs in the core networking or lobby systems, please fork the repo and create a pull request.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

---

## 📜 License

Distributed under the MIT License. See `LICENSE.txt` for more information.

---

## 📞 Contact

**Josh Hall** – Griffith University – [joshua.hall@griffith.edu.au]

Project Link: [https://github.com/josh-hall-griffith/UE_Network_Lab](https://github.com/josh-hall-griffith/UE_Network_Lab)


---

## Attribution
This project utilises the following third-party resources:

* **[Advanced Sessions Plugin](https://vreue4.com/advanced-sessions-binaries)**: Created by **mordentral**. This plugin provides the extended blueprint functionality for session management, server searching, and networking metadata used in this template.