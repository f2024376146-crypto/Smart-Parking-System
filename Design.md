**Smart Parking System - Design Documentation**
1. Project Overview

This project is a Modular Parking Management System designed to handle real-time parking requests, slot allocations across multiple zones, and state transitions for vehicles. It utilizes a Linked List of areas within each zone and a State Machine to track request progress.

2. System Architecture

The system is divided into several interconnected modules to ensure scalability and clarity:

Zone & Area Management: Each Zone contains a Linked List of AreaNode objects, where each node points to a ParkingArea containing 5 slots.

Allocation Engine: A static utility that finds the first available slot in a specified zone by traversing the Linked List.

State Machine: Tracks requests through five states: REQUESTED, ALLOCATED, OCCUPIED, RELEASED, and CANCELLED.

Rollback Manager: Uses a stack-based history to undo recent operations, ensuring data integrity.

3. Data Structures & Complexity

ComponentImplementationTime ComplexityZone StorageLinked List of Areas O(N) where N is number of areas.Slot SearchLinear Search within Areas O(S) where S is total slots in a zone.Undo/RollbackStack (Array-based)O(1) per operation.Request HistoryStatic Array (Size 20)O(1) for lookup.

4. Core Logic Implementation

The project strictly follows the logic defined in the source files:

ParkingSystem.cpp: Manages the main flow, including the automated test suite and user interaction.

Vehicle.cpp: Stores basic vehicle data and preferred zones.

ParkingSlot.cpp: Manages individual slot availability and ID mapping (e.g., Zone 1 slots start at ID 10).

5. Verification: 10 Automated Test Cases

The system includes a suite of 10 automated tests (accessible via Menu Option 6) to verify all rules:

Standard Allocation: Successfully parks a vehicle in Zone 0 (Slot 0).

Boundary Allocation: Parks a vehicle in Zone 2 (Slot 20).

Invalid Zone Check: Rejects allocation for Zone IDs outside the 0-2 range.

Sequential Search: Confirms that slots are filled in order within the Linked List.

Standard Release: Marks a slot as available and clears the state.

State Protection: Prevents double-releasing an already free slot.

Rollback Logic: Reverts the last operation and restores previous data.

Invalid Index Handling: Prevents errors when releasing a non-existent request index.

Analytics Integrity: Displays correct counts for total transactions.

Capacity Overflow: Confirms "No slots available" once all 5 slots in an area are full.

