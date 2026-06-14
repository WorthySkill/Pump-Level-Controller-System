# Automated Pump Level Controller - Digital System Interfacing Specification

A comprehensive hardware-software engineering specification and logic layout for an industrial Automated Pump Level Controller. This project showcases proficiency in low-level digital system interfacing, discrete logic state-machine formulation, asynchronous sensor input filtering, physical hardware debouncing, and fail-safe system automation loops.

## ⚙️ System Architecture & Logic Parameters
The system monitors water reservoirs across discrete thresholds to regulate automated pump actions, preventing resource depletion and structural overflow events:
* **FSM Control Logic (Finite State Machine):** Implements a robust state-machine loop that continuously samples high/low sensor boundaries to transition safely between idle modes and full operational draw states.
* **Asynchronous Signal Filtering:** Integrates low-pass hardware filters and algorithmic debouncing frameworks to clean raw toggle signals from fluid sensors, completely eliminating voltage spikes and false trigger loops.
* **Fail-Safe Operational Matrix:** Engineered with hardware overrides to halt pump operations instantly if terminal sensors detect out-of-bounds metrics (e.g., dry-running conditions or sensor open-circuit faults).
* **Multi-Stage Driver Interfacing:** Pairs low-voltage controller outputs with isolated high-current electrical switches (relays/opto-isolators) to manage heavy motor inductive loads safely without system reset interference.

## 🛠️ Tech Stack & Design Tools
* **Design Paradigm:** Finite State Machine (FSM) Logic / Digital Subsystem Interfacing
* **Hardware Interfacing Principles:** Signal Conditioning, Electrical Isolation, Switching Relays, Hardware Debouncing
* **Simulation & Circuit Schematics:** Proteus Design Suite / MultiSIM / Logic Circuit CAD
* **Core Documentation:** Comprehensive Hardware Verification & Pinout Logic Maps

## 📁 Repository Structure
* `Hardware-Schematics/` - Dedicated directory storing logic state-machine maps, wiring blueprints, and component interface layouts.
* `README.md` - Complete, production-ready system specification and structural operational design documentation.

## 🔧 Operational Logic Verification
The system's decision-making loop processes active inputs using a definitive logic state matrix:

| Current State | Sensor High | Sensor Low | Target Pump Output | Next State Action |
| :--- | :--- | :--- | :--- | :--- |
| **TANK_EMPTY** | 0 (Low) | 0 (Low) | **ON** (Initiate Filling) | TANK_FILLING |
| **TANK_FILLING**| 0 (Low) | 1 (High)| **ON** (Continue Run) | TANK_FILLING |
| **TANK_FULL** | 1 (High)| 1 (High)| **OFF** (Halt Filling) | TANK_IDLE |
| **TANK_DRAIN** | 0 (Low) | 1 (High)| **OFF** (Maintain Idle)| TANK_DRAIN |
