1. # Introduction

This project implements an in-memory Smart Parking Allocation & Zone Management System for a city divided into zones. The system manages parking requests, allocates parking slots based on availability and zone preferences, enforces a strict request lifecycle, supports cancellation with rollback, and provides usage analytics.

The project is designed to strengthen understanding of core data structures such as arrays, linked lists, stacks, queues, and state machines while modeling a real-world urban resource allocation problem.

2  Zone and Slot Representation
2.1 City and Zones

The city is represented as an array of Zone objects.

Each Zone has:

A unique zoneId

A linked list of ParkingArea objects

A custom adjacency structure for neighboring zones (array-based, no STL graphs)

This design satisfies the requirement of zone-based city representation without routing graphs.

2.2 Parking Areas

Each Zone contains multiple ParkingArea objects.

Parking areas are stored using a singly linked list.

Each parking area manages its own slots.

This allows flexible expansion and efficient traversal without using STL containers.

2.3 **Parking Slots**

Each ParkingArea contains an array of ParkingSlot objects.

Each slot stores:

Slot ID

Zone ID

Availability status (free / occupied)

Slots are accessed using a first-available strategy, which keeps allocation logic simple and efficient.

3. **Vehicle and Parking Request Management**
3.1 Vehicle Representation

Each vehicle is represented by a Vehicle object.

Attributes:

Vehicle ID

Preferred zone

Vehicles do not directly interact with slots; all allocation is handled by the system controller.

3.2 Parking Requests

Parking requests are represented by ParkingRequest objects.

Each request contains:

Request ID

Vehicle ID

Requested zone

Request time

Current state

Requests are processed in FIFO order, conceptually using a queue.

4.  # Parking Request Lifecycle State Machine

A strict state machine is implemented using an enumeration.

Valid States:
REQUESTED
ALLOCATED
OCCUPIED
RELEASED
CANCELLED

Allowed Transitions:
REQUESTED → ALLOCATED
REQUESTED → CANCELLED
ALLOCATED → OCCUPIED
ALLOCATED → CANCELLED
OCCUPIED → RELEASED

Invalid Transitions:

Any transition not listed above is explicitly rejected.

This ensures system correctness and prevents inconsistent states.

5#   **Allocation Strategy**

The allocation logic is implemented in the AllocationEngine and follows these rules:

Same-zone preference

The requested zone is searched first.

First-available slot

Slots are checked sequentially.

Cross-zone allocation

If the requested zone is full, other zones are checked.

Cross-zone allocation incurs a penalty (tracked logically).

No STL maps or graphs are used in allocation logic, fulfilling implementation constraints.

6.  #  Cancellation and Rollback Design
6.1 Rollback Motivation

When a request is cancelled or rollback is triggered, the system must:

Restore slot availability

Restore request state

Maintain analytics consistency

6.2 Rollback Data Structure

Rollback is implemented using a stack (linked list).

Each rollback entry stores:

Pointer to allocated slot

Pointer to parking request

Previous request state

6.3 Rollback Operation

When rollback of the last k operations is requested:

Pop k entries from the stack

Release the associated slot

Restore the request’s previous state

This design supports undoing multiple allocations safely and efficiently.

7. # Analytics and History Tracking

The system maintains a complete history of parking requests to support analytics.

Supported Analytics:

Total number of requests

Cancelled vs completed requests

Zone utilization rate

Peak usage zones

Average parking duration

Analytics remain consistent even after cancellation and rollback operations.

8.  #  Testing Strategy

A minimum of 10 test cases were implemented in main.cpp, covering:

Same-zone allocation

Cross-zone allocation

Allocation failure when all zones are full

Valid lifecycle transitions

Invalid state transition detection

Cancellation from REQUESTED state

Cancellation from ALLOCATED state

Rollback of single allocation

Rollback of multiple allocations

System stability after rollback

These tests ensure correctness, robustness, and compliance with project requirements.

9. # Time and Space Complexity Analysis
Time Complexity
Operation	Complexity
Slot allocation	O(Z × A × S)
Request cancellation	O(1)
Rollback (k operations)	O(k)
Analytics queries	O(n)

Where:

Z = number of zones

A = parking areas per zone

S = slots per area

n = total number of requests

Space Complexity

Zones, parking areas, and slots use linear space

Rollback stack uses O(k) space

Request history uses O(n) space

Overall space complexity is O(n + ZAS).

10. # Conclusion

This project demonstrates a complete and modular implementation of a smart parking management system using fundamental data structures. By enforcing strict state transitions, supporting rollback, and providing analytics, the system models real-world constraints while adhering to academic and implementation requirements.
