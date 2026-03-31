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
1. **Fork the repo:**
Best to Fork the repo first to your own repository, then clone to work on it locally.

3. **Rebuild the project:**
Before opening, right click on the UE_Network_Lab.uproject, and select "Generate Visual Studio Project Files". You should see new UE_Network_Lab.sln file appear.

3. **Rebuild the Project:**
    Double-click `UE_Network_Lab.uproject` to launch the Unreal Editor. You may be prompted to rebuild the project as the Advanced Session Plugin may require it. If you get an error during this stage, try to open the UE_Network_Lab.sln file in visal studio 2022, and rebuild the project using "Development Editor" build configuration.
The **Advanced Sessions Plugin** is included in the `Plugins/` directory and should initialise automatically.

4. **Open the Project:**
Once this is done, you should be able to either double click on the UE_Network_Lab.uproject or open it via the Epic Games Launcher.

---

## ✨ Usage & Documentation
You can find documentation on how The Control Lab is setup, and how you can extend it to create new multiplayer maps and experiences.  
Visit [The Control Lab Wiki](https://github.com/josh-hall-griffith/UE_Network_Lab/wiki)

---

## 🤝 Contributing

This project is an educational framework. If you find bugs in the core networking or lobby systems, please fork the repo and create a pull request.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request (PR)
6. The team will review your PR and accept or provide feedback before merging.

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
