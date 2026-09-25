# Logic Complete
##### Logic Complete provides the hardware. The machine designer provides the behavior.
> A small CPU simulator written in C11, built from the bottom up as a hardware-design and C-learning project.

<!-- TEST_STATUS_START -->
| 🧪 Tests | ❌ Failures | ⚪ Ignored | ⚠️ Warnings | 🧠 Memory Errors |
|---:|---:|---:|---:|---:|
| **146** | **0** | **0** | **0** | **0** |
<!-- TEST_STATUS_END -->

<!-- MEMORY_STATUS_START -->
| 📦 Allocs | 🗑️ Frees | 💾 Bytes Allocated | 💧 Leaked Bytes | 🧱 Leaked Blocks |
|---:|---:|---:|---:|---:|
| **19** | **19** | **4205** | **0** | **0** |
<!-- MEMORY_STATUS_END -->

## About

Logic Complete is an experimental CPU simulator being built from the ground up in C.

The goal isn't simply to emulate a CPU. The project intentionally models the hardware as a collection of increasingly complex components, with each layer built from and tested against the layers beneath it.

The project is also being used as a way to learn C more deeply by implementing increasingly realistic computer hardware abstractions.

## Architecture

The project is being built in layers:

```text
Logic Gates
    ↓
Basic Components
    ↓
Bit-Width Components
    ↓
Datapath
    ↓
Memory
    ↓
Control
    ↓
CPU
```

## Current Components

* Logic gates
* 8-bit logic operations
* Multiplexer
* Decoder
* Half adder
* Full adder
* 8-bit ripple-carry adder
* 8-bit subtractor
* Comparator
* Shifters
* Registers
* ALU
* ALU flags
* Register file

## Testing

Every hardware component is developed with unit tests using Unity.

Tests are automatically discovered, so adding a new test file does not require maintaining a central test registry.

```bash
make test
```

The Git pre-commit hook automatically runs the complete test suite before allowing a commit.

## Development Philosophy

The project favors explicit hardware-like abstractions over hiding behavior behind high-level C operations.

Where practical, components are constructed from previously implemented components.

For example:

```text
Full Adder
    ↓
8-bit Adder
    ↓
ALU
```

and:

```text
Logic Gates
    ↓
Decoder
    ↓
Register File
```

The intent is that every abstraction remains inspectable: if something is unclear, its implementation can be followed down to the underlying hardware-like operations.

## Project Structure

```text
include/    Header files
src/        Hardware implementations
tests/      Unit tests
build/      Build artifacts
```

## Status

This is an active experimental project. The architecture will evolve as new hardware components are implemented and tested.
