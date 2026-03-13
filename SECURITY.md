# Security Policy

## Supported Versions

The project is currently in early pre-release (Alpha). Security updates are focused on the latest development branch.

| Version | Supported |
| --- | --- |
| 0.0.2 | ✅ |
| < 0.0.2 | ❌ |

> [!IMPORTANT]
> **Experimental Status:** As this project is in version 0.0.2, the networking architecture is an early-stage testbed. Users should only host sessions on trusted networks (such as university labs or via secure VPNs) and avoid using this framework for production-ready commercial titles without a thorough independent security audit.

## Reporting a Vulnerability

We value the community's help in securing this educational framework. If you discover a vulnerability, please follow the steps below.

### How to Report
Please do not open a public GitHub issue for security vulnerabilities. Instead, email **joshua.hall@griffith.edu.au** with the subject line `[SECURITY VULNERABILITY] - UE_Network_Lab`. 

**Please include the following details:**
* A description of the vulnerability.
* Steps to reproduce the issue (or a blueprint screenshot of the exploit).
* Potential impact (e.g., Client-to-Server privilege escalation, session crashing).

### What to Expect
* **Acknowledgement:** You will receive a response within 72 hours.
* **Updates:** We will provide status updates as we investigate the replication logic or session handling involved.
* **Disclosure:** Once a patch is merged into the main branch, we will credit the researcher in the `CHANGELOG.md` (unless you wish to remain anonymous).

## Security Scope

In this pre-release phase, we are specifically looking for:
* **RPC Exploits:** Validation errors in `Server` or `Multicast` functions that allow clients to manipulate the `remainingTime` or `winnerID` outside of the authoritative game logic.
* **Session Privacy:** Issues where `Manual Join` via IP address exposes more host information than intended.
* **Asset Injection:** Ways to force the loading of unauthorized assets through the `PDA_ExperimentDef` data structures.
