# Contributing to The Control Lab

Welcome! We are excited that you want to contribute to The Control Lab. This project is an experimental testbed for multiplayer gameplay engineering. Whether you are fixing a bug in the core networking or adding a new minigame experiment, your contributions help build this ecosystem.

## How to Contribute

### Reporting Bugs
If you find an issue with the core networking, lobby, or session systems:
1. Search the [Issues](https://github.com/josh-hall-griffith/UE_Network_Lab/issues) tab to see if it has already been reported.
2. If not, open a new issue.
3. Provide a clear title and description. Include steps to reproduce the bug and, if possible, screenshots or snippets of the Blueprint logic involved.

### Developing New Experiments
If you are adding a new experiment (minigame):
1. **Fork the repo** to your own GitHub account.
2. **Create a feature branch:** `git checkout -b feature/MyMinigameName`.
3. **Follow Technical Standards:**
   - Use the `Template_Game` as your base.
   - Adhere to the `Input Schema` to ensure compatibility.
   - Maintain the "Testing Facility" aesthetic (Lab White/Hazard Orange materials).
   - Ensure your map uses a unique `Experiment ID`.
4. **Test your code:** Ensure your game state correctly handles the 60-second "Pass/Fail" loop and that the `remainingTime` replicates to all clients.

### Submitting Pull Requests
1. Ensure your code follows the established project naming conventions (PascalCase).
2. Clean up your folder structure before committing.
3. Push your branch to your forked repository.
4. Open a Pull Request (PR) against the `main` branch of this repository.
5. In your PR description, explain what your experiment does and confirm it meets the technical standards outlined in the README.

## Technical Expectations

* **Networking:** All variables that affect game state (e.g., player scores, timers, winners) must be replicated. Please avoid "Client-Side Authority" patterns.
* **Performance:** Keep asset counts low. The focus is on gameplay mechanics, not high-fidelity graphics.
* **Compatibility:** Ensure your minigame functions correctly when triggered by the `MainMenu` and `GameLobby` systems.

## Code of Conduct

This is an educational environment. We expect all contributors to be respectful and constructive in their feedback during code reviews and discussions. 

## Contact
If you have questions about the architecture or need clarification on the networking standards, please reach out to **Josh Hall** at [joshua.hall@griffith.edu.au].
